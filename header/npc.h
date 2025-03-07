#ifndef NPC_H
#define NPC_H
#include "Character.h"
#include "Attack.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class NPC : public Character {
    private:
        int expReward;
        vector<int> loot;
        const string enemyDescription;

    public:
        NPC(const string& name, 
            int level,
            const string& description,
            const vector<int>& stats, int xpReward, const vector<int>& itemLoot) : 
            Character(name, level, stats), enemyDescription(description), expReward(xpReward), loot(itemLoot) {};

        int GetExpReward() const;
        vector<int> GetLoot() const;
        virtual Attack GetAttack(int seed) = 0;
        const string GetDescription() const { return enemyDescription; }
};

#endif
