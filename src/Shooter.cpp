#include "../header/Shooter.h"
#include <stdexcept>
#include <vector>
#include <string>

using std::vector;
using std::string;

Shooter::Shooter() :Player() {}

Shooter::Shooter(const string& name, const string& playerClass, int level, vector<int>& stats) 
: Player(name, playerClass, level, stats) {}

Shooter::Shooter(const string& name, const string& playerClass, int level, vector<int>& stats, int exp, vector<int>& inventory) 
: Player(name, playerClass, level, stats, exp, inventory) {}

Attack Shooter::GetLvlUpMove(int newLvl) {

    switch(newLvl){
    case 1: 
    return Attack("Gummo", "Pull up with the stick and let it hit: A single, quick damage shotgun attack.", 95, 5, 5, 10, 0, 0, 0);

    case 2: 
    return Attack("Murder on My Mind", "I wake up in the morning, I got murder on my mind: A charged up attack that does extra damage if prepared in advance.", 90, 3, 3, 15, 30, 3, -3);

    case 3: 
    return Attack("Ransom", "I got two twin Glocks, turn you to a dancer: A rapid series of shots from dual wield pistols.", 85, 3, 3, 20, 20, 2, -4);

    case 4: 
    return Attack("No Auto", "Glock so big, gotta hold it with two hands: A heavy single shot attack with a powerful pistol.", 90, 2, 2, 25, 50, 3, -5);

    default:
    throw std::invalid_argument("Invalid level requested for attack: " + std::to_string(newLvl));
    
}
}
