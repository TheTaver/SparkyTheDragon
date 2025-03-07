#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Duelist.h"
#include "Character.h"

using std::string;
using std::vector;

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