#include "../header/npc.h"

#include <cstdlib>
#include <vector>

using std::vector;


int NPC::GetExpReward() const {
    return expReward;
}

void NPC::SetExpReward(int newExpReward) {
    // can expReward be negative???
    // if (newExpReward >= 0) {
        expReward = newExpReward;
    // }
}

vector<int> NPC::GetLoot() const {
    return loot;
}

void NPC::SetLoot(vector<int> newLoot) {
    loot = newLoot;
}