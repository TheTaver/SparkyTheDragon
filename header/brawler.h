#ifndef __BRAWLER_H__
#define __BRAWLER_H__
#include "Attack.h"
#include "Player.h"

class Brawler : public Player{
    public:
    //constructors
    Brawler();
    Brawler (string name, string playerclass, int level, vector<int>& stats) : Player(name, playerclass, lvl, stats){};
    Brawler(string name, string playerclass, int level, vector<int>& stats, int exp, vector<int>& inventory) : Player(name, playerclass, lvl, stats, exp, inventory) {};

    Attack GetLvlUpMove(int newlvl);
};

#endif