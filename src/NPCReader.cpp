#include <sstream>
#include <iostream>
#include "NPCReader.h"
#include "CyberRat.h"

using std::stringstream;

vector<int> NPCReader::GetIntVecFromLine(const string& line) {
    // Line is just ints separated by spaces
    stringstream lineStream(line);
    vector<int> intVector;

    int readInt;
    while(not lineStream.eof()) {
        
        lineStream >> readInt;
        if(not lineStream.fail()) {
            intVector.push_back(readInt);
        } else if(not lineStream.eof()) {
            throw std::runtime_error("Error reading line: " + line);
        }
    }
    return intVector;
}

NPC* NPCReader::GetEnemy(const string& npcFilename) {
    std::ifstream enemyFile(npcFilename);
    if(not enemyFile.is_open()) {
        throw std::runtime_error("File "+npcFilename+" unable to be opened.");
    }
    // File format (line by line):
    // Enemy Type
    // Enemy Level
    // Enemy Description
    // Enemy stats
    // Xp reward
    // Loot

    string enemyName;
    int enemyLevel;
    string enemyDescription;
    string statVectorInput;
    int enemyExpReward;
    string lootVectorInput;
    
    vector<int> enemyStats;
    getline(enemyFile, enemyName);
    enemyFile >> enemyLevel;
    getline(enemyFile, enemyDescription);  // Get rid of \n after enemy level
    getline(enemyFile, enemyDescription);
    getline(enemyFile, statVectorInput);
    enemyFile >> enemyExpReward;
    getline(enemyFile, lootVectorInput);  // Get rid of \n after xp
    getline(enemyFile, lootVectorInput);
    
    vector<int> statVector = GetIntVecFromLine(statVectorInput);
    vector<int> lootVector = GetIntVecFromLine(lootVectorInput);
    
    if(enemyName == "CyberRat") {
        return new CyberRat(enemyName, enemyLevel, enemyDescription, statVector, enemyExpReward, lootVector);
    }

    throw std::runtime_error("Unknown enemy type: " + enemyName);
}