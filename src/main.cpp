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
    // Element textBox = hbox({
    //     text(L"Hello, World!") | border | bold
    // });

    // Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
    // Render(display, textBox);
    // cout << display.ToString() << endl;


    // MenuDisplay menu;
    // string theInput = menu.Displaystart();

    // if(theInput == "Quit"){
    //     //see if victory screen is okay
    //     theInput = menu.DisplayVictory();
    //     if(theInput == "Again"){
    //         theInput = "Start";
    //     }
    // }
    // if(theInput == "Start"){
    //     theInput = menu.DisplayClassSelection();
    //     if(theInput == "Brawler"){
    //         cout << "YUHHHHH" << endl;
    //     }
    //     else if (theInput == "Shooter"){
    //         cout << "bruh" << endl;
    //     }
    //     //smth with like player can input their char name when any button click
    // }
    // else if(theInput == "Continue"){
    //     //just to see if gameover screen is fine
    //     theInput = menu.DisplayGameOver();
    //     if(theInput == "Quitcuzdead"){
    //         cout << "dead fr" << endl;
    //     }
    // }


    GameController game;
    game.StartGameLoop();
    //show the menus
    //load the room
    //room has combat then enter combat
    //dadadadadada
    
    return 0;
}