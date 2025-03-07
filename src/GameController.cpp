#include "MenuDisplay.h"
#include "CombatInfoDisplay.h"
#include "CombatUI.h"

#include <ftxui/component/screen_interactive.hpp>
#include <vector>


using namespace std;

//not working in cmake yet lol
int main() {
    MenuDisplay menu;
    //CombatInfoDisplay 
    //CombatUI 
    string playerName = "";
    string theInput = menu.Displaystart();

    if(theInput == "Start"){
        theInput = menu.DisplayClassSelection();
        if(theInput == "Brawler" || theInput == "Shooter" || theInput == "Duelest"){
            cout << "Name your character" << endl;
            cin >> playerName;

            //then start first room
            //but lets

        }
    }
    else if(theInput == "Continue"){
        //load from last checkpoint
    }

    return 0;
}