#include "../header/Duelist.h"

Duelist::Duelist() : Player() {}

Duelist::Duelist(std::string name, std::string playerClass, int level, std::vector<int>& stats) 
: Player(name, playerClass, level, stats) {}

Duelist::Duelist(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) {}

Attack Duelist::GetLvlUpMove(int newLvl) {

    if(newLvl == 3) {
        return Attack("Piercing Thrust", "A thrust aimed at the weak spots", 90, 3, 3,
        15, 30, 3, -3); // Effect lower the enemy's agility by 3
    }

    else if(newLvl == 5) {
        return Attack("Blade Dance", "A rapid series of sword strikes", 85, 3, 3,
        20, 20, 2, -4); // Effect lower the enemy's defense by 4
    }

    else if(newLvl == 7) {
        return Attack("Parry Counter", "Parries and counters the next attack", 95, 3, 3,
        10, 0, 3, 3); // Effect increase the Player's defense by 3
    }
    else if(newLvl == 10) {
        return Attack("Finishing Blow", "A finishing strike", 70, 3, 3,
        30, 0, 0, 0);
    }

    // The player didn't reach the lvl yet
    return Attack();
    
}

