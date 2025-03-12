#ifndef _ROOMDISPLAY_
#define _ROOMDISPLAY_

#include "Room.h"
#include "Character.h"
#include <string>
#include <iostream>
#include <vector>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

class RoomDisplay {
    public: 
    std::string  DisplayRoom(Room room, Character player);
    
};


#endif