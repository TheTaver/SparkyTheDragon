#include "../header/Duelist.h"
#include <stdexcept>

Duelist::Duelist() : Player() {}

Duelist::Duelist(std::string name, std::string playerClass, int level, std::vector<int>& stats) 
: Player(name, playerClass, level, stats) {}

Duelist::Duelist(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) {}

Attack Duelist::GetLvlUpMove(int newLvl) {

    switch(newLvl){
    case 1: 
    return Attack("Quick Slash", "A swift sword slash.", 95, 5, 5, 10, 0, 0, 0);

    case 2: 
    return Attack("Piercing Thrust", "A thrust aimed at the weak spots.", 90, 3, 3, 15, 30, 3, -3);

    case 3: 
    return Attack("Blade Dance", "A rapid series of sword strike.", 85, 3, 3, 20, 20, 2, -4);

    case 4: 
    return Attack("Master Parry", "A counterattack that reduces enemy defense.", 90, 2, 2, 25, 50, 3, -5);

    default:
    throw std::invalid_argument("Invalid level requested for attack: " + std::to_string(newLvl));
    
}
}

