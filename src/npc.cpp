#include "../header/npc.h"
#include <cstdlib>


int NPC::GetExpReward() const {
    return expReward;
}

std::vector<int> NPC::GetLoot() const {
    return loot;
}