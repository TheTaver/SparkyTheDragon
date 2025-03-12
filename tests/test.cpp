#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "Player.h"
#include "../header/Shooter.h"

#include <ftxui/dom/elements.hpp>
#include "Character.h"

using std::string;
using std::vector;


TEST(FTX_Import, CreateElement) {
    EXPECT_NO_THROW( ftxui::Element testBox = ftxui::hbox({
        ftxui::text(L"Hello, World!") | ftxui::border | ftxui::bold
    }));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Player test cases

TEST(DuelistTest, DefaultConstructor) {
    Shooter p;
    EXPECT_EQ(p.GetName(), "");
    EXPECT_EQ(p.GetLevel(), 1);
    EXPECT_EQ(p.GetStat(0), 100);
    EXPECT_EQ(p.itemCount(1), 0);
}

// Test Parameterized Constructor
TEST(DuelistTest, ParameterizedConstructor) {
    std::vector<int> stats = {100, 10, 10, 10};
    Shooter p("Hero", "Duelist", 1, stats);

    EXPECT_EQ(p.GetName(), "Hero");
    EXPECT_EQ(p.GetLevel(), 1);
    EXPECT_EQ(p.GetStat(0), stats.at(0));
    EXPECT_EQ(p.itemCount(1), 0);
}

// Test Add Experience and Level Up
TEST(DuelistTest, AddExpAndLevelUp) {
    std::vector<int> stats = {100, 10, 10, 10};
    Shooter p("Hero", "Duelist", 1, stats);

    p.addExp(100);
    EXPECT_TRUE(p.canLevelUp());

    p.levelUp("strength");
    EXPECT_EQ(p.GetLevel(), 2);
    EXPECT_FALSE(p.canLevelUp());
    EXPECT_EQ(p.GetStat(1), 12);
}

// Test Add Item and Item Count
TEST(DuelistTest, AddItemAndItemCount) {
    Shooter p;
    p.addItem(1);
    p.addItem(1);
    p.addItem(2);

    EXPECT_EQ(p.itemCount(1), 2);
    EXPECT_EQ(p.itemCount(2), 1);
    EXPECT_EQ(p.itemCount(3), 0);
}

// Test Use Item
TEST(DuelistTest, UseItem) {
    Shooter p;
    p.addItem(1);
    p.addItem(2);

    EXPECT_TRUE(p.useItem(1));
    EXPECT_EQ(p.itemCount(1), 0);
    EXPECT_FALSE(p.useItem(3));
}