#ifndef __COMBATCONTROLLER_H__
#define __COMBATCONTROLLER_H__

#include "CombatUI.h"
#include "Player.h"
#include "npc.h"

class CombatController {
    private:
        Player* player;
        NPC* enemy;
        const string npcFilename;
    public:
        CombatController(Player* playerChar, const string& enemyFile) :
        player(playerChar), npcFilename(enemyFile)
        {
            enemy = NPCReader::ReadEnemy(npcFilename);
        }


};

#endif