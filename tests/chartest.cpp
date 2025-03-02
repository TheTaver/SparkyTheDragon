#include <string>
#include <vector>
#include "gtest/gtest.h"

#include "Character.h"

using std::string;
using std::vector;

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