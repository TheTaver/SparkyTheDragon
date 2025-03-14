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
    // Initialize currHp to maxHp
    currHp = stats.at(0);
}

int Character::GetStat(int statNum) const {
    return stats.at(statNum) + tempStats.at(statNum); // Effective stat amount, base + temp
}

const vector<int> Character::GetTempStats() const {
    return tempStats; // Effective stat amount, base + temp
}

void Character::DealDamage(int damageAmount) {
    if(damageAmount < 0) {
        throw std::invalid_argument("Damage Amount must be non-negative. Damage amount: "+damageAmount);
    }
    // Stats can be from 0-20 base (not counting temp)
    // 20 Defense takes 1/2 the damage compared to 0 defense
    double damageMultiplier = 1 - 0.5 * (GetStat(3) / 20.0); // Between 1 (0 Def) and 0.5 (20 Def) (inclusive)
    DealTrueDamage(std::floor(damageAmount * damageMultiplier));
}

void Character::DealTrueDamage(int damageAmount) {
    if(damageAmount < 0) {
        throw std::invalid_argument("Damage Amount must be non-negative. Damage amount: "+damageAmount);
    }
    // True damage ignores defense
    currHp-= damageAmount;
}

void Character::HealCharacter(int healAmount) {
    if(healAmount < 0) {
        throw std::invalid_argument("Heal Amount must be non-negative. Damage amount: "+healAmount);
    }
    
    currHp+=healAmount;
    
    // Check if went over maxHp:
    if(currHp > GetStat(0)) {
        currHp = GetStat(0);
    }
}

bool Character::IsDead() const {
    return (currHp <= 0);
}

void Character::TempChangeStat(int statNum, int change) {
    if(statNum >= 4) {
        throw std::invalid_argument("Invalid stat number: "+statNum);
    }
    tempStats.at(statNum)+= change;
    // If changing the maxHp
    if(statNum == 0) {
        // If increasing maxHp, also heal character for the same amount
        if(change > 0) {
            currHp += change;
        }
        // Make sure currHp isn't above the new max
        if(currHp > GetStat(0)) {
            currHp = GetStat(0);
        }
    }
}

void Character::ResetTempStat(int statNum) {
    tempStats.at(statNum) = 0;
    // If changing maxHp, make sure currHp doesn't go over its new max
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

void Character::AddMove(Attack newMove) {
    moves.push_back(newMove);
}