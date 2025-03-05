#ifndef DUELIST_H
#define DUELIST_H

#include "Player.h"
#include "Attack.h"

class Duelist : public Player {
    public: 

        Duelist();
        Duelist(std::string name, std::string playerClass, int level, std::vector<int>& stats);
        Duelist(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory);
    
        Attack GetLvlUpMove(int newLvl) override;
    };

#endif