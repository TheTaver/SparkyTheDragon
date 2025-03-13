#include <iostream>
#include "CombatController.h"
#include "NPCReader.h"
#include "Duelist.h"

using namespace std;

int main() {
    string enemyFile = "npcfiles/CyberRat.txt";
    vector<int> plyerStats = {20, 2, 4, 1};
    Duelist player("Stabby guy", "Duelist", 1, plyerStats);
    player.addItem(0);
    player.addItem(1);
    player.addItem(2);
    player.addItem(3);
    NPC* rat = NPCReader::GetEnemy(enemyFile);
    CombatController controller(&player, rat);
    controller.StartCombat();

    delete rat;
    return 0;
}