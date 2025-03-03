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
<<<<<<< HEAD
int Character::GetStat(int statNum) const {
    return stats.at(statNum) + tempStats.at(statNum);
}
void Character::TempChangeStat(int statNum, int change) {
    tempStats.at(statNum)+= change;
}
void Character::ResetTempStat(int statNum) {
    tempStats.at(statNum) = 0;
}
=======

int Character::GetStat(int statNum) const {
    return stats.at(statNum) + tempStats.at(statNum);
}

void Character::TempChangeStat(int statNum, int change) {
    tempStats.at(statNum)+= change;
}

void Character::ResetTempStat(int statNum) {
    tempStats.at(statNum) = 0;
}

>>>>>>> master
void Character::ResetAllTemp() {
    for(int i = 0; i < tempStats.size(); i++) {
        ResetTempStat(i);
    }
}
<<<<<<< HEAD
// const vector<Attack> GetMoves() const {
//     return moves;
// }
=======

// const vector<Attack> GetMOves() const {
//     return moves;
// }

>>>>>>> master
// void AddMove(const Attack& newMove) {
//     moves.push_back(newMove);
// }