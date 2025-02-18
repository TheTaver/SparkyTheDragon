#include "gtest/gtest.h"
#include <ftxui/dom/elements.hpp>


TEST(FTX_Import, CreateElement) {
    EXPECT_NO_THROW( ftxui::Element testBox = ftxui::hbox({
        ftxui::text(L"Hello, World!") | ftxui::border | ftxui::bold
    }));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}