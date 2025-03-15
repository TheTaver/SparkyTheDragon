#include "MenuDisplay.h"
 #include "CombatInfoDisplay.h"
 #include "CombatUI.h"
 #include "Duelist.h"
 #include "brawler.h"
 #include "Shooter.h"
 #include "CyberRat.h"
 #include "GameController.h"
 #include "Room.h"
 #include <ftxui/component/screen_interactive.hpp>
 #include <vector>
 #include <fstream>


using namespace std;

int main() {
    using namespace ftxui;
    string gameInput;
    GameController game;
    while (gameInput != "Quit" && gameInput != "Returncd" && gameInput != "Quitcuzdead"){
        gameInput = game.StartGameLoop();
    }
    
    return 0;
}