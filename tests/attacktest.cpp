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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}