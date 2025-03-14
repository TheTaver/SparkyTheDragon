#include "../header/brawler.h"
#include <stdexcept>

Attack Brawler::GetLvlUpMove(int newlvl){
    if (newlvl == 1){
        return Attack("Punch", false, 0, 0, 20, 5, 0, 0, 0);
    }
    else if (newlvl == 2){
        return Attack("Sweep Kick", false, 0, 0, 15, 10, 0, 0, 0);
    }
    else if (newlvl == 3){
        return Attack("Body Slam", false, 0, 0, 10, 15, 0, 0, 0);
    }
    else if (newlvl == 4){
        return Attack("Ultimate Taijutsu Combo", false, 0, 0, 5, 20, 0, 0, 0);
    }
    else{
        throw std::invalid_argument("cant lvl up more than 4 times");
    }
}