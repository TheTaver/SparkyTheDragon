#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__
#include <string>
#include "MenuDisplay.h"
#include "CombatInfoDisplay.h"
#include "CombatUI.h"
#include "CombatController.h"
#include "Duelist.h"
#include "brawler.h"
#include "Shooter.h"
#include "CyberRat.h"
#include "SecurityGaurdA.h"
#include "SecurityGaurdB.h"
#include "Sparky.h"
#include <ftxui/component/screen_interactive.hpp>
#include <vector>
#include "Player.h"
#include "Room.h"
#include <fstream>

using namespace std;

class GameController {
    public:
    string position;

    void SaveGame(NPC* enemy, Player*& thePlayer,string position);
    Room LoadRoom(string position);
    Player* MakeCharacter(string theInput);
    void StartGameLoop();
    void EnterRoom(Player* thePlayer, Room room);
    bool DoCombat(NPC* enemy, Player* thePlayer);
};

#endif