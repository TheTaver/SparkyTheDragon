#include "Character.h"
#include "Attack.h"
#include <stdexcept>
#include <cmath>

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
    currHp = stats.at(0);
}

int Character::GetStat(int statNum) const {
    return stats.at(statNum) + tempStats.at(statNum);
}

void Character::DealDamage(int damageAmount) {
    // Stats can be from 0-20 base (not counting temp)
    // 20 Defense takes 1/2 the damage compared to 0 defense
    double damageMultiplier = 1 - 0.5 * (GetStat(3) / 20);
    currHp-= std::floor(damageAmount * damageMultiplier);
}

void Character::TempChangeStat(int statNum, int change) {
    tempStats.at(statNum)+= change;
    if(statNum == 0) {
        if(GetStat(0) < currHp) {
            currHp = GetStat(0);
        }
    }
}

void Character::ResetTempStat(int statNum) {
    tempStats.at(statNum) = 0;
    // If changing maxHp, make sure currHp doesn't go over
    if(statNum == 0) {
        if(currHp > GetStat(0)) {
            currHp = GetStat(0);
        }
    }
}

void Character::ResetAllTemp() {
    for(int i = 0; i < tempStats.size(); i++) {
        ResetTempStat(i);
    }
}

const vector<Attack> Character::GetMoves() const {
    return moves;
}

void Character::AddMove(const Attack& newMove) {
    if(moves.size() >= 4)
        throw std::invalid_argument("Max of 4 moves allowed");
    moves.push_back(newMove);
}