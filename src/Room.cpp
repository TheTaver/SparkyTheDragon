#include "../header/Room.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Room::Room(const std::string& filename)
: numOptions(0), hasCombat(false) {
    
    std::ifstream file(filename);
    if(!file.is_open()) {
        throw std::runtime_error("Failed to open room file");
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

    // Read number of options
    if (!(file >> numOptions)) {
        throw std::runtime_error("Error reading number of options");
    }
    file.ignore();

    optionText.clear();
    for (int i = 0; i < numOptions; ++i) {
        std::string option;
        if (!std::getline(file, option)) {
            throw std::runtime_error("Error reading option " + std::to_string(i + 1));
        }
        optionText.push_back(option);
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

std::string Room::GetDescription() const {
    return description;
}

std::string Room::GetChoice() const {
    return choice;
}

int Room::GetNumOptions() const {
    return numOptions;
}

std::vector<std::string> Room::GetOptions() const {
    return optionText;
}

bool Room::HasCombat() const {
    return hasCombat;
}