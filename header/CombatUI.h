#ifndef __COMBATUI_H__
#define __COMBATUI_H__
#include "CombatInfoDisplay.h"

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
using std::string;

class CombatUI {
  public:
    struct BtnStrings {
      const string text1;
      const string text2;
      const string text3;
      const string text4;
      BtnStrings(const string& t1, const string& t2, const string& t3, const string& t4) : text1(t1), text2(t2), text3(t3), text4(t4) {};
    };
    vector<string> mvStrs;
    vector<string> itemStrs;

    const Player* playerChar;
    CombatInfoDisplay displayElements; // Top half of the screen, doesn't get User input
    string* userInputString;
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

    // BtnStrings moveStrs;
    // BtnStrings itemStrs;
    
    ftxui::ButtonOption HighlightButtonStyle();
    ftxui::Component MakeButton(const string& text);
    
    struct BtnCoords {
      // To track current selected button
      int row = 0;
      int col1 = 0;
      int col2 = 0;
      BtnCoords(int r, int c1, int c2) : row(r), col1(c1), col2(c2) {};
    };
    ftxui::Component QuadButtonMenu(BtnStrings& strings, BtnCoords& coords);

    
    ftxui::Component GetQuitButton();
    ftxui::Component GetItemButtons(BtnCoords& coords);
    ftxui::Component GetMoveButtons(BtnCoords& coords);

    ftxui::Component GetAllButtons(BtnCoords& leftCoords, BtnCoords& rightCoords);

  public:
    CombatUI(const Player* player, const NPC* enemy, string* inputString)
    : playerChar(player), displayElements(player, enemy), userInputString(inputString)
    {
      for(int i = 0; i < player->GetMoves().size(); i++) {
        mvStrs.push_back(player->GetMoves().at(i).name);
      }
      while(mvStrs.size() < 4) {
        mvStrs.push_back("None");
      }
      itemStrs.push_back("Medkits");
      itemStrs.push_back("StrBuff");
      itemStrs.push_back("AgiBuff");
      itemStrs.push_back("DefBuff");
    }

    void ShowCombatScreenUntilInput(const vector<wstring>& combatLog);
    // Get string pointer?
};


#endif