#include "../header/Shooter.h"
#include <stdexcept>
#include <vector>
#include <string>

using std::vector;
using std::string;

Shooter::Shooter() :Player() { moves.push_back(GetLvlUpMove(1)); }

Shooter::Shooter(const string& name, const string& playerClass, int level, vector<int>& stats) 
: Player(name, playerClass, level, stats) { moves.push_back(GetLvlUpMove(1)); }

Shooter::Shooter(const string& name, const string& playerClass, int level, vector<int>& stats, int exp, vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) { moves.push_back(GetLvlUpMove(1)); }

Attack Shooter::GetLvlUpMove(int newLvl) {

    switch(newLvl){
    case 1: 
    return Attack("Gummo", false, 95, 5, 5, 10, 0, 0, 0);

    case 2: 
    return Attack("Murder on My Mind", false, 90, 3, 3, 15, 30, 3, -3);

    case 3: 
    return Attack("Ransom", false, 85, 3, 3, 20, 20, 2, -4);

    case 4: 
    return Attack("No Auto", false, 90, 2, 2, 25, 50, 3, -5);

    default:
    throw std::invalid_argument("Invalid level requested for attack: " + std::to_string(newLvl));
    
}
}
