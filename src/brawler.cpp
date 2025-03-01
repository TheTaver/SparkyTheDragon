#include "brawler.h"

Attack Brawler::GetLvlUpMove(int newlvl){
    if (newlvl == 1){
        return Attack("Punch", "", 0, 0, 20, 5, 0, "", 0);
    }
    else if (newlvl == 2){
        return Attack("Slam", "", 0, 0, 20, 5, 0, "", 0);
    }
    else if (newlvl == 3){
        return Attack("Kick", "", 0, 0, 20, 5, 0, "", 0);
    }
    else if (newlvl == 4){
        return Attack("", "", 0, 0, 20, 5, 0, "", 0);
    }
    else{
        return throw
    }
}