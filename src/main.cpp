#include "MenuDisplay.h"
#include "CombatInfoDisplay.h"
#include "CombatUI.h"
#include "Duelist.h"
#include "CyberRat.h"
#include <ftxui/component/screen_interactive.hpp>
#include <vector>


using namespace std;

// int main() {
//     using namespace ftxui;
//     Element textBox = hbox({
//         text(L"Hello, World!") | border | bold
//     });

//     Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
//     Render(display, textBox);
//     cout << display.ToString() << endl;


//     MenuDisplay menu;
//     string theInput = menu.Displaystart();

//     if(theInput == "Quit"){
//         //see if victory screen is okay
//         theInput = menu.DisplayVictory();
//         if(theInput == "Again"){
//             theInput = "Start";
//         }
//     }
//     if(theInput == "Start"){
//         theInput = menu.DisplayClassSelection();
//         if(theInput == "Brawler"){
//             cout << "YUHHHHH" << endl;
//         }
//         else if (theInput == "Shooter"){
//             cout << "bruh" << endl;
//         }
//         //smth with like player can input their char name when any button click
//     }
//     else if(theInput == "Continue"){
//         //just to see if gameover screen is fine
//         theInput = menu.DisplayGameOver();
//         if(theInput == "Quitcuzdead"){
//             cout << "dead fr" << endl;
//         }
//     }

//     return 0;
// }

//actual gameloop
int main() {
    NPC* enemy = new CyberRat();
    Player* thePlayer = nullptr;
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
            vector<int> duelistStats = {15, 4, 2, 8};
            thePlayer = new Duelist(playerName, 1, duelistStats);
        }
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

    //clean up memory when the player finishes the game or starts a new one without finishing maybe
    delete thePlayer;
    delete enemy;

    return 0;
}