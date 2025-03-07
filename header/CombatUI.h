#ifndef __COMBATUI_H__
#define __COMBATUI_H__
#include "CombatInfoDisplay.h"

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
using std::string;

class CombatUI {
  public:
    const Player* playerChar;
    CombatInfoDisplay displayElements; // Top half of the screen, doesn't get User input
    string* userInputString;
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
    
    ftxui::Component MakeButton(const string& text);

  public:
    CombatUI(const Player* player, const NPC* enemy, string* inputString)
    : playerChar(player), displayElements(player, enemy), userInputString(inputString)
    {}

    void ShowCombatScreenUntilInput(const vector<wstring>& combatLog);
};


#endif