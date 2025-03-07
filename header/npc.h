#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Attack.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class NPC : public Character {
protected:
    int expReward;
    vector<int> loot;

public:
    NPC(const string& name, int level, const vector<int>& stats, int expReward, const vector<int>& loot);

    int GetExpReward() const;
    vector<int> GetLoot() const;
    virtual Attack GetAttack(int seed) = 0;
};

#endif
