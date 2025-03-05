// #include "MenuDisplay.h"
#include "CombatInfoDisplay.h"
#include "Character.h"
#include "CyberRat.h"

# include <ftxui/component/screen_interactive.hpp>
#include <vector>


using namespace std;

vector<wstring> makeCombatLog() {
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
    using namespace ftxui;
    vector<int> items = {2, 3, 4, 5};
    vector<int> maxItems = {10, 10, 10, 10};
    vector<int> stats = {15, 8, 2, 4};
    // int currHealth = 11;
    string quitStr = "";

    // auto display = ScreenInteractive::Fullscreen();
    // ftxui::Component sidebarRenderer = fullSidebarRenderer(player, items, maxItems, quitStr, display);
    
    // Element infoSidebar = GetPlayerSidebar(player, items, maxItems);
    // Component quitButton = screenQuitButton(quitStr, display);
    // Component sidebarRenderer = Renderer(quitButton, [&] {
        //     return vbox({
            //     infoSidebar | yflex,
            //     quitButton->Render()
            //     });
            // });
            
    string ratDesc = "The CyberRat is a mechanical scavenger, searching the abandoned factory for scraps of metal and energy to consume.";
    vector<wstring> log = makeCombatLog();

    // Element combatLog = getCombatLog(log);
    // Element enemyDisplay = enemySidebar(L" CyberRat ", ratDesc,  15, 15);
    // auto display = Screen::Create(Dimension::Fit(combatLog));
    Player* playerChar = new Player("Shooty Guy", "Shooter", 1, stats);
    NPC* rat = new CyberRat();

    CombatInfoDisplay infoDisplay(playerChar, rat);
    Element combatDisplay = infoDisplay.GetAllCombatElements(log);
    auto display = Screen::Create(Dimension::Fit(combatDisplay));
    Render(display, combatDisplay);
    cout << display.ToString() << endl;

    

    return 0;
}