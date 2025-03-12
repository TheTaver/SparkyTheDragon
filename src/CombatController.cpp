#include "CombatController.h"
#include "CombatUI.h"
#include <string>

using std::cout;
using std::endl;

CombatController::CombatController(Player* playerChar, const string& enemyFile) :
player(playerChar), npcFilename(enemyFile)
{
    // enemy created with new
    enemy = NPCReader::GetEnemy(npcFilename);
    combatLog.add("You encountered a "+enemy->GetName()+"!");
}

CombatController::~CombatController() {
    delete enemy;
}

void CombatController::StartCombat(int randSeed) {
    bool endCombat = false;
    srand(randSeed);
    while(not endCombat and not player->IsDead() and not enemy->IsDead()) {
        endCombat = DoRound(rand());
    }
    // Todo: Fix?
    if(player->IsDead()) {
        cout << "rip lmao" << endl;
    } else if(enemy->IsDead()) {
        cout << "gj!" << endl;
    } else {
        cout << "k bye" << endl;
    }
}

void CombatController::UseMove(Character* attacker, Attack& move, Character* opponent, const int roundSeed) {
    Character* target;
    if(move.targetSelf) {
        target = attacker;
    } else {
        target = opponent;
    }
    string hitMsg = attacker->GetName() + " used " + move.name + " on "+target->GetName()+"!";
    combatLog.add(hitMsg);
    
    const vector<int> prevStats = target->GetTempStats();
    if(not move.hit(*attacker, *target, roundSeed)) {
        combatLog.add("But it missed!");
        return;
    }
    // If a stat changed, print out what stat and change
    int statChanged = -1;
    const vector<int> currStats = target->GetTempStats();
    for(int i = 0; i < prevStats.size(); i++) {
        if(currStats.at(i) != prevStats.at(i)) {
            statChanged = i;
            break;
        }
    }
    
    if(statChanged != -1) {
        vector<string> statNames = {"Health", "Strength", "Agility", "Defense"};
        string statChangeMessage = target->GetName()+"'s "+statNames.at(statChanged)+" ";
        if(prevStats.at(statChanged) > currStats.at(statChanged)) {
            statChangeMessage+= "increased";
        } else {
            statChangeMessage+= "decreased";
        }
        combatLog.add(statChangeMessage);
    }
}

bool CombatController::DoRound(int rand) {
    int roundSeed = rand;
    string input = GetValidAction();
    
    vector<Attack> moves = player->GetMoves();
    
    // Player's action
    if(input.find("Move") != string::npos) {
        int moveNum = input.back() - '0';
        UseMove(player, moves.at(moveNum), enemy, roundSeed);

    } else if(input.find("Item") != string::npos) {
        int itemNum = input.back() - '0';
        player->useItem(itemNum);
        string itemStr = player->GetName()+" used ";
        if(itemNum == 0) {
            itemStr+= "MedKit";
        } else if(itemNum == 1) {
            itemStr+= "StrBuff";
        } else if(itemNum == 2) {
            itemStr+= "AgiBuff";
        } else if(itemNum == 3) {
            itemStr+= "DefBuff";
        } else {
            itemStr+= "????";
        }
        combatLog.add(itemStr);
    } else if(input == "Quit Game") {
        return true;
    }
    
    if(player->IsDead() or enemy->IsDead()) {
        return true;
    }
    
    // Enemy's Action
    Attack enemyAttack = enemy->GetAttack(roundSeed);
    UseMove(enemy, enemyAttack, player, roundSeed);
    

    return (input == "Quit Game" or player->IsDead() or enemy->IsDead());
}

string CombatController::GetPlayerInput() const {
    string playerInput = "";
    string returnString = "";
    CombatUI display(player, enemy, &playerInput);

    display.ShowCombatScreenUntilInput(combatLog.getLog());

    vector<Attack> moves = player->GetMoves();
    for(int i = 0; i < moves.size(); i++) {
        if(playerInput == moves.at(i).name) {
            return "Move "+std::to_string(i);
        }
    }
    if(playerInput == "Medkits") return "Item 0";
    if(playerInput == "StrBuff") return "Item 1";
    if(playerInput == "AgiBuff") return "Item 2";
    if(playerInput == "DefBuff") return "Item 3";

    if(playerInput == "None" or playerInput == "Quit Game") {
        return playerInput;
    }


    return "bro what? "+playerInput;
}

string CombatController::GetValidAction() {
    // Make sure the player has move uses/items that they want to use
    while(true) {
        string input = GetPlayerInput();
        if(input.find("Move") != string::npos)
        {
            // Player selected a move
            int moveNum = input.back() - '0';
            if(player->GetMoves().at(moveNum).numUses > 0) {
                return input;
            } else {
                combatLog.add(player->GetMoves().at(moveNum).name + " is out of uses.");
                continue;
            }
        }
        else if(input == "None")
        {
            combatLog.add("Please select a move or item to use.");
            continue;
        }
        else if(input.find("Item") != string::npos)
        {
            int itemNum = input.back() - '0';
            if(player->itemCount(itemNum) > 0) {
                return input;
            } else {
                string itemName = "Unknown Item";
                switch(itemNum) {
                    case 0:
                        itemName = "Medkit";
                        break;
                    case 1:
                        itemName = "StrBuff";
                        break;
                    case 2:
                        itemName = "AgiBuff";
                        break;
                    case 3:
                        itemName = "DefBuff";
                        break;
                }
                combatLog.add("No "+itemName+" items remaining.");
                continue;
            }
        }
        else if(input == "Quit Game")
        {
            return input;
        }
        else
        {
            throw std::runtime_error("Unknown input option: "+input);
        }
    }
}