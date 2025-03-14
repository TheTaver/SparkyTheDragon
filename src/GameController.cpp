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

Player* GameController::MakeCharacter(string theInput){
    MenuDisplay menu;
    string playerName = "";
    cout << "What is your characters name?" << endl;
    cin >> playerName;

    if(theInput == "Brawler"){
        vector<int> brawlerStats = {20, 2, 1, 4};
        return new Brawler(playerName, "Brawler", 1, brawlerStats);
    } 
    else if (theInput == "Shooter"){
        vector<int> shooterStats = {20, 4, 2, 1};
        return new Shooter(playerName, "Shooter", 1, shooterStats);
    } 
    else if (theInput == "Duelist"){
        vector<int> duelistStats = {20, 2, 4, 1};
        return new Duelist(playerName, "Duelist", 1, duelistStats);
    }
    else {
        throw std::runtime_error("akjdbnf");
    }
}

string GameController::StartGameLoop() {
    MenuDisplay menu;
    string playerName = "";
    string position = "";
    string theInput = menu.Displaystart();

    if(theInput == "Start"){
        theInput = menu.DisplayClassSelection();
        Player* thePlayer = MakeCharacter(theInput);

        //mane idk
        position = "test_room.txt";
        Room currentRoom(position);
        Room prevRoom(position);
        EnterRoom(thePlayer, currentRoom);

        bool quitButtonClicked = false;
        //then start first room
        //games saves after a battle is done i assume
        //but first lets just get the cui logic in here
        NPC* enemy1 = new CyberRat();
        quitButtonClicked = DoCombat(enemy1, thePlayer);
        delete enemy1;
            
        NPC* enemy2 = new SecurityGaurdA();
        quitButtonClicked = DoCombat(enemy2, thePlayer);
        delete enemy2;

        NPC* enemy3 = new SecurityGaurdB();
        quitButtonClicked = DoCombat(enemy3, thePlayer);
        delete enemy3;
    
        NPC* enemy4 = new RoboNinja();
        quitButtonClicked = DoCombat(enemy4, thePlayer);
        delete enemy4;

        NPC* enemy5 = new Sparky();
        quitButtonClicked = DoCombat(enemy5, thePlayer);
        delete enemy5;
        

        if(thePlayer->IsDead()) {
            return theInput = menu.DisplayGameOver();
        }
        if (enemy5->IsDead()){
            return theInput = menu.DisplayVictory();
        }
    }
    if(theInput == "Continue"){
        //load from last checkpoint
        if (playerName != ""){
            LoadRoom(position);
        }
    }
    return "Quit";
}

bool GameController::DoCombat(NPC* enemy, Player* thePlayer){
    CombatController combat(thePlayer, enemy);
    combat.StartCombat();
    if (thePlayer->IsDead() != true && enemy->IsDead() != true){
        return true; // clicked quit button
    }
    if(!thePlayer->IsDead()) {
        vector<int> eneLoot = enemy->GetLoot();
        for(int i =0; i < eneLoot.size(); i++){
            thePlayer->addItem(eneLoot[i]);
        }
        thePlayer->addExp(enemy->GetExpReward());
    }
    return false;
}