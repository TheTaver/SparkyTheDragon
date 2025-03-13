#include "GameController.h"


void GameController::SaveGame(NPC* enemy, Player*& thePlayer, string filename){
    ofstream file(filename);
    //everytime a file opens it saves ig
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

Room GameController::LoadRoom(NPC* enemy, Player*& thePlayer,string position,string filename){
    ifstream file(filename);
    if(file.is_open()){
        Room room(position);
        return room;
    }
    else{
        cout << "didnt open save file" << endl;
        return Room("default_position");
    }
};

void GameController::EnterRoom(Player* thePlayer, Room room){
    cout << room.GetDescription() << endl;
    cout << room.GetChoice() << endl;

    vector<string> options = room.GetOptions();
    for (int i = 0; i < room.GetNumOptions(); i++){
        cout << options[i] << endl;
    }

    int playerChoice;
    cout << "Option chosen: " << room.GetNumOptions() << endl;
    cin >> playerChoice;

    //if choice is correct
    if (playerChoice >= 1 && playerChoice <= room.GetNumOptions()) {
        cout << "You chose: " << options[playerChoice - 1] << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
};

void GameController::StartGameLoop(NPC* enemy, Player*& thePlayer){
    MenuDisplay menu;
    string playerName = "";
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
        Room currentRoom("txt/test_room.txt");
        Room prevRoom("txt/test_room.txt");
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
    }
}