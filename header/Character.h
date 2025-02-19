#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include <string>
#include <vector>  // For attack vector
// #include "Attack.h"  // For attack vector

using std::string;
using std::vector;

class Character {
    private:
        string name;
        int lvl;

    protected:
        int currHp;
        vector<int> stats;     // [maxHp, strength, agility, defense]
        vector<int> tempStats;  // [maxHp, strength, agility, defense]
        // vector<Attack> moves;  // Need Attack class stub

    public:
        Character(const string& charName, int level, const vector<int>& stats);  // stats is 4 element int array
        // ~Character();  // Not needed since no "new" members

        const string& GetName() const { return name; };
        int GetLevel() const          { return lvl;  };

        int GetStat(int statNum) const;
        void TempChangeStat(int statNum, int change);
        void ResetTempStat(int statNum);
        void ResetAllTemp();
};
#endif