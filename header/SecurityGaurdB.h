#ifndef __SECURITYGAURDB_H__
#define __SECURITYGAURDB_H__
#include "npc.h"
#include <random>

class SecurityGaurdB : public NPC {
    public:
    SecurityGaurdB(): NPC("SecuirtyGaurdB", 2, 
            "This Security Gaurd has knives as fingers! Its program also got corrupted, destorying every living thing it sees.",
            {25, 4, 4, 4}, 110, {3,3,1,0,0}) {};
            
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Puncture", false, 80, 30,30,6,0,-1,0);
        Attack move2 = Attack("Sharp Claw", false, 90,30,30,10,0,-2,0);
         
        srand(randSeed);
        int randChoice = rand() % 2;
        if (randChoice == 0){
            return move1;
        }
        else{
            return move2;
        }
    }
};

#endif