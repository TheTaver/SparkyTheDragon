#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <string>
#include <iostream>
#include "Room.h"
#include "Character.h"

class GameController {
    private:
        std::string position;

    public:
        GameController() : position("start") {}

        void SaveGame() {
            std::cout << "Saving game...\n";
        }

        Room LoadRoom(const std::string& position) {
            std::cout << "Loading room at position: " << position << "\n";
            return Room(position); 
        }

        void StartGameLoop() {
            std::cout << "Starting game loop...\n";
        }

        void EnterRoom(Character& player, Room& room) {
            std::cout << "Entering room: " << room.GetDescription() << "\n";
        }
};

#endif // GAMECONTROLLER_H
