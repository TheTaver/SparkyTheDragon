#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

class Room {
private:
    std::string position;
    std::string description;
    std::string choice;
    int numOptions;
    bool hasCombat;
    std::vector<std::string> optionText;
    std::vector<std::string> nextRooms;

public:
    Room();
    Room(const std::string& filename);

    const std::string& GetDescription() const;  
    const std::vector<std::string>& GetOptions() const;
    int GetNumOptions() const { return numOptions; }
    bool HasCombat() const { return hasCombat; }
    std::string GetNextRoom(int choice) const { return nextRooms[choice]; }
};

#endif
