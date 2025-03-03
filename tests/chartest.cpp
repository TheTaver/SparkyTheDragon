#include <string>
#include <vector>
#include "gtest/gtest.h"

#include "Character.h"

using std::string;
using std::vector;


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

TEST(DealDamageTest, NoDefense) {
    vector<int> stats = {20, 0, 0, 0}; // 0% Damage Reduction
    Character punchingBag("Test Dummy", 1, stats);

    EXPECT_EQ(punchingBag.GetCurrHp(), stats.at(0));
    punchingBag.DealDamage(5);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 5));
    punchingBag.DealDamage(10);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 15));
}

TEST(DealDamageTest, Base20Defense) {
    vector<int> stats = {20, 0, 0, 20}; // 50% Damage Reduction
    Character punchingBag("Test Dummy", 1, stats);

    EXPECT_EQ(punchingBag.GetCurrHp(), stats.at(0));
    punchingBag.DealDamage(5);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 2));
    punchingBag.DealDamage(10);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 7));
}

TEST(DealDamageTest, Base10Defense) {
    vector<int> stats = {20, 0, 0, 10}; // 25% Damage Reduction
    Character punchingBag("Test Dummy", 1, stats);

    EXPECT_EQ(punchingBag.GetCurrHp(), stats.at(0));
    punchingBag.DealDamage(5);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 3));
    punchingBag.DealDamage(10);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 10));
}

TEST(DealDamageTest, Temp20Defense) {
    vector<int> stats = {20, 0, 0, 0};
    Character punchingBag("Test Dummy", 1, stats);
    punchingBag.TempChangeStat(3, 20); // 50% Damage Reduction
    
    EXPECT_EQ(punchingBag.GetCurrHp(), stats.at(0));
    punchingBag.DealDamage(5);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 2));
    punchingBag.DealDamage(10);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 7));
}

TEST(DealDamageTest, Temp10Defense) {
    vector<int> stats = {20, 0, 0, 0};
    Character punchingBag("Test Dummy", 1, stats);
    punchingBag.TempChangeStat(3, 10); // 25% Damage Reduction

    EXPECT_EQ(punchingBag.GetCurrHp(), stats.at(0));
    punchingBag.DealDamage(5);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 3));
    punchingBag.DealDamage(10);
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 10));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}