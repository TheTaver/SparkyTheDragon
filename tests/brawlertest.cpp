#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "brawler.h"
#include "Character.h"

using std::string;
using std::vector;

TEST(BrawlerTest, GetLvlUpMove_Level1) {
    Brawler d;
    Attack move = d.GetLvlUpMove(1);
    EXPECT_EQ(move.name, "Punch");
    EXPECT_EQ(move.damage, 10);
    EXPECT_EQ(move.baseAccuracy, 95);
}

TEST(BrawlerTest, GetLvlUpMove_Level2) {
    Brawler d;
    Attack move = d.GetLvlUpMove(2);
    EXPECT_EQ(move.name, "Sweep Kick");
    EXPECT_EQ(move.damage, 15);
    EXPECT_EQ(move.baseAccuracy, 90);
}

TEST(BrawlerTest, GetLvlUpMove_Level3) {
    Brawler d;
    Attack move = d.GetLvlUpMove(3);
    EXPECT_EQ(move.name, "Body Slam");
    EXPECT_EQ(move.damage, 20);
    EXPECT_EQ(move.baseAccuracy, 85);
}

TEST(BrawlerTest, GetLvlUpMove_Level4) {
    Brawler d;
    Attack move = d.GetLvlUpMove(4);
    EXPECT_EQ(move.name, "Ultimate Taijutsu Combo");
    EXPECT_EQ(move.damage, 25);
    EXPECT_EQ(move.baseAccuracy, 90);
}

TEST(BrawlerTest, GetLvlUpMove_InvalidLevel) {
    Brawler d;
    EXPECT_THROW(d.GetLvlUpMove(99), std::invalid_argument);
}

TEST(BrawlerTest, ParameterizedConstructor2) {
    vector<int> stats = {20, 0, 0, 0};
    vector<int> inv = {0, 1, 2, 3};
    string name = "Sir Garner";
    Brawler d(name, "Brawler", 1, stats, 0, inv);
    EXPECT_EQ(d.GetName(), name);
    EXPECT_EQ(d.GetMoves().size(), 1);
}