#include "brawler.h"
#include "Attack.h"
#include <stdexcept>

Brawler::Brawler() : Player() { moves.push_back(GetLvlUpMove(1)); }

Brawler::Brawler(const std::string& name, const std::string& playerClass, int level, std::vector<int>& stats) 
: Player(name, playerClass, level, stats) { moves.push_back(GetLvlUpMove(1)); }

Brawler::Brawler(const std::string& name, const std::string& playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) { moves.push_back(GetLvlUpMove(1)); }

Attack Brawler::GetLvlUpMove(int newlvl){
    if (newlvl == 1){
        return Attack("Punch", false, 95, 20, 20, 5, 0, 0, 0);
    }
    else if (newlvl == 2){
        return Attack("Sweep Kick", false, 90, 15, 15, 10, 0, 0, 0);
    }
    else if (newlvl == 3){
        return Attack("Body Slam", false, 85, 10, 10, 15, 0, 0, 0);
    }
    else if (newlvl == 4){
        return Attack("Ultimate Taijutsu Combo", false, 80, 5, 5, 20, 0, 0, 0);
    }
    else{
        throw std::invalid_argument("cant lvl up more than 4 times");
    }
}