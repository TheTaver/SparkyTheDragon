#include "Room.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Room::Room() 
: position("Unknown"), description("Empty room"), choice("None"), numOptions(0), hasCombat(false) {}

Room::Room(const std::string& filename)
: numOptions(0), hasCombat(false) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open room file: " + filename);
    }

    if (!std::getline(file, position)) {
        throw std::runtime_error("Error reading position");
    }

    if (!std::getline(file, description)) {
        throw std::runtime_error("Error reading description");
    }

    if (!std::getline(file, choice)) {
        throw std::runtime_error("Error reading choice");
    }

    if (!(file >> numOptions)) {
        throw std::runtime_error("Error reading number of options");
    }
    file.ignore();

    optionText.clear();
    nextRooms.clear();

    for (int i = 0; i < numOptions; ++i) {
        std::string option;
        if (!std::getline(file, option)) {
            throw std::runtime_error("Error reading option " + std::to_string(i + 1));
        }
        optionText.push_back(option);
    }

    for (int i = 0; i < numOptions; ++i) {
        std::string roomPath;
        if (!std::getline(file, roomPath)) {
            throw std::runtime_error("Error reading next room path for choice " + std::to_string(i + 1));
        }
        nextRooms.push_back(roomPath);
    }

    int combatValue = 0;
    if (!(file >> combatValue)) {
        throw std::runtime_error("Error reading hasCombat");
    }
    hasCombat = (combatValue == 1);

    if (file.fail() && !file.eof()) {
        throw std::runtime_error("Error while reading file: " + filename);
    }

    file.close();
}

// ✅ Implement missing functions
const std::string& Room::GetDescription() const {
    return description;
}

const std::vector<std::string>& Room::GetOptions() const {
    return optionText;
}
