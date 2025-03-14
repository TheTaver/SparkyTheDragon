#include "../header/brawler.h"
#include <stdexcept>
#include <vector>
#include <string>

using std::vector;
using std::string;

Brawler::Brawler() :Player() { moves.push_back(GetLvlUpMove(1)); }

Brawler::Brawler(const string& name, const string& playerClass, int level, vector<int>& stats) 
: Player(name, playerClass, level, stats) { moves.push_back(GetLvlUpMove(1)); }

Brawler::Brawler(const string& name, const string& playerClass, int level, vector<int>& stats, int exp, vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) { moves.push_back(GetLvlUpMove(1)); }

Attack Brawler::GetLvlUpMove(int newLvl) {

    switch(newLvl){
    case 1: 
    return Attack("Punch", "", 95, 0, 20, 10, 0, 0, 0);

    case 2: 
    return Attack("Sweep Kick", "", 90, 0, 15, 15, 0, 0, 0);

    case 3: 
    return Attack("Body Slam", "", 85, 0, 10, 20, 0, 0, 0);

    case 4: 
    return Attack("Ultimate Taijutsu Combo", "", 90, 0, 5, 25, 0, 0, 0);

    default:
    throw std::invalid_argument("Invalid level requested for attack: " + std::to_string(newLvl));
    
}
}