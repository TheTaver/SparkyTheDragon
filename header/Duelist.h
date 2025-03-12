#ifndef DUELIST_H
#define DUELIST_H

#include "Player.h"
#include "Attack.h"

class Duelist : public Player {
    public: 

        Duelist();
        Duelist(std::string name, int level, std::vector<int>& stats) : Player(name, "Duelist", level, stats) { moves.push_back(GetLvlUpMove(1)); };
        Duelist(std::string name, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory);

        Attack GetLvlUpMove(int newLvl) { return Attack("Quick Slash", false, 95, 15, 15, 10, 0, 0, 0); };
    };

#endif