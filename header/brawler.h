#ifndef __BRAWLER_H__
#define __BRAWLER_H__
#include "Attack.h"
#include "Player.h"

class Brawler : public Player{
    public:
    //constructors
    Brawler();
    Brawler(const std::string& name, const std::string& playerClass, int level, std::vector<int>& stats);
    Brawler(const std::string& name, const std::string& playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory);

    Attack GetLvlUpMove(int newlvl) override;
};

#endif
