#ifndef __COMBATINFODISPLAY_H__
#define __COMBATINFODISPLAY_H__
#include <ftxui/dom/elements.hpp>
#include "Player.h"
#include "npc.h"

using std::wstring;
using ftxui::Element;
using ftxui::Color;

class CombatInfoDisplay {
  private:
      const Player* player;
      const NPC* enemy;

      ftxui::Element GetItemCounter(const wstring& name, const int curr, ftxui::Color clr);
      ftxui::Element GetStatDisplay(const wstring& name, const int amount, ftxui::Color clr);
      ftxui::Element PlayerHpDisplay();
      
      Element GetEnemyHpDisplay();
      Element GetEnemySidebar();

      Element GetCombatLog(const std::vector<wstring>& combatlog);

      Element GetPlayerStatWindow();
      Element GetPlayerInventoryWindow();
      Element GetPlayerSidebar();

    public:
      CombatInfoDisplay(const Player* playerChar, const NPC* battleOpponent) : player(playerChar), enemy(battleOpponent) {};

      Element GetAllCombatElements(const vector<wstring>& combatlog);
};

#endif