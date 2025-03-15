#include <iostream>
#include "CombatController.h"
#include "Duelist.h"
#include "CyberRat.h"

using namespace std;

int main() {
    vector<int> plyerStats = {20, 2, 4, 1};
    Duelist player("Stabby guy", "Duelist", 1, plyerStats);
    player.addItem(0);
    player.addItem(1);
    player.addItem(2);
    player.addItem(3);
    NPC* rat = new CyberRat();
    CombatController controller(&player, rat);
    controller.StartCombat();
    delete rat;
    
    return 0;
}