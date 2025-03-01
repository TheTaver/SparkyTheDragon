#ifndef ATTACK_H
#define ATTACK_H
#include <string>

class Character;

class Attack {
    
    private:
    int effectChance;
    int effectStat;
    int effect;

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

    Attack(std::string name, std::string description, int baseAccuracy, int numUses, int maxUses, 
        int damage, int effectChance, int effectStat, int effect);

    void hit(Character& attacker, Character& target, int randSeed);

};

#endif