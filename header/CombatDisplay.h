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

// Element showing item's name, amount currently held, and max amount in a given color
Element itemCounter(const wstring& name, const int curr, const int max, Color clr) {
  return hbox({
    text((name+L": ")), text(to_wstring(curr)) | bold | color(clr), text(L"/"+to_wstring(max)) | color(clr),
  });
}

// Element that shows an individual stat's name and current value, with the value set to a color
Element statDisplay(const wstring& name, const int amount, Color clr) {
  return hbox({
    text((name+L": ")), text(to_wstring(amount)) | align_right | bold | color(clr)
  });
}

// Return the gauge that shows the enemy's current Hp Percentage
// Colored Green when near full hp, Orange when medium hp, Red when low on hp
Element enemyHpDisplay(const wstring& name, const int currHp, const int maxHp) {
  float remainingHpPercent = static_cast<double>(currHp) / maxHp;
  Color gaugeColor;
  if(remainingHpPercent > 0.65) {
    gaugeColor = Color::LightGreen;
  } else if(remainingHpPercent > 0.30) {
    gaugeColor = Color::Orange1;
  } else {
    gaugeColor = Color::Red1;
  }
  return window(text(L" " +name+L" ") | center, gauge(remainingHpPercent) | color(gaugeColor));
}

// Return the element showing the enemy's Name, Health bar, and Description
Element getEnemySidebar(const wstring& name, const string& enemyDesc, const int enemyHp, const int enemyMaxHp) {
  return vbox({
    enemyHpDisplay(name, enemyHp, enemyMaxHp),
    window(text(L" Description ") | center, hflow(paragraph(enemyDesc)))
  });
}

// Return the element containing the player's inventory display
Element playerInventoryWindow(const vector<int>& currItems, const vector<int>& maxItems) {
  if(currItems.size() != 4 or maxItems.size() != 4) 
    throw std::invalid_argument("Curr and Max stats must have Medkits, Str, Agi, Def items");
  // A window showing the player's current inventory contents
  auto content =
        vbox({
          itemCounter(L"MedKits", currItems[0], maxItems[0], Color::Pink1),
          itemCounter(L"StrBuff", currItems[1], maxItems[1], Color::Red),
          itemCounter(L"AgiBuff", currItems[2], maxItems[2], Color::BlueLight),
          itemCounter(L"DefBuff", currItems[3], maxItems[3], Color::DarkGreen),
        });

  return window(text(L" Inventory ") | center, content);
}

Element playerStatWindow(const Character& player) {
  // A window element showing the player's current health and stats
  auto content =
        vbox({
          itemCounter(L"HP", player.GetCurrHp(), player.GetStat(0), Color::HotPink),
          statDisplay(L"Strength", player.GetStat(1), Color::Red),
          statDisplay(L"Agility", player.GetStat(2), Color::BlueLight),
          statDisplay(L"Defense", player.GetStat(3), Color::DarkGreen)
        });

  return window(text(L" Stats ") | center, content);
}
// Element getInfoSideBar(const Character& player) { // TODO: Swap character for player class, so can get inv status
Element getInfoSideBar(const Character& player, const vector<int>& currItems, const vector<int>& maxItems) {
  // Put together the Player stat and item displays
  return vbox({
    playerStatWindow(player),
    playerInventoryWindow(currItems, maxItems)
  });
}

Element getCombatLog(const vector<wstring>& combatLog) {
  // combatLog is vector of lines of text to display in the combatLog window
  Elements textLog;
  // Turn each line of text into a text element
  for(int i = 0; i < combatLog.size(); i++) {
    textLog.push_back(text(combatLog.at(i)));
  }
  // Display all text elements in a vbox
  return window(text(L" Combat Log ") | center, vbox({textLog}));
}

// Make buttons fill in background & bold name when hovered/selected
ButtonOption Style() {
  auto option = ButtonOption::Animated();
  option.transform = [](const EntryState& s) {
    auto element = text(s.label);
    if (s.focused) {
      element |= bold;
    }
    return element | center | borderEmpty | flex;
  };
  return option;
};

// Get entire top half of combat UI
// All NON-INPUT sections (Displays Only)
Element GetAllCombatElements(Character& player, const vector<wstring>& combatLog,
  const vector<int>& currItems, const vector<int>& maxItems,
  const wstring& enemyName, const string& enemyDesc, const int enemyHp, const int enemyMaxHp) {
    
    // Columns displayed from left to right
    Element enemySidebar = getEnemySidebar(enemyName, enemyDesc, enemyHp, enemyMaxHp);
    Element combatLogElement = getCombatLog(combatLog);
    Element playerSidebar = getInfoSideBar(player, currItems, maxItems);
    
    // Resize the elements if necessary
    return hbox({
      // enemySidebar,
      enemySidebar | size(WIDTH, LESS_THAN, 40),
      separator(),
      // combatLogElement,
      combatLogElement | size(WIDTH, GREATER_THAN, 60),
      separator(),
      playerSidebar
    });
}

// Returns component for the quit button
Component screenQuitButton(string& quitStr, ScreenInteractive& screen) {
  return Button("Quit Game", [&] { quitStr = "Quit"; screen.ExitLoopClosure()(); }, Style());;
}

// Doesn't work
void fullSidebarRenderer(const Character& player, const vector<int>& currItems, const vector<int>& maxItems, string& quitStr, ScreenInteractive& screen) {
  Element infoSidebar = getInfoSideBar(player, currItems, maxItems);
  Component quitButton = screenQuitButton(quitStr, screen);
  Component sidebarRenderer = Renderer(quitButton, [&] {
    return vbox({
      infoSidebar | yflex,
      quitButton->Render()
    });
  });
  screen.Loop(sidebarRenderer);
} 


/*
class CombatDisplay {
    private:
        

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