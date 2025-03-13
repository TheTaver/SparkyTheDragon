#include "gtest/gtest.h"
#include "EnemySubclasses.h"

TEST(CyberRatTest, TestGetAttackFunct){
    CyberRat cyberRat;
    int randSeed = 100;
    Attack theAttack = cyberRat.GetAttack(randSeed);
 
    EXPECT_EQ(theAttack.name, "Bite");
    EXPECT_EQ(theAttack.description, "");
    EXPECT_EQ(theAttack.baseAccuracy, 80);
    //numUses is random which is why it fails
    EXPECT_EQ(theAttack.numUses, 30);
    EXPECT_EQ(theAttack.maxUses, 30);
    EXPECT_EQ(theAttack.damage,3);
}

TEST(SecurityGaurdA, TestGetAttackwSeed){
    SecurityGaurdA securityGaurdA;
    int randSeed = 99;
    Attack attack1 = securityGaurdA.GetAttack(randSeed);

    EXPECT_EQ(attack1.name, "Chainsaw Stab");
    EXPECT_EQ(attack1.baseAccuracy, 85);
    EXPECT_EQ(attack1.damage, 7);
    EXPECT_EQ(attack1.numUses, 30);
    EXPECT_EQ(attack1.maxUses, 30);

    SecurityGaurdA securityGuardA2;
    int randSeedAgain = 100;
    Attack attack2 = securityGuardA2.GetAttack(randSeedAgain);

    EXPECT_EQ(attack2.name, "Chainsaw Slash");
    EXPECT_EQ(attack2.baseAccuracy, 90);
    EXPECT_EQ(attack2.damage, 9);
    EXPECT_EQ(attack2.numUses, 30);
    EXPECT_EQ(attack2.maxUses, 30);
}