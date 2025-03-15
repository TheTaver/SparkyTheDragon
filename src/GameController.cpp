#include "GameController.h"
#include "RoomDisplay.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <ctime>

void GameController::SaveGame(NPC* enemy, Player*& thePlayer, std::string position) {
    std::ofstream file(position);
    if (file.is_open()) {
        thePlayer->GetName();
        enemy->GetName();
        file.close();
    } else {
        std::cout << "File cannot open for saving" << std::endl;
    }
}

Room GameController::LoadRoom(std::string position) {
    Room room(position);
    return room;
}



void GameController::EnterRoom(Player* thePlayer, Room currentRoom) {
    RoomDisplay display;
    MenuDisplay menu;
    int currentHp = thePlayer->GetStat(0);
    bool quitButtonClicked = false;
    int roomsCleared = 0;  
    
    srand(time(0));

    while (true) {
      
        std::string playerChoice = display.DisplayRoom(currentRoom, *thePlayer, currentHp);

        if (playerChoice == "Health Pot") {
            std::cout << "Used Health Potion!\n";
            continue;  // Stay in the same room and then fight an enemy
        } else if (playerChoice == "Quit game") {
            std::cout << "Exiting game...\n";
            exit(0);
        } else {// ✅ Transition to a new room
            std::vector<std::string> options = currentRoom.GetOptions();
            for (size_t i = 0; i < options.size(); ++i) {
                if (playerChoice == options[i]) {
                    std::cout << "Moving to: " << currentRoom.GetNextRoom(i) << "...\n";
                    currentRoom = Room(currentRoom.GetNextRoom(i));
                    roomsCleared++;  
                    break;
                }
            }
        }

        
        NPC* enemy = nullptr;

      
        if (roomsCleared >= 5) {
            enemy = new Sparky();
            std::cout << "⚡ FINAL BOSS: Sparky appears! ⚡\n";
        } else {
            // ✅ Properly randomize different enemy types
            int enemyType = rand() % 5;  // Random value between 0 and 4
            switch (enemyType) {
                case 0: enemy = new CyberRat(); break;
                case 1: enemy = new SecurityGaurdA(); break;
                case 2: enemy = new SecurityGaurdB(); break;
                case 3: enemy = new RoboNinja(); break;
                //case 4: enemy = new RoboBro(); break;
            }
            std::cout << "An enemy appears: " << typeid(*enemy).name() << "!\n";
        }

        quitButtonClicked = DoCombat(enemy, thePlayer);
        delete enemy;

        if (thePlayer->IsDead()) {
            delete thePlayer;
            menu.DisplayGameOver();
            return;
        }

        // ✅ 3. If Sparky was just defeated, end the game
        if (roomsCleared >= 5) {
            std::cout << "🎉 You defeated Sparky! The game is complete! 🎉\n";
            delete thePlayer;
            menu.DisplayVictory();
            return;
        }
    }
}


Player* GameController::MakeCharacter(std::string theInput) {
    MenuDisplay menu;
    std::string playerName = "";
    std::cout << "What is your character's name?" << std::endl;
    std::cin >> playerName;

    if (theInput == "Brawler") {
        std::vector<int> brawlerStats = {20, 2, 1, 4};
        return new Brawler(playerName, "Brawler", 1, brawlerStats);
    } else if (theInput == "Shooter") {
        std::vector<int> shooterStats = {20, 4, 2, 1};
        return new Shooter(playerName, "Shooter", 1, shooterStats);
    } else if (theInput == "Duelist") {
        std::vector<int> duelistStats = {20, 2, 4, 1};
        return new Duelist(playerName, "Duelist", 1, duelistStats);
    } else {
        throw std::runtime_error("Invalid class selection.");
    }
}

std::string GameController::StartGameLoop() {
    MenuDisplay menu;
    std::string playerName = "";
    std::string position = "test_room.txt";
    std::string theInput = menu.Displaystart();

    if (theInput == "Start") {
        theInput = menu.DisplayClassSelection();
        Player* thePlayer = MakeCharacter(theInput);

        Room currentRoom(position);
        EnterRoom(thePlayer, currentRoom);

        delete thePlayer;
    }

    return "Quit";
}

bool GameController::DoCombat(NPC* enemy, Player* thePlayer) {
    CombatController combat(thePlayer, enemy);
    combat.StartCombat();

    if (!thePlayer->IsDead() && !enemy->IsDead()) {
        return true;
    }

    if (!thePlayer->IsDead()) {
        std::vector<int> enemyLoot = enemy->GetLoot();
        for (int item : enemyLoot) {
            thePlayer->addItem(item);
        }
        thePlayer->addExp(enemy->GetExpReward());
    }

    return false;
}
