#include "Character.h"
#include <stdexcept>

Character::Character(const string& charName, int level, const vector<int>& stats) {
    if(level < 0)
        throw std::invalid_argument("level value must be positive");
    if(stats.size() < 4)
        throw std::invalid_argument("stats size length " + std::to_string(stats.size()) + " is less than the required stat amount");
    
    name = charName;
    lvl = level;
    
    for(int i = 0; i < stats.size(); i++) {
        this->stats.push_back(stats.at(i));
        tempStats.push_back(0);
    }
}