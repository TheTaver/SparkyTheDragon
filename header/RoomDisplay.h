#ifndef _ROOMDISPLAY_
#define _ROOMDISPLAY_

#include "Room.h"
#include "Character.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

class RoomDisplay {
public:
    std::string DisplayRoom(Room& room, Character& player, int currentHp);  
};

#endif
