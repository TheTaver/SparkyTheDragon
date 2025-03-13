#ifndef __BRAWLER_H__
#define __BRAWLER_H__
#include "Attack.h"
#include "Player.h"

class Brawler : public Player{
    public:
    //constructors
    Brawler();
    Brawler(string name, string playerclass, int level, vector<int>& stats) : Player(name, "Brawler", lvl, stats){ moves.push_back(GetLvlUpMove(1)); };
    Brawler(string name, string playerclass, int level, vector<int>& stats, int exp, vector<int>& inventory);

    Attack GetLvlUpMove(int newlvl);
};

#endif
