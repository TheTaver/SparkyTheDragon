#ifndef __ENEMYSUBCLASSES_H__
#define __ENEMYSUBCLASSES_H__
#include "npc.h"
#include <random>

//lvl1 npc
class CyberRat : public NPC {
    private: //??
    int expReward = 100;
    //like 3 healths potions and maybe a dmg boost pot? (lmk) I forgot the numbers for those
    vector<int> loot = {0,0,0,1,2,3,4};
    public:
    //probs necessary to make idk
    CyberRat(const string& name, int level, vector<int>& stats) : NPC(name, level, stats) {}
    Attack GetAttack(int randSeed){ 
        return Attack("Bite", "Bites your feet! Doesn't do much damage", 100, 0, 100, 5, 0,0,0);
    };
};

//lvl2
class SecurityGaurdA : public NPC {
    private:
    int expReward = 120;
    vector<int> loot = {};
    public:
    SecurityGaurdA(const string& name, int level, vector<int>& stats) : NPC(name, level, stats) {}
    Attack GetAttack(int randSeed){
        //2 moves
        Attack move1 = Attack("Chainsaw Stab", "", 0, 0,0,0,0,0,0);
        Attack move2 = Attack("Chainsaw Slash", "", 0,0,0,0,0,0,0);
        //switch off both moves some how
        return move1;
    };
};

//final boss
class Sparky : public NPC {
    private:
    int expReward = 0;
    vector<int> loot = {0};
    public:
    Sparky(const string& name, int level, vector<int>& stats) : NPC(name, level, stats) {}
    Attack GetAttack(int randSeed){
        //4 moves
        Attack move1 = Attack("Wing Slash", "", 0, 0,0,0,0,0,0);
        Attack move2 = Attack("Thunder Bolt", "", 0,0,0,0,0,0,0);
        Attack move3 = Attack("Sparkmove3", "", 0,0,0,0,0,0,0);
        Attack move4 = Attack("Sparkmove4", "", 0,0,0,0,0,0,0);
        //switch off both moves some how
        return move1;
    };
};

#endif