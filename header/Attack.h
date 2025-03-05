#ifndef ATTACK_H
#define ATTACK_H
#include <string>

class Character;

class Attack {
    
    private:
    int effectChance;
    int effectStat;
    int effectAmount;

    bool doesItHit(Character& target, int randSeed);
    void applyEffect(Character& target, int randSeed);

    public: 
    
    std::string name; 
    std::string description;
    int baseAccuracy;
    int numUses;
    int maxUses;
    int damage;

    Attack();

    Attack(const std::string& name, const std::string& description, int baseAccuracy, int numUses, int maxUses, 
        int damage, int effectChance, int effectStat, int effectAmount);

    void hit(Character& attacker, Character& target, int randSeed);

};

#endif