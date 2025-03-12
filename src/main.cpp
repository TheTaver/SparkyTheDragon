#include "MenuDisplay.cpp"
#include "../header/RoomDisplay.h"
#include "../header/Room.h"
#include "../header/Character.h"
#include <iostream>
#include <vector>



int main() {
    Element textBox = hbox({
        text(L"Hello, World!") | border | bold
    });

    Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
    Render(display, textBox);
    cout << display.ToString() << endl;


    MenuDisplay menu;
    string theInput = menu.Displaystart();

    if(theInput == "Start"){
        theInput = menu.DisplayClassSelection();
        if(theInput == "Brawler"){
            cout << "YUHHHHH" << endl;
        }
        else if (theInput == "Shooter"){
            cout << "bruh" << endl;
        }
        //smth with like player can input their char name when any button click
    }
    else if(theInput == "Continue"){
        //just to see if gameover screen is fine
        theInput = menu.DisplayGameOver();
        if(theInput == "Quitcuzdead"){
            cout << "dead fr" << endl;
        }
    }

    std::cout << "Creating Room Object...\n";
    
    // Create test room
    Room testRoom("room1.txt");  // Ensure this file exists and is formatted correctly

    std::cout << "Creating Character Object...\n";

    // Create test player
    std::vector<int> stats = {100, 10, 10, 10};
    Character testPlayer("Hero", 1, stats);

    std::cout << "Creating RoomDisplay Object...\n";

    // Create RoomDisplay
    RoomDisplay roomDisplay;
    
    std::cout << "Calling DisplayRoom...\n";

    // Display room
    std::string playerChoice = roomDisplay.DisplayRoom(testRoom, testPlayer);

    std::cout << "Player selected: " << playerChoice << std::endl;
   

    return 0;
}