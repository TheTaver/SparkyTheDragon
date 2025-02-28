#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <vector>  // For attack/stats vectors
// #include "Attack.h"  // For attack vector

using std::string;
using std::vector;

class Character {
    private:
        string name;
        string charClass;
        
    protected:
        int lvl;
        int currHp;
        vector<int> stats;     // [maxHp, strength, agility, defense]
        vector<int> tempStats;  // [maxHp, strength, agility, defense]
        // vector<Attack> moves;  // Need Attack class stub

    public:
        Character(const string& charName, const string& charClass, int level, const vector<int>& stats);  // stats is 4 element int array
        // ~Character();  // Not needed since no "new" members

        const string& GetName() const { return name; };
        const string& GetClass() const { return charClass; }
        int GetLevel() const          { return lvl;  };

        int GetStat(int statNum) const;
        void TempChangeStat(int statNum, int change);
        void ResetTempStat(int statNum);
        void ResetAllTemp();

        // const vector<Attack> GetMoves() const;
        // void AddMove(const Attack&);
};
#endif