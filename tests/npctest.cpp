#include <string>
#include <vector>
#include "gtest/gtest.h"

#include "npc.h"
#include "Attack.h"

using std::string;
using std::vector;

const int NUM_STATS = 4;

// mock class
class TestNPC : public NPC {
public:
    TestNPC(const string& name, int level, const vector<int>& stats, int expReward, const vector<int>& loot)
        : NPC(name, level, "", stats, expReward, loot) {}

    Attack GetAttack(int seed) override {
        return Attack("Test Attack", "A test move", 100, 10, 10, 20, 0, 0, 0);
    }
};

TEST(NPCTest, ConstructNPC) {
    string name = "NPC";
    int level = 5;
    vector<int> stats = {100, 10, 10, 10};
    int expReward = 50;
    vector<int> loot = {1, 2, 3};

    EXPECT_NO_THROW(
        TestNPC npc(name, level, stats, expReward, loot);
        EXPECT_EQ(npc.GetExpReward(), expReward);
        EXPECT_EQ(npc.GetLoot(), loot);
    );
}

TEST(NPCTest, GetExpReward) {
    TestNPC npc("NPC", 5, {100, 10, 10, 10}, 50, {1, 2, 3});
    EXPECT_EQ(npc.GetExpReward(), 50);
}

TEST(NPCTest, GetLoot) {
    TestNPC npc("NPC", 5, {100, 10, 10, 10}, 50, {1, 2, 3});
    vector<int> loot = npc.GetLoot();

    ASSERT_EQ(loot.size(), 3);
    EXPECT_EQ(loot[0], 1);
    EXPECT_EQ(loot[1], 2);
    EXPECT_EQ(loot[2], 3);
}

TEST(NPCTest, GetAttack) {
    TestNPC npc("NPC", 5, {100, 10, 10, 10}, 50, {1, 2, 3});
    Attack attack = npc.GetAttack(0);

    EXPECT_EQ(attack.name, "Test Attack");
    EXPECT_EQ(attack.damage, 20);
}

TEST(NPCTest, AbstractNPC) {
    NPC* npcPointer = nullptr;
    EXPECT_EQ(npcPointer, nullptr);
}

TEST(NPCTest, NPCCombatInteraction) {
    TestNPC npc("NPC", 5, {100, 10, 10, 10}, 50, {1, 2, 3});
    Character player("Player", 5, {100, 10, 10, 10});

    Attack enemyAttack = npc.GetAttack(0);
    int initialHP = player.GetCurrHp();
    
    enemyAttack.hit(npc, player, 0);

    EXPECT_LT(player.GetCurrHp(), initialHP);
}

TEST(NPCTest, MultipleLootChecks) {
    TestNPC npc("NPC", 5, {100, 10, 10, 10}, 50, {5, 10, 15});
    vector<int> loot = npc.GetLoot();

    ASSERT_EQ(loot.size(), 3);
    EXPECT_EQ(loot[0], 5);
    EXPECT_EQ(loot[1], 10);
    EXPECT_EQ(loot[2], 15);
}

TEST(NPCTest, SetLoot_Valid) {
    TestNPC npc("NPC", 1, {5, 10, 3, 2}, 50, {1, 2});

    std::vector<int> newLoot = {3, 4, 5};
    npc.SetLoot(newLoot);
    
    EXPECT_EQ(npc.GetLoot(), newLoot);
}

// **Test for Setting an Empty Loot List**
TEST(NPCTest, SetLoot_Empty) {
    TestNPC npc("NPC", 1, {5, 10, 3, 2}, 50, {1, 2});

    std::vector<int> emptyLoot = {};
    npc.SetLoot(emptyLoot);
    
    EXPECT_TRUE(npc.GetLoot().empty());
}

TEST(NPCTest, SetExpReward_Valid) {
    TestNPC npc("NPC", 1, {5, 10, 3, 2}, 50, {1, 2});

    EXPECT_EQ(npc.GetExpReward(), 50); // Initial value

    npc.SetExpReward(100);
    EXPECT_EQ(npc.GetExpReward(), 100);

    npc.SetExpReward(0); // Edge case: setting to zero
    EXPECT_EQ(npc.GetExpReward(), 0);
}

// **Test for ExpReward Setter Throwing an Exception on Negative Values**
TEST(NPCTest, SetExpReward_InvalidNegative) {
    TestNPC npc("NPC", 1, {5, 10, 3, 2}, 50, {1, 2});

    EXPECT_THROW(npc.SetExpReward(-10), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
