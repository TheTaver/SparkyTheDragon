#ifndef __SPARKY_H__
#define __SPARKY_H__
#include "npc.h"
#include <random>

class Sparky : public NPC {
    public:
    Sparky(): NPC("Sparky The Dragon", 4, 
        "You bother them! Now they want to kill you because you bothered them! rawr!",
        {50, 15, 15, 15}, 0, {}) {};
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Wing Slash", false, 95, 30,30,15,0,0,0);
        Attack move2 = Attack("Thunder Bolt", false, 90,30,30,22,0,0,0);
        Attack move3 = Attack("Metalic Spikes", false, 85,30,30,25,0,0,0);
        Attack move4 = Attack("Lighting Breath", false, 50,30,30,35,0,0,0);
        srand(randSeed);
        int randChoice = rand() % 4;
        if (randChoice == 0){
            return move1;
        }
        else if (randChoice == 1){
            return move2;
        }
        else if (randChoice == 2){
            return move3;
        }
        else{
            return move4;
        }
    };
};

#endif