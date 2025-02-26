#include <string>
#include <vector>
#include "gtest/gtest.h"

#include <ftxui/dom/elements.hpp>
#include "Character.h"

using std::string;
using std::vector;


TEST(FTX_Import, CreateElement) {
    EXPECT_NO_THROW( ftxui::Element testBox = ftxui::hbox({
        ftxui::text(L"Hello, World!") | ftxui::border | ftxui::bold
    }));
}

const int NUM_STATS = 4;

TEST(CharacterClass, ConstructReg) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
    }
    
    EXPECT_NO_THROW(
        Character reggie(name, level, stats);
        EXPECT_EQ(reggie.GetName(), name);
        EXPECT_EQ(reggie.GetLevel(), level);
    );
}

TEST(CharacterClass, NegativeLevel) {
    std::string name = "Reginald";
    int level = -1;
    vector<int> stats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
    }
    
    EXPECT_THROW(Character reggie(name, level, stats);, std::invalid_argument);
}

TEST(CharacterClass, NotEnoughStats) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < (NUM_STATS - 1); i++) {
        stats.push_back(i);
    }
    
    EXPECT_THROW(Character reggie(name, level, stats);, std::invalid_argument);
}

TEST(CharacterClass, GetStatNoTemp) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
    }
    Character reggie(name, level, stats);
    
    for(int i = 0; i < NUM_STATS; i++) {
        EXPECT_EQ(reggie.GetStat(i), stats.at(i));
    }
}

TEST(CharacterTempStats, OnePosChange) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
    }
    Character reggie(name, level, stats);
    reggie.TempChangeStat(2, 10);

    
    EXPECT_EQ(reggie.GetStat(2), 12);
    for(int i = 0; i < NUM_STATS; i++) {
        if(i != 2) {
            EXPECT_EQ(reggie.GetStat(i), stats.at(i));
        }
    }
}

TEST(CharacterTempStats, OneNegChange) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
    }
    Character reggie(name, level, stats);
    reggie.TempChangeStat(2, -10);

    
    EXPECT_EQ(reggie.GetStat(2), -8);
    for(int i = 0; i < NUM_STATS; i++) {
        if(i != 2) {
            EXPECT_EQ(reggie.GetStat(i), stats.at(i));
        }
    }
}

TEST(CharacterTempStats, AllPosChanges) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    vector<int> tempStats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
        tempStats.push_back(i);
    }
    Character reggie(name, level, stats);
    for(int i = 0; i < NUM_STATS; i++) {
        reggie.TempChangeStat(i, tempStats.at(i));
    }


    for(int i = 0; i < NUM_STATS; i++) {
        EXPECT_EQ(reggie.GetStat(i), (stats.at(i) + tempStats.at(i)));
    }
}

TEST(CharacterTempStats, AllNegChanges) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    vector<int> tempStats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
        tempStats.push_back(-i);
    }
    Character reggie(name, level, stats);
    for(int i = 0; i < NUM_STATS; i++) {
        reggie.TempChangeStat(i, tempStats.at(i));
    }


    for(int i = 0; i < NUM_STATS; i++) {
        EXPECT_EQ(reggie.GetStat(i), (stats.at(i) + tempStats.at(i)));
    }
}

TEST(CharacterTempStats, ResetOneChange) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
    }
    Character reggie(name, level, stats);
    reggie.TempChangeStat(2, 10);
    reggie.TempChangeStat(1, 5);

    
    EXPECT_EQ(reggie.GetStat(1), 6);
    EXPECT_EQ(reggie.GetStat(2), 12);
    
    reggie.ResetTempStat(2);
    
    EXPECT_EQ(reggie.GetStat(1), 6);
    EXPECT_EQ(reggie.GetStat(2), 2);

}

TEST(CharacterTempStats, ResetAllChanges) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    vector<int> tempStats;
    for(int i = 0; i < NUM_STATS; i++) {
        stats.push_back(i);
        tempStats.push_back(-i);
    }
    Character reggie(name, level, stats);
    for(int i = 0; i < NUM_STATS; i++) {
        reggie.TempChangeStat(i, tempStats.at(i));
    }
    
    for(int i = 0; i < NUM_STATS; i++) {
        EXPECT_EQ(reggie.GetStat(i), (stats.at(i) + tempStats.at(i)));
    }
    
    reggie.ResetAllTemp();

    for(int i = 0; i < NUM_STATS; i++) {
        EXPECT_EQ(reggie.GetStat(i), stats.at(i));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}