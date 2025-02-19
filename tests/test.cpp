#include <string>
#include <vector>
#include "gtest/gtest.h"

#include <ftxui/dom/elements.hpp>
#include "Character.h"

using std::string;
using std::vector;


TEST(FTX_Import, CreateElement) {
    EXPECT_NO_THROW( ftxui::Element testBox = ftxui::hbox({
        ftxui::text(L"Hello, World!") | ftxui::border | ftxui::bold
    }));
}

TEST(CharacterClass, ConstructReg) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < 4; i++) {
        stats.push_back(i);
    }
    
    EXPECT_NO_THROW(
        Character reggie(name, level, stats);
        EXPECT_EQ(reggie.GetName(), name);
        EXPECT_EQ(reggie.GetLevel(), level);
    );
}

TEST(CharacterClass, NegativeLevel) {
    std::string name = "Reginald";
    int level = -1;
    vector<int> stats;
    for(int i = 0; i < 4; i++) {
        stats.push_back(i);
    }
    
    EXPECT_THROW(Character reggie(name, level, stats);, std::invalid_argument);
}

TEST(CharacterClass, NotEnoughStats) {
    std::string name = "Reginald";
    int level = 1;
    vector<int> stats;
    for(int i = 0; i < 3; i++) {
        stats.push_back(i);
    }
    
    EXPECT_THROW(Character reggie(name, level, stats);, std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}