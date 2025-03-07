#ifndef __CYBERRAT_H__
#define __CYBERRAT_H__

#include "npc.h"

class CyberRat : public NPC {
    private:

    public:
        CyberRat() :
            NPC("CyberRat", 1,
            "The CyberRat is a mechanical scavenger, searching the abandoned factory for scraps of metal and energy to consume.",
            {25, 0, 0, 0}, 100, {3, 1, 0, 0})
            {};
        Attack GetAttack(int seed) override {
            return Attack("Bite", "", 80, 30, 30, 25, 0, -1, 0);
        }

};
#endif