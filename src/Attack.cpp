#include "../header/Attack.h"
#include "../header/Character.h"
#include <stdlib.h>
#include <iostream>

Attack::Attack() : name(""), description(""), baseAccuracy(0), numUses(0), maxUses(0), 
damage(0), effectChance(0), effectStat(0), effectAmount(0) {}

Attack::Attack(const std::string& name, const std::string& description, int baseAccuracy, int numUses, int maxUses, 
    int damage, int effectChance, int effectStat, int effectAmount) : name(name), description(description), 
    baseAccuracy(baseAccuracy), numUses(numUses), maxUses(maxUses), damage(damage), effectChance(effectChance),
    effectStat(effectStat), effectAmount(effectAmount) {}


    // Check if the target get hit or not
bool Attack::doesItHit(Character& target, int randSeed) {
    srand(randSeed); // outputs the dfferent number every time so it doesnt output the same number

    int hitChance = rand() % 100; // which a number will return 0-99
    return hitChance < baseAccuracy; // if the baseAccuracy is greater then will hit and return true

    }

    // Check if the target gets a temp stat decrease
void Attack::applyEffect(Character& target, int randSeed) {
    srand(randSeed);
    int effectChanceHit = (rand() % 100) + 1;  
    
    if (effectChanceHit <= effectChance) {
        target.TempChangeStat(effectStat, effectAmount);
    }
    
}

// The hit function 
void Attack::hit(Character& attacker, Character& target, int randSeed) {
    if (numUses <= 0) {
        std::cout << name << " has no uses left!\n";
        return;
    }

    numUses--;

if (doesItHit(target, randSeed)) {
    std::cout << name << " hits for " << damage << " damage!\n";

 
    target.DealDamage(damage); // Decrease the hp when the target after the hit
    applyEffect(target, randSeed);
} else {
    std::cout << name << " missed!\n";
}

}
