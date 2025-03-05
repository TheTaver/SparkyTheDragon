#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Player.h"
#include "Duelist.h"
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

// Player test cases


TEST(DuelistTest, DefaultConstructor) {
    Duelist p;
    EXPECT_EQ(p.GetName(), "");
    EXPECT_EQ(p.GetLevel(), 1);
    EXPECT_EQ(p.GetStat(0), 100);
    EXPECT_EQ(p.itemCount(1), 0);
}

// Test Parameterized Constructor
TEST(DuelistTest, ParameterizedConstructor) {
    std::vector<int> stats = {100, 10, 10, 10};
    Duelist p("Hero", "Duelist", 1, stats);

    EXPECT_EQ(p.GetName(), "Hero");
    EXPECT_EQ(p.GetLevel(), 1);
    EXPECT_EQ(p.GetStat(0), stats.at(0));
    EXPECT_EQ(p.itemCount(1), 0);
}

// Test Add Experience and Level Up
TEST(DuelistTest, AddExpAndLevelUp) {
    std::vector<int> stats = {100, 10, 10, 10};
    Duelist p("Hero", "Duelist", 1, stats);

    p.addExp(100);
    EXPECT_TRUE(p.canLevelUp());

    p.levelUp("strength");
    EXPECT_EQ(p.GetLevel(), 2);
    EXPECT_FALSE(p.canLevelUp());
    EXPECT_EQ(p.GetStat(1), 12);
}

// Test Add Item and Item Count
TEST(DuelistTest, AddItemAndItemCount) {
    Duelist p;
    p.addItem(1);
    p.addItem(1);
    p.addItem(2);

    EXPECT_EQ(p.itemCount(1), 2);
    EXPECT_EQ(p.itemCount(2), 1);
    EXPECT_EQ(p.itemCount(3), 0);
}

// Test Use Item
TEST(DuelistTest, UseItem) {
    Duelist p;
    p.addItem(1);
    p.addItem(2);

    EXPECT_TRUE(p.useItem(1));
    EXPECT_EQ(p.itemCount(1), 0);
    EXPECT_FALSE(p.useItem(3));
}


// New test cases for the duelist
TEST(DuelistTest, GetLvlUpMove_Level1) {
    Duelist d;
    Attack move = d.GetLvlUpMove(1);
    EXPECT_EQ(move.name, "Quick Slash");
    EXPECT_EQ(move.damage, 10);
    EXPECT_EQ(move.baseAccuracy, 95);
}

TEST(DuelistTest, GetLvlUpMove_Level2) {
    Duelist d;
    Attack move = d.GetLvlUpMove(2);
    EXPECT_EQ(move.name, "Piercing Thrust");
    EXPECT_EQ(move.damage, 15);
    EXPECT_EQ(move.baseAccuracy, 90);
}

TEST(DuelistTest, GetLvlUpMove_Level3) {
    Duelist d;
    Attack move = d.GetLvlUpMove(3);
    EXPECT_EQ(move.name, "Blade Dance");
    EXPECT_EQ(move.damage, 20);
    EXPECT_EQ(move.baseAccuracy, 85);
}

TEST(DuelistTest, GetLvlUpMove_Level4) {
    Duelist d;
    Attack move = d.GetLvlUpMove(4);
    EXPECT_EQ(move.name, "Master Parry");
    EXPECT_EQ(move.damage, 25);
    EXPECT_EQ(move.baseAccuracy, 90);
}

TEST(DuelistTest, GetLvlUpMove_InvalidLevel) {
    Duelist d;
    EXPECT_THROW(d.GetLvlUpMove(99), std::invalid_argument);
}