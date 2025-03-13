#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

class Room {
    private:
    std::string description;
    std::string position;
    std::string choice;
    int numOptions;
    std::vector<std::string> optionText;
    bool hasCombat;

    public:
    Room(const std::string& position);

    std::string GetDescription() const;
    std::string GetChoice() const;
    int GetNumOptions() const;
    std::vector<std::string> GetOptions() const;
    bool HasCombat() const;
};

#endif