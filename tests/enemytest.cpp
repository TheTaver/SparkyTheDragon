#include "gtest/gtest.h"
#include "EnemySubclasses.h"

//CyberRat
TEST(CyberRatTest, TestGetAttackFunct){
    vector<int> stats = {5,5,5};
    CyberRat cyberRat("CyberRat", 1, stats);
    int randSeed = 100;
    Attack theAttack = cyberRat.GetAttack(randSeed);

    EXPECT_EQ(theAttack.name, "Bite");
    EXPECT_EQ(theAttack.description, "Bites your feet! Doesn't do much damage");
    EXPECT_EQ(theAttack.damage, 5);
    EXPECT_EQ(theAttack.baseAccuracy, 100);
    EXPECT_EQ(theAttack.numUses, 0);
    EXPECT_EQ(theAttack.maxUses, 100);
}

/*class MockChar : public Character{
    public:
    MOCK_METHOD(
}*/
//the stub
