#ifndef __SECURITYGAURDA__
#define __SECURITYGAURDA__
#include "npc.h"

class SecurityGaurdA : public NPC {
    public:
    SecurityGaurdA(): NPC("SecurityGaurdA", 2, 
            "This Secuirty Gaurd has chainsaws for arms! Its program got corrupted, destorying every living thing it sees.",
            {25, 3, 3, 3}, 110, {2,2,1,0,0}) {}
    SecurityGaurdA(const string& name, int level, const string& description,
            const vector<int>& stats, int xpReward, const vector<int>& itemLoot)
            : NPC(name, level, description, stats, xpReward, itemLoot) {}

    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Chainsaw Stab", false, 85, 30,30,7,0,-2,0);
        Attack move2 = Attack("Chainsaw Slash", false, 87,30,30,9,0,-2,0);

        srand(randSeed);
        int randChoice = rand() %2;
        if (randChoice == 0){
            return move1;
        }
        else{
            return move2;
        }
    }
};

#endif