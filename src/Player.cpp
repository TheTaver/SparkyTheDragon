#include "../header/Player.h"

#include <cmath>
#include <vector>
#include <algorithm>

// Call the character which have an empty name "", level 1, the default stat(idk how you guys want it)
//  Temp starting stats (hp 100, 10, 10, 10)
Player::Player() 
: Character("",  1, std::vector<int>{100, 10, 10, 10}), exp(0), inventory({}) {}


// For the new players when start fresh
Player::Player(std::string name, std::string playerClass, int level, std::vector<int>& stats) 
: Character(name, level, stats), exp(0), inventory({}) {}

// For returning players
Player::Player(std::string name, std::string playerClass, int level, std::vector<int>& stats, int exp, std::vector<int>& inventory) 
: Character(name, level, stats), exp(exp), inventory(inventory) {}


// no deconstructor needed

// to check if they can level up
bool Player::canLevelUp() {
    int requiredExp = static_cast<int>(100 * pow(expMult, lvl - 1)); // checking if they level up
    return exp >= requiredExp; // return true if this is true
}

// Leveling up the player
void Player::levelUp(std::string stats) {
    while(canLevelUp) // if this true then it will go on this loop
    {
        // change the required xp to up x1.5 (can be change later you guys want to)
       int requiredExp = static_cast<int>(100 * pow(expMult, lvl - 1));

       exp -= requiredExp; // Substract the the current xp with the required xp
       lvl++; // level up :)


       // The choices of what stat can the player upgrade (idk how much you guy the stat to be upgrade)
       if(stats == "strength") {
        this->stats[0] += 2; 

       } else if(stats == "maxHP"){
        this->stats[1] += 2;

       } else if (stats == "agility") {
        this->stats[2] += 2;

       } else if (stats == "defense") {
        this->stats[3] += 2;

       }
    }
}


// get the xp
void Player::addExp(int amount) {
    exp += amount;

}

// add item to the inventory
void Player::addItem(int itemType) {
    inventory.push_back(itemType);

}

// get the count of the item type
int Player::itemCount(int itemType) {
    int count = 0;

    for (int item : inventory) {
        if (item == itemType) count ++;
    }

    return count;
}


bool Player::useItem(int itemType) {
    auto it = std::find(inventory.begin(), inventory.end(), itemType);
    if (it != inventory.end()) { 
        inventory.erase(it);
        return true;
    }
    return false;

}