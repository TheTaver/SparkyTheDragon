// #include "MenuDisplay.h"
#include "CombatUI.h"
#include "CyberRat.h"
#include "Duelist.h"

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
    // Initialize test variables
    vector<int> stats = {15, 8, 2, 4};
    string ratDesc = "The CyberRat is a mechanical scavenger, searching the abandoned factory for scraps of metal and energy to consume.";
    vector<wstring> log = makeCombatLog();
    Duelist* playerChar = new Duelist("Shooty Guy", 1, stats);
    NPC* rat = new CyberRat();
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2*i; j++) {
            playerChar->addItem(i);
        }
    }

    string inputStr = "This is a very long string so that it has lots of space for input text.";
    
    // auto display = ScreenInteractive::Fullscreen();
    // ftxui::Component sidebarRenderer = fullSidebarRenderer(player, items, maxItems, quitStr, display);
    
    // Element infoSidebar = GetPlayerSidebar(player, items, maxItems);
    // Component quitButton = screenQuitButton(quitStr, display);
    CombatUI combUI(playerChar, rat, &inputStr);
    CombatUI::BtnCoords left(0, 0, 0);
    CombatUI::BtnCoords right(0, 0, 0);
    // Component buttons = combUI.GetAllButtons(left, right);
    Component buttons = combUI.GetMoveButtons(left);
    
            
    combUI.screen.Loop(buttons);

    // Element combatLog = getCombatLog(log);
    // Element enemyDisplay = enemySidebar(L" CyberRat ", ratDesc,  15, 15);
    // auto display = Screen::Create(Dimension::Fit(combatLog));


    // CombatInfoDisplay infoDisplay(playerChar, rat);
    // Element combatDisplay = infoDisplay.GetAllCombatElements(log);
    
    
    

    return 0;
}