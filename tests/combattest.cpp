#include <iostream>
#include "NPCReader.h"

using namespace std;

int main() {
    string enemyFile = "npcfiles/CyberRat.txt";
    NPC* rat = NPCReader::GetEnemy(enemyFile);

    cout << rat->GetDescription() << endl; 


    return 0;
}