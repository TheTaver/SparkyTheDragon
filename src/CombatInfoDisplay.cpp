#include "CombatInfoDisplay.h"

using std::string;
using std::wstring;
using std::vector;
using namespace ftxui;

// Element showing item's name, amount currently held, and max amount in a given color
Element CombatInfoDisplay::GetItemCounter(const wstring& name, const int curr, Color clr) {
  return hbox({
    text((name+L": ")), text(to_wstring(curr)) | bold | color(clr)
  });
}
Element CombatInfoDisplay::PlayerHpDisplay() {
  Color hpColor = Color::HotPink;
  return hbox({
    text(L"HP: "), text(to_wstring(player->GetCurrHp())) | bold | color(hpColor), text(L"/"+to_wstring(player->GetStat(0))) | color(hpColor)
  });
}

// Element that shows an individual stat's name and current value, with the value set to a color
Element CombatInfoDisplay::GetStatDisplay(const wstring& statName, const int amount, Color clr) {
  return hbox({
    text((statName+L": ")), text(to_wstring(amount)) | align_right | bold | color(clr)
  });
}

// Return the gauge that shows the enemy's current Hp Percentage
// Colored Green when near full hp, Orange when medium hp, Red when low on hp
Element CombatInfoDisplay::GetEnemyHpDisplay() {
  float remainingHpPercent = static_cast<double>(enemy->GetCurrHp()) / enemy->GetStat(0);
  Color gaugeColor;
  if(remainingHpPercent > 0.65) {
    gaugeColor = Color::LightGreen;
  } else if(remainingHpPercent > 0.30) {
    gaugeColor = Color::Orange1;
  } else {
    gaugeColor = Color::Red1;
  }
  return window(text(L" " +to_wstring(enemy->GetName())+L" ") | center, gauge(remainingHpPercent) | color(gaugeColor));
}

// Return the element showing the enemy's Name, Health bar, and Description
Element CombatInfoDisplay::GetEnemySidebar() {
  return vbox({
    GetEnemyHpDisplay(),
    window(text(L" Description ") | center, hflow(paragraph(enemy->GetDescription())))
  });
}

// Return the element containing the player's inventory display
Element CombatInfoDisplay::GetPlayerInventoryWindow() {
  // A window showing the player's current inventory contents
  auto content =
        vbox({
          GetItemCounter(L"MedKits", player->itemCount(0), Color::Pink1),
          GetItemCounter(L"StrBuff", player->itemCount(1), Color::Red),
          GetItemCounter(L"AgiBuff", player->itemCount(2), Color::BlueLight),
          GetItemCounter(L"DefBuff", player->itemCount(3), Color::DarkGreen),
        });

  return window(text(L" Inventory ") | center, content);
}

Element CombatInfoDisplay::GetPlayerStatWindow() {
  // A window element showing the player's current health and stats
  auto content =
        vbox({
          PlayerHpDisplay(),
          GetStatDisplay(L"Strength", player->GetStat(1), Color::Red),
          GetStatDisplay(L"Agility", player->GetStat(2), Color::BlueLight),
          GetStatDisplay(L"Defense", player->GetStat(3), Color::DarkGreen)
        });

  return window(text(L" Stats ") | center, content);
}

Element CombatInfoDisplay::GetPlayerSidebar() {
  // Put together the Player stat and item displays
  return vbox({
    GetPlayerStatWindow(),
    GetPlayerInventoryWindow()
  });
}

Element CombatInfoDisplay::GetCombatLog(const vector<wstring>& combatLog) {
  // combatLog is vector of lines of text to display in the combatLog window
  ftxui::Elements textLog;
  // Turn each line of text into a text element
  for(int i = 0; i < combatLog.size(); i++) {
    textLog.push_back(text(combatLog.at(i)));
  }
  // Display all text elements in a vbox
  return window(text(L" Combat Log ") | center, vbox({textLog}));
}

// Get entire top half of combat UI
// All NON-INPUT sections (Displays Only)
Element CombatInfoDisplay::GetAllCombatElements(const vector<wstring>& combatLog) {
  // Columns displayed from left to right
  Element enemySidebar = GetEnemySidebar();
  Element combatLogElement = GetCombatLog(combatLog);
  Element playerSidebar = GetPlayerSidebar();
  
  // Resize the elements if necessary
  return hbox({
    // enemySidebar,
    enemySidebar | size(WIDTH, LESS_THAN, 40),
    separator(),
    // combatLogElement,
    combatLogElement | size(WIDTH, GREATER_THAN, 60),
    separator(),
    playerSidebar | size(WIDTH, GREATER_THAN, 14)
  });
}
