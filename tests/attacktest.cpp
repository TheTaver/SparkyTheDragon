#include <string>
#include <vector>
#include "gtest/gtest.h"

#include "Character.h"
#include "Attack.h"

using std::string;
using std::vector;

TEST(AttackTest, BasicNoDefNoAgiHit) {
    vector<int> stats = {20, 0, 0, 0};
    Character punchingBag("Test Dummy", 1, stats);
    Attack basicAttack("Basic Shot", "", 100, 30, 30, 10, 0, -1, 0);
    
    EXPECT_EQ(punchingBag.GetCurrHp(), stats.at(0));
    basicAttack.hit(punchingBag, punchingBag, 0); // Attacker strength not yet implemented
    EXPECT_EQ(punchingBag.GetCurrHp(), (stats.at(0) - 10));
}

TEST(AttackTest, TestDefaultConstructor) {
    EXPECT_NO_THROW(
        Attack basicAttack();
    );
}

TEST(AttackTest, TestModifyDefense) {
    vector<int> stats = {20, 0, 0, 0};
    Character punchingBag("Test Dummy", 1, stats);
    Attack reduceDef("Weakening Shot", "", 100, 30, 30, 10, 100, 2, -4);
    EXPECT_TRUE(reduceDef.hit(punchingBag, punchingBag, 0));
    EXPECT_EQ(punchingBag.GetStat(2), -4);
}

TEST(AttackTest, TestNoUses) {
    vector<int> stats = {20, 0, 0, 0};
    Character punchingBag("Test Dummy", 1, stats);
    Attack reduceDef("Weakening Shot", "", 100, 0, 1, 10, 100, 2, -4);
    EXPECT_FALSE(reduceDef.hit(punchingBag, punchingBag, 0));
    EXPECT_EQ(punchingBag.GetCurrHp(), 20);
}

TEST(AttackTest, TestMiss) {
    vector<int> stats = {20, 0, 0, 0};
    Character punchingBag("Test Dummy", 1, stats);
    Attack reduceDef("Weakening Shot", "", 0, 1, 1, 10, 100, 2, -4);
    EXPECT_FALSE(reduceDef.hit(punchingBag, punchingBag, 0));
    EXPECT_EQ(punchingBag.GetCurrHp(), 20);
}