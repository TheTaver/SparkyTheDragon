#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player : public Character {
    private:
    // Player's xp
    int exp;

    // Player's inventory
    std::vector<int> inventory;
    
    public:

    // Added this cuz for the save and system (if we are trying)
    Player();

    // This is for new players
    Player(std::string name, std::string playerClass, int level, std::vector<int>& stats);

    // Returning Players and their saved items and xp
    Player(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory);

    // Destructor (still in progess)
    ~Player();

    // Our helper functions 
    bool canLevelUp();

    void levelUp(std::string stats);

    void addExp(int exp);

    void addItem(int itemType);

    int itemCount(int itemtype);

    bool useItem(int itemType);

};

#endif