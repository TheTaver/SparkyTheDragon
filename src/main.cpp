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
        cout << "YOOOO" << endl;
    }
    return 0;
}