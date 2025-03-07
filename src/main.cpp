#include "MenuDisplay.cpp"




int main() {
    Element textBox = hbox({
        text(L"Hello, World!") | border | bold
    });

    Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
    Render(display, textBox);
    cout << display.ToString() << endl;


    MenuDisplay menu;
    string theInput = menu.Displaystart();

    if(theInput == "Quit"){
        //see if victory screen is okay
        theInput = menu.DisplayVictory();
        if(theInput == "Again"){
            theInput = "Start";
        }
    }
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

    return 0;
}