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
    Duelist* playerChar = new Duelist("Shooty Guy", "Duelist", 1, stats);
    NPC* rat = new CyberRat();
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2*i; j++) {
            playerChar->addItem(i);
        }
    }

    string inputStr = "This is a very long string so that it has lots of space for input text.";
    
    CombatUI combUI(playerChar, rat, &inputStr);
    combUI.ShowCombatScreenUntilInput(log);

    cout << "Input: " << inputStr << endl;

}