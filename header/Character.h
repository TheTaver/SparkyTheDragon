#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "Attack.h"
#include <string>
#include <vector>  // For attack/stats vectors

using std::string;
using std::vector;

class Character {
    private:
        string name;
        
    protected:
        int lvl;
        int currHp;
        vector<int> stats;     // [maxHp, strength, agility, defense]
        vector<int> tempStats;  // [maxHp, strength, agility, defense]
        vector<Attack> moves;  // Moves available to the player in combat

    public:
        Character(const string& charName, int level, const vector<int>& stats);  // stats is 4 element int array
        // ~Character();  // Not needed since no "new" members

        const string& GetName() const { return name; };
        int GetLevel() const          { return lvl;  };
        int GetCurrHp() const         { return currHp;  };
        
        int GetStat(int statNum) const;
        const vector<int> GetTempStats() const;
        void TempChangeStat(int statNum, int change);
        void ResetTempStat(int statNum);
        void ResetAllTemp();

        void DealDamage(int damageAmount);
        void DealTrueDamage(int damageAmount); // Ignores defense stat
        void HealCharacter(int healAmount);
        bool IsDead() const;

        const vector<Attack> GetMoves() const;
        void AddMove(Attack newMove);
};
#endif