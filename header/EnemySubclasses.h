#ifndef __ENEMYSUBCLASSES_H__
#define __ENEMYSUBCLASSES_H__
#include "npc.h"
#include <random>

//lvl1
class CyberRat : public NPC {
    public:
    CyberRat() : NPC("CyberRat", 1, 
            "The CyberRat is a mechanical scavenger, searching the abandoned factory for scraps of metal and energy to consume.",
            {20, 5, 5, 5}, 100, {3, 1, 0, 0}) {}
    CyberRat(const string& name, int level, const string& description,
            const vector<int>& stats, int xpReward, const vector<int>& itemLoot)
            : NPC(name, level, description, stats, xpReward, itemLoot) {}

    Attack GetAttack(int randSeed) override {
        return Attack("Bite", "", 80, 30, 30, 6, 0, -1, 0);
    }

};

//lvl2
class SecurityGaurdA : public NPC {
    public:
    SecurityGaurdA(): NPC("SecurityGaurdA", 2, 
            "This Secuirty Gaurd has chainsaws for arms! Its program got corrupted, destorying every living thing it sees.",
            {25, 3, 3, 3}, 110, {2,2,1,0,0}) {}
    SecurityGaurdA(const string& name, int level, const string& description,
            const vector<int>& stats, int xpReward, const vector<int>& itemLoot)
            : NPC(name, level, description, stats, xpReward, itemLoot) {}

    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Chainsaw Stab", "", 85, 30,30,7,0,-2,0);
        Attack move2 = Attack("Chainsaw Slash", "", 87,30,30,9,0,-2,0);

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

class SecurityGaurdB : public NPC {
    public:
    SecurityGaurdB(): NPC("SecuirtyGaurdB", 2, 
            "This Security Gaurd has knives as fingers! Its program also got corrupted, destorying every living thing it sees.",
            {25, 4, 4, 4}, 110, {3,3,1,0,0}) {};
    SecurityGaurdB(const string& name, int level, const string& description,
            const vector<int>& stats, int xpReward, const vector<int>& itemLoot)
            : NPC(name, level, description, stats, xpReward, itemLoot) {}
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Puncture", "", 80, 30,30,6,0,-1,0);
        Attack move2 = Attack("Sharp Claw", "", 90,30,30,10,0,-2,0);
         
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

//lvl3
class RoboNinja : public NPC {
    public:
    RoboNinja(): NPC("RoboNinja", 3, 
            "! ",
            {33, 8, 8, 8}, 110, {0,0,0,1,2,3}) {};
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("", "", 80, 30,30,6,0,-1,0);
        Attack move2 = Attack("Sharp Claw", "", 90,30,30,10,0,-2,0);
        Attack move3 = Attack("Triple Kunai", "", 93,30,30,13,0,-3,0);

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

// class SecurityGaurdA : public NPC {
//     public:
//     SecurityGaurdA(const string& name, int level, vector<int>& stats) : NPC(name, level, stats) {}
//     Attack GetAttack(int randSeed){
//         Attack move1 = Attack("Chainsaw Stab", "", 0, 0,0,0,0,0,0);
//         Attack move2 = Attack("Chainsaw Slash", "", 0,0,0,0,0,0,0);
//         //switch off both moves some how
//         return move1;
//     };
// };

class FactoryCEO : public NPC {
    public:
   
};
//final boss
class Sparky : public NPC {
    public:
    Sparky(): NPC("Sparky The Dragon", 4, 
        "! ",
        {50, 12, 12, 12}, 0, {}) {};
    Attack GetAttack(int randSeed){
        Attack move1 = Attack("Wing Slash", "", 0, 0,0,0,0,0,0);
        Attack move2 = Attack("Thunder Bolt", "", 0,0,0,0,0,0,0);
        Attack move3 = Attack("Sparkmove3", "", 0,0,0,0,0,0,0);
        Attack move4 = Attack("Sparkmove4", "", 0,0,0,0,0,0,0);
        return move1;
    };
};

#endif