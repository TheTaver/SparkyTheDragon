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

    
    ftxui::ButtonOption HighlightButtonStyle();
    ftxui::Component MakeButton(const string& text);
    
    struct BtnCoords {
      // To track current selected button
      int row = 0;
      int col1 = 0;
      int col2 = 0;
    };
    ftxui::Component QuadButtonMenu(const string& text1, const string& text2, const string& text3, const string& text4, BtnCoords& coords);

    
    ftxui::Component GetQuitButton();
    ftxui::Component GetItemButtons(BtnCoords& coords);
    ftxui::Component GetMoveButtons(BtnCoords& coords);

    ftxui::Component GetAllButtons(BtnCoords& leftCoords, BtnCoords& rightCoords);

  public:
    CombatUI(const Player* playerChar, const NPC* enemy, string* inputString)
    : displayElements(playerChar, enemy), userInputString(inputString)
    {}

    void ShowCombatScreenUntilInput(const vector<wstring>& combatLog);
    // Get string pointer?
};


#endif