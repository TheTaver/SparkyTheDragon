#include "../header/Player.h"
#include <gtest/gtest.h>
#include <vector>

// Test default constructor
TEST(PlayerTest, DefaultConstructor) {
    Player p;
    EXPECT_EQ(p.GetName(), "");
    EXPECT_EQ(p.GetClass(), "Unknown");
    EXPECT_EQ(p.GetLevel(), 1);
    EXPECT_EQ(p.GetStat(0), 10);
    EXPECT_EQ(p.itemCount(1), 0);
}

// Test parameterized constructor
TEST(PlayerTest, ParameterizedConstructor) {
    std::vector<int> stats = {100, 10, 10, 10};
    Player p("Hero", "Brawler", 1, stats);

    EXPECT_EQ(p.GetName(), "Hero");
    EXPECT_EQ(p.GetClass(), "Brawler");
    EXPECT_EQ(p.GetLevel(), 1);
    EXPECT_EQ(p.GetStat(0), stats);
    EXPECT_EQ(p.itemCount(1), 0);
}

// Test adding experience and leveling up
TEST(PlayerTest, AddExpAndLevelUp) {
    std::vector<int> stats = {100, 10, 10, 10};
    Player p("Hero", "Brawler", 1, stats);

    p.addExp(100);
    EXPECT_TRUE(p.canLevelUp());

    p.levelUp("strength");

    EXPECT_EQ(p.GetLevel(), 2);
    EXPECT_FALSE(p.canLevelUp());
    EXPECT_EQ(p.GetStat(0), 12);  // Strength +2
}

// Test adding items and item count
TEST(PlayerTest, AddItemAndItemCount) {
    Player p;
    p.addItem(1);
    p.addItem(1);
    p.addItem(2);

    EXPECT_EQ(p.itemCount(1), 2);
    EXPECT_EQ(p.itemCount(2), 1);
    EXPECT_EQ(p.itemCount(3), 0);
}

// Test using items
TEST(PlayerTest, UseItem) {
    Player p;
    p.addItem(1);
    p.addItem(2);

    EXPECT_TRUE(p.useItem(1));
    EXPECT_EQ(p.itemCount(1), 0);
    EXPECT_FALSE(p.useItem(3));  // Item 3 was never added
}
