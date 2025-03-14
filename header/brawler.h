#ifndef BRAWLER_H
#define BRAWLER_H

#include "Player.h"
#include "Attack.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Brawler : public Player {
    public: 

        Brawler();
        Brawler(const string& name, const string& playerClass, int level, vector<int>& stats);
        Brawler(const string& name, const string& playerClass, int level, vector<int>& stats, int exp, vector<int>& inventory);
    
        Attack GetLvlUpMove(int newLvl) override;
    };

#endif
