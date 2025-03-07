#ifndef NPC_H
#define NPC_H
// class npc; public character 
#include <string>
#include <vector>

using std::string;
using std::vector;


#include "Character.h"
//#include "Attack.h"

class NPC : public Character {
    private:
        int expReward;
        vector<int> loot;
        const string enemyDescription;

    public:
        NPC(const string& name, 
            int level,
            const string& description,
            const vector<int>& stats) : 
            Character(name, level, stats), enemyDescription(description) {};

        int GetExpReward() const {
            return expReward;
        };

        vector<int> GetLoot() const {
            return loot;
        };

        const string GetDescription() const { return enemyDescription; }

        //Attack GetAttack(int ) 
};

#endif
