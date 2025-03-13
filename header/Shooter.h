#ifndef SHOOTER_H
#define SHOOTER_H

#include "Player.h"
#include "Attack.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Shooter : public Player {
    public: 

        Shooter();
        Shooter(const string& name, const string& playerClass, int level, vector<int>& stats);
        Shooter(const string& name, const string& playerClass, int level, vector<int>& stats, int exp, vector<int>& inventory);
    
        Attack GetLvlUpMove(int newLvl) override;
    };

#endif