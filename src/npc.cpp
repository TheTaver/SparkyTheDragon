#include "../header/npc.h"
#include <cstdlib>

NPC::NPC(const std::string& name, int level, const std::vector<int>& stats, int expReward, const std::vector<int>& loot)
    : Character(name, level, stats), expReward(expReward), loot(loot) {}

int NPC::GetExpReward() const {
    return expReward;
}

std::vector<int> NPC::GetLoot() const {
    return loot;
}
