#ifndef __COMBATDISPLAY_H__
#define __COMBATDISPLAY_H__

#include <iostream>
#include <ftxui/dom/elements.hpp>
# include <ftxui/component/component.hpp>
# include <ftxui/component/event.hpp>
# include <ftxui/component/screen_interactive.hpp>
# include <ftxui/component/loop.hpp>

#include <vector>
#include <string>

// #include "NPC.h"
#include "Character.h"

using std::string;
using std::wstring;
using std::vector;
using namespace ftxui;

Element itemCounter(const wstring& name, const int curr, const int max, Color clr) {
  return hbox({
    text((name+L": ")), text(to_wstring(curr)) | bold | color(clr), text(L"/"+to_wstring(max)) | color(clr),
  });
}

Element statDisplay(const wstring& name, const int amount, Color clr) {
  return hbox({
    text((name+L": ")), text(to_wstring(amount)) | align_right | bold | color(clr)
  });
}

Element playerInventoryWindow(const vector<int>& currItems, const vector<int>& maxItems) {
  if(currItems.size() != 4 or maxItems.size() != 4) 
    throw std::invalid_argument("Curr and Max stats must have Medkits, Str, Agi, Def items");
  auto content =
        vbox({
          itemCounter(L"MedKits", currItems[0], maxItems[0], Color::Pink1),
          itemCounter(L"StrBuff", currItems[1], maxItems[1], Color::Red),
          itemCounter(L"AgiBuff", currItems[2], maxItems[2], Color::BlueLight),
          itemCounter(L"DefBuff", currItems[3], maxItems[3], Color::DarkGreen),
        });

  return window(text(L" Player Info ") | center, content);
}

Element playerStatWindow(const int currHP, const vector<int>& stats) {
  if(stats.size() != 4) 
    throw std::invalid_argument("Curr and Max stats must have Health, Strength, Agility, Defense stats");
  auto content =
        vbox({
          itemCounter(L"HP", currHP, stats[0], Color::HotPink),
          statDisplay(L"Strength", stats[1], Color::Red),
          statDisplay(L"Agility", stats[2], Color::BlueLight),
          statDisplay(L"Defense", stats[3], Color::DarkGreen)
        });

  return window(text(L" Stats ") | center, content);
}

Element getScreenSideBar(const int currHp, const vector<int>& playerStats, const vector<int>& currItems, const vector<int>& maxItems) {
  return vbox({
    playerInventoryWindow(currItems, maxItems),
    playerStatWindow(currHp, playerStats)
  }) | border;
}

/*
class CombatDisplay {
    private:
        const Player* player;
        // const NPC* opponent;

    public:
        CombatDisplay(const Player* playerChar, const NPC* battleOpponent) : player(playerChar), opponent(battleOpponent);


      string DisplayCombat() const{
        string playerInput = "";
        auto screen = ScreenInteractive::FitComponent();
        
        auto newgameb = Button("New Game", [&] { playerInput = "Start"; screen.ExitLoopClosure()(); }, Style()); //to screen.charcostumization()
        auto loadgameb = Button("Continue Load Game", [&] { playerInput = "Continue"; screen.ExitLoopClosure()(); }, Style()); //to screen.ingame()
        auto quitb = Button("Quit", [&] { playerInput = "Quit"; screen.ExitLoopClosure()(); }, Style());
     
        // The tree of components. This defines how to navigate using the keyboard.
        // The selected `row` is shared to get a grid layout.
        int row = 0;
        auto buttons = Container::Vertical({
          newgameb | flex,
          loadgameb | flex,
          quitb | flex
        });
     
        // Modify the way to render them on screen:
        auto renderer = Renderer(buttons, [&] {
          return vbox({
                    text("Sparky the Dragon!") | center | bold,
                    separator(),
                    buttons->Render() | flex,
                }) | flex | border;
        });
    
        screen.Loop(renderer);
        return playerInput;
      };
      
};
*/
#endif