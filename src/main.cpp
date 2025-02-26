#include "MenuDisplay.h"
#include "CombatDisplay.h"

#include <vector>


using namespace std;

int main() {
    vector<int> items = {2, 3, 4, 5};
    vector<int> maxItems = {10, 10, 10, 10};
    vector<int> stats = {15, 7, 3, 4};
    int currHealth = 11;
    
    ftxui::Element sidebar = getScreenSideBar(currHealth, stats, items, maxItems);
    Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(sidebar));
    Render(display, sidebar);
    cout << display.ToString() << endl;

    return 0;
}