#ifndef SHOOTER_H
#define SHOOTER_H
#include "Player.h"
#include "Attack.h"

class Shooter : public Player{
    public:

    Shooter();

    Shooter(std::string name, std::string playerClass, int level, std::vector<int>& stats);

    Shooter(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory);

    Attack GetLvlUpMove(int newLvl) override;
};



#endif