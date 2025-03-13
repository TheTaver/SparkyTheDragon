#include "GameController.h"


void GameController::SaveGame(NPC* enemy, Player*& thePlayer, string position){
    ofstream file(position);
    //everytime a file opens it saves ig, probs will change
    if(file.is_open()){
        //uhhhhhh
        thePlayer->GetName();
        enemy->GetName();
        file.close();
    }
    else {
        cout << "File cannot open for saving" << endl;
    }
};

Room GameController::LoadRoom(string position){
    Room room(position);
    return room;
};

void GameController::EnterRoom(Player* thePlayer, Room room){
    //layout will be changed probs 
    cout << room.GetDescription() << endl;
    cout << room.GetChoice() << endl;

    vector<string> options = room.GetOptions();
    for (int i = 0; i < room.GetNumOptions(); i++){
        cout << options[i] << endl;
    }

    //to show the room text
    int playerChoice;
    cout << "Option chosen: " << room.GetNumOptions() << endl;
    cin >> playerChoice; //this kinda does nothing lol
};

void GameController::StartGameLoop(NPC* enemy, Player*& thePlayer){
    MenuDisplay menu;
    string playerName = "";
    string position = "";
    string theInput = menu.Displaystart();

    if(theInput == "Start"){
        cout << "What is your characters name?" << endl;
        cin >> playerName;
        theInput = menu.DisplayClassSelection();
        if(theInput == "Brawler"){
            //not yet
        } 
        else if (theInput == "Shooter"){
            //not yet
        } 
        else if (theInput == "Duelist"){
            //health, power, agility, def
            vector<int> duelistStats = {20, 2, 4, 1};
            thePlayer = new Duelist(playerName, 1, duelistStats);
        }

        //mane idk
        position = "txt/test_room.txt";
        Room currentRoom(position);
        Room prevRoom(position);
        EnterRoom(thePlayer, currentRoom);

        //then start first room
        //games saves after a battle is done i assume
        //but first lets just get the cui logic in here
        while(thePlayer->IsDead() != true && enemy->IsDead() != true){
            CombatInfoDisplay CombatInfoDisplay(thePlayer, enemy);
            CombatUI CombatUI(thePlayer, enemy, &theInput);
            vector<wstring> combatLog;
            CombatUI.ShowCombatScreenUntilInput(combatLog);
        }
        
        if (thePlayer->IsDead()){
            theInput = menu.DisplayGameOver();
            if (theInput == "Returncd"){
                theInput = "Continue";
            }
        }
        else{
            
            //to the next fight/room ig
        }
    }
    if(theInput == "Continue"){
        //load from last checkpoint
        if (playerName != ""){
            LoadRoom(position);
        }
    }
}