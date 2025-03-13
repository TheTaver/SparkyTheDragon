#ifndef __NPCREADER_H__
#define __NPCREADER_H__
#include <fstream>
#include <stdexcept>

#include "npc.h"


class NPCReader {
    public:
        static vector<int> GetIntVecFromLine(const string& line);
    public:
        NPCReader() = delete;
        static NPC* GetEnemy(const string& npcFilename);
};

#endif