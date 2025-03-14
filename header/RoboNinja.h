#ifndef __ROBONINJA_H__
#define __ROBONINJA_H__
#include "npc.h"
#include <random>

class RoboNinja : public NPC {
    public:
    RoboNinja(): NPC ("RoboNinja", 3, 
            "This RoboNinja is looking for parts for his half dead RoboBrother! And you bothered him so he is attacking you now.",
            {33, 8, 8, 8}, 110, {0,0,0,1,2,3}) {};
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Shirukin", "", 80, 30,30,6,0,1,0);
        Attack move2 = Attack("Sharp Claw", "", 90,30,30,10,90,2,-1);
        Attack move3 = Attack("Triple Kunai", "", 93,30,30,13,95,3,-2);

        srand(randSeed);
        int randChoice = rand() % 3;
        if (randChoice == 0){
            return move1;
        }
        else if (randChoice == 1){
            return move2;
        }
        else {
            return move3;
        }
    }
};

#endif