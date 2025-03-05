#include "../header/Shooter.h"

Shooter::Shooter() : Player() {}

Shooter::Shooter(std::string name, std::string playerClass, int level, std::vector<int>& stats) 
: Player(name, playerClass, level, stats) {}

Shooter::Shooter(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) {}

Attack Shooter::GetLvlUpMove(int newLvl) {

    if(newLvl == 3) {
        return Attack();
    }
    else if(newLvl == 5) {
        return Attack();

    }
    else if(newLvl == 7) {
        return Attack();
    }
    else if(newLvl == 10){
        return Attack();
    }

    return Attack();
}