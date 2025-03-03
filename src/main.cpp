// #include "MenuDisplay.h"
#include "CombatDisplay.h"
#include "Character.h"

# include <ftxui/component/screen_interactive.hpp>
#include <vector>


using namespace std;

vector<wstring> combatlog() {
    wstring ratTurn1 = L"CyberRat used Metallic Bite.";
    wstring ratTurn2 = L"But it missed!";
    wstring playerTurn1 = L"Shooter used Gun.";
    wstring playerTurn2 = L"CyberRat was defeated!";
    vector<wstring> combatLog;
    combatLog.push_back(ratTurn1);
    combatLog.push_back(ratTurn2);
    combatLog.push_back(playerTurn1);
    combatLog.push_back(playerTurn2);
    return combatLog;
}

int main() {
    vector<int> items = {2, 3, 4, 5};
    vector<int> maxItems = {10, 10, 10, 10};
    vector<int> stats = {15, 7, 3, 4};
    // int currHealth = 11;
    Character player("ShooterChar", 1, stats);
    string quitStr = "";

    // auto display = ScreenInteractive::Fullscreen();
    // ftxui::Component sidebarRenderer = fullSidebarRenderer(player, items, maxItems, quitStr, display);
    
    // Element infoSidebar = getInfoSideBar(player, items, maxItems);
    // Component quitButton = screenQuitButton(quitStr, display);
    // Component sidebarRenderer = Renderer(quitButton, [&] {
        //     return vbox({
            //     infoSidebar | yflex,
            //     quitButton->Render()
            //     });
            // });
            
    string ratDesc = "The CyberRat is a mechanical scavenger, searching the abandoned factory for scraps of metal and energy to consume.";
    vector<wstring> log = combatlog();

    // Element combatLog = getCombatLog(log);
    // Element enemyDisplay = enemySidebar(L" CyberRat ", ratDesc,  15, 15);
    // auto display = Screen::Create(Dimension::Fit(combatLog));
    
    Element combatInfoUI = GetAllCombatElements(player, log, items, maxItems, L"CyberRat", ratDesc, 15, 15);
    auto display = Screen::Create(Dimension::Fit(combatInfoUI));
    Render(display, combatInfoUI);
    cout << display.ToString() << endl;
    combatInfoUI = GetAllCombatElements(player, log, items, maxItems, L"CyberRat", ratDesc, 12, 15);

    Render(display, combatInfoUI);
    cout << display.ToString() << endl;
    combatInfoUI = GetAllCombatElements(player, log, items, maxItems, L"CyberRat", ratDesc, 9, 15);

    Render(display, combatInfoUI);
    cout << display.ToString() << endl;
    combatInfoUI = GetAllCombatElements(player, log, items, maxItems, L"CyberRat", ratDesc, 7, 15);

    Render(display, combatInfoUI);
    cout << display.ToString() << endl;
    combatInfoUI = GetAllCombatElements(player, log, items, maxItems, L"CyberRat", ratDesc, 3, 15);

    Render(display, combatInfoUI);
    cout << display.ToString() << endl;
    

    // cout << "quitStr: " << quitStr << endl;

    return 0;
}