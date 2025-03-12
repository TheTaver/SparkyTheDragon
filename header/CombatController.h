#ifndef __COMBATCONTROLLER_H__
#define __COMBATCONTROLLER_H__

#include "CombatUI.h"
#include "CombatLog.h"
#include "NPCReader.h"
#include "Player.h"
#include "npc.h"

class CombatController {
    private:
        Player* player;
        NPC* enemy;
        const string npcFilename;
        CombatLog combatLog;

        string GetPlayerInput() const;
        string GetValidAction();
        bool DoRound(int rand); // Returns whether to continue combat or not
        void UseMove(Character* attacker, Attack& move, Character* target, const int roundSeed);
    public:
        CombatController(Player* playerChar, const string& enemyFile);
        ~CombatController();

        // rule of 3
        CombatController(const CombatController& rhs) = delete;
        CombatController operator=(const CombatController& rhs) = delete;

        void StartCombat(int randSeed = -1); // -1 indicates no seed
};

#endif