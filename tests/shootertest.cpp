#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Shooter.h"
#include "Character.h"

using std::string;
using std::vector;

TEST(ShooterTest, GetLvlUpMove_Level1) {
    Shooter d;
    Attack move = d.GetLvlUpMove(1);
    EXPECT_EQ(move.name, "Gummo");
    EXPECT_EQ(move.damage, 10);
    EXPECT_EQ(move.baseAccuracy, 95);
}

TEST(ShooterTest, GetLvlUpMove_Level2) {
    Shooter d;
    Attack move = d.GetLvlUpMove(2);
    EXPECT_EQ(move.name, "Murder on My Mind");
    EXPECT_EQ(move.damage, 15);
    EXPECT_EQ(move.baseAccuracy, 90);
}

TEST(ShooterTest, GetLvlUpMove_Level3) {
    Shooter d;
    Attack move = d.GetLvlUpMove(3);
    EXPECT_EQ(move.name, "Ransom");
    EXPECT_EQ(move.damage, 20);
    EXPECT_EQ(move.baseAccuracy, 85);
}

TEST(ShooterTest, GetLvlUpMove_Level4) {
    Shooter d;
    Attack move = d.GetLvlUpMove(4);
    EXPECT_EQ(move.name, "No Auto");
    EXPECT_EQ(move.damage, 25);
    EXPECT_EQ(move.baseAccuracy, 90);
}

TEST(ShooterTest, GetLvlUpMove_InvalidLevel) {
    Shooter d;
    EXPECT_THROW(d.GetLvlUpMove(99), std::invalid_argument);
}

TEST(ShooterTest, ParameterizedConstructor) {
    vector<int> stats = {20, 0, 0, 0};
    vector<int> inv = {0, 1, 2, 3};
    string name = "Guns Garcia";
    Shooter d(name, "Shooter", 1, stats, 0, inv);
    EXPECT_EQ(d.GetName(), name);
    EXPECT_EQ(d.GetMoves().size(), 1);
}

TEST(ShooterTest, ParameterizedConstructor2) {
    vector<int> stats = {10, 5, 5, 5};
    Shooter d("Lil Glock", "Shooter", 1, stats);
    EXPECT_EQ(d.GetName(), "Lil Glock");
    EXPECT_EQ(d.GetMoves().size(), 1);
}

TEST(ShooterTest, AddExpAndLevelUp) {
    std::vector<int> stats = {20, 4, 2, 1};
    Shooter p("Hero", "Shooter", 1, stats);

    EXPECT_EQ(p.GetLevel(), 1);
    p.addExp(100);
    EXPECT_EQ(p.GetLevel(), 2);
    EXPECT_FALSE(p.canLevelUp());
    EXPECT_EQ(p.GetStat(1), 8);
}