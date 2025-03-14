#include "../header/Duelist.h"
#include <stdexcept>

Duelist::Duelist() : Player() { moves.push_back(GetLvlUpMove(1)); }

Duelist::Duelist(const std::string& name, const std::string& playerClass, int level, std::vector<int>& stats) 
: Player(name, playerClass, level, stats) { moves.push_back(GetLvlUpMove(1)); }

Duelist::Duelist(const std::string& name, const std::string& playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) { moves.push_back(GetLvlUpMove(1)); }

Attack Duelist::GetLvlUpMove(int newLvl) {

    switch(newLvl){
    case 1: 
    return Attack("Quick Slash", false, 95, 5, 5, 10, 0, 0, 0);

    case 2: 
    return Attack("Piercing Thrust", false, 90, 3, 3, 15, 30, 3, -3);

    case 3: 
    return Attack("Blade Dance", false, 85, 3, 3, 20, 20, 2, -4);

    case 4: 
    return Attack("Master Parry", false, 90, 2, 2, 25, 50, 3, -5);

    default:
    throw std::invalid_argument("Invalid level requested for attack: " + std::to_string(newLvl));

}
}
