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
    Room();
    Room(const std::string& position);

    const std::string GetDescription() const;
    const std::string GetChoice() const;
    int GetNumOptions() const;
    const std::vector<std::string> GetOptions() const;
    bool HasCombat() const;
};

#endif