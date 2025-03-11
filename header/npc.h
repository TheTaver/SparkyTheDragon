// class npc; public character 
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef NPC_H
#define NPC_H

#include "Character.h"
//#include "Attack.h"

class NPC : public Character {
    private:
        int expReward;
        vector<int> loot;

    public:
        NPC(const string& name, 
            int level,
            const vector<int>& stats);

        int GetExpReward() const {
            return expReward;
        };

        vector<int> GetLoot() const {
            return loot;
        };

        //Attack GetAttack(int ) 
};


#endif
