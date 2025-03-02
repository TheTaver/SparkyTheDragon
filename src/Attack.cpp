#include "Attack.h"
#include "Character.h"
#include "../header/Character.h"
#include <stdlib.h>

Attack::Attack() : name(""), description(0), baseAccuracy(0), numUses(0), maxUses(0), 
damage(0), effectChance(0), effectStat(-1), effect(0) {}

Attack::Attack(std::string name, std::string description, int baseAccuracy, int numUse, int maxUses, 
    int damage, int effectChance, int effectStat, int effect) : name(name), description(description), 
    baseAccuracy(baseAccuracy), numUses(numUses), maxUses(maxUses), damage(damage), effectChance(effectChance),
    effectStat(effectStat), effect(effect) {}


    // Check if the target get hit or not
bool Attack::doesItHit(Character& target, int randSeed) {
    int targetAgility = target.GetStat(2); // Target's agility makes it easier for them to dodge
    double dodgeChanceMultiplier = 1 + (targetAgility/20.0); // 20 agility => 2x miss chance at most

    srand(randSeed); // outputs the dfferent number every time so it doesnt output the same number
    int dodgeChance = rand() % 100; // which a number will return 0-99
    return (dodgeChance * dodgeChanceMultiplier)  < baseAccuracy; // if the baseAccuracy is greater then will hit and return true
    // => If dodgeChance is less than the accuracy, they failed to dodge the attack
    }

    // Check if the target gets a temp stat decrease
void Attack::applyEffect(Character& target, int randSeed) {
    srand(randSeed);
    int effectChanceHit = rand() % 100;

    // Check if the target will get the effect
    if(effectChanceHit < effectChance) {
        target.TempChangeStat(effectStat, effect); // if true the target will get effected temp
    } 

}

// The hit function 
void Attack::hit(Character& attacker, Character& target, int randSeed) {
    if(doesItHit(target, randSeed)) {
        target.DealDamage(damage); // Decrease the hp when the target after the hit

        // Attempts the to give the target an effect after the hit
        applyEffect(target, randSeed);
    }
}


