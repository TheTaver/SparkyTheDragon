#include "../header/Shooter.h"
#include "gtest/gtest.h"
#include <stdexcept>
#include <vector>

using std::vector;

TEST(ShooterTest, DefaultConstructor) {
    Shooter player;
    EXPECT_EQ(player.GetStat(1), 10);
}

TEST(ShooterTest, ParameterizedConstructor) {
    vector<int> stats = {90, 12, 15, 8};
    Shooter player("Joe", "Shooter", 1, stats);

    EXPECT_EQ(player.GetStat(0), 90); 
    EXPECT_EQ(player.GetStat(1), 12);
    EXPECT_EQ(player.GetStat(2), 15);
    EXPECT_EQ(player.GetStat(3), 8);
}

TEST(ShooterTest, GetLvlUpMove_ValidLevels) {
    Shooter player;

    Attack lvl1Move = player.GetLvlUpMove(1);
    EXPECT_EQ(lvl1Move.name, "Gummo");
    EXPECT_EQ(lvl1Move.damage, 10);

    Attack lvl2Move = player.GetLvlUpMove(2);
    EXPECT_EQ(lvl2Move.name, "Murder on My Mind");
    EXPECT_EQ(lvl2Move.damage, 15);

    Attack lvl3Move = player.GetLvlUpMove(3);
    EXPECT_EQ(lvl3Move.name, "Ransom");
    EXPECT_EQ(lvl3Move.damage, 20);

    Attack lvl4Move = player.GetLvlUpMove(4);
    EXPECT_EQ(lvl4Move.name, "No Auto");
    EXPECT_EQ(lvl4Move.damage, 25);
}

TEST(ShooterTest, GetLvlUpMove_InvalidLevel) {
    Shooter player;

    EXPECT_THROW(player.GetLvlUpMove(5), std::invalid_argument);
    EXPECT_THROW(player.GetLvlUpMove(-1), std::invalid_argument);
    EXPECT_THROW(player.GetLvlUpMove(10), std::invalid_argument);
}
