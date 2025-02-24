#include "MenuDisplay.h"




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

    return 0;
}