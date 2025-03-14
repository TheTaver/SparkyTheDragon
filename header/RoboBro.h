#ifndef __ROBOBRO_H__
#define __ROBOBRO_H__
#include "npc.h"
#include <random>

class RoboBro : public NPC {
    public:
    RoboBro(): NPC ("RoboBro", 3, 
            "You killed his brother! Now hes mad and will try to avenge him and also steal your limbs to fix himself.",
            {33, 9, 9, 8}, 110, {0,0,0,0,1,2,3}) {};
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Fist Bump", false, 80, 30,30,7,0,1,0);
        Attack move2 = Attack("Revenge Screech", false, 90,30,30,11,90,2,-1);
        Attack move3 = Attack("Beat Up", false, 93,30,30,14,95,3,-2);

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