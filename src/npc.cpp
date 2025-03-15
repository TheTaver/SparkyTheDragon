#include "../header/npc.h"
#include <stdexcept>

#include <cstdlib>
#include <vector>

using std::vector;
using std::runtime_error;


int NPC::GetExpReward() const {
    return expReward;
}

void NPC::SetExpReward(int newExpReward) {
    if (newExpReward < 0) throw runtime_error("Cannot have negative experience");
    expReward = newExpReward;
}

vector<int> NPC::GetLoot() const {
    return loot;
}

void NPC::SetLoot(vector<int> newLoot) {
    loot = newLoot;
}