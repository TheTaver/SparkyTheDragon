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
    return Attack("Punch", false, 95, 20, 20, 5, 0, 0, 0);

    case 2: 
    return Attack("Sweep Kick", false, 90, 15, 15, 10, 0, 0, 0);

    case 3: 
    return Attack("Body Slam", false, 85, 10, 10, 15, 80, 3, -4);

    case 4: 
    return Attack("Ultimate Taijutsu Combo", false, 80, 5, 5, 20, 0, 0, 0);


    default:
    throw std::invalid_argument("Invalid level requested for attack: " + std::to_string(newLvl));
    }
}