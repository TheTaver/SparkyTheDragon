#include "../header/Room.h"
#include <gtest/gtest.h>
#include <fstream>
#include <iostream>

// Create a temp room file for testing
void CreateTestRoomFile(const std::string& filename) {
    std::ofstream file(filename);
    file << "Basement\n";
    file << "You wake up in a cold, abandoned factory basement.\n";
    file << "What do you want to do?\n";
    file << "3\n";
    file << "Search the room for anything useful.\n";
    file << "Head upstairs toward the faint sound of machinery.\n";
    file << "Listen carefully for anything nearby.\n";
    file << "1\n";
    file.close();
}

TEST(RoomTest, LoadRoomCorrectly) {
    const std::string filename = "test_room.txt";
    CreateTestRoomFile(filename);

    Room room(filename);

    EXPECT_EQ(room.GetDescription(), "You wake up in a cold, abandoned factory basement.");
    EXPECT_EQ(room.GetChoice(), "What do you want to do?");
    EXPECT_EQ(room.GetNumOptions(), 3);

    std::vector<std::string> expectedOptions = {
        "Search the room for anything useful.",
        "Head upstairs toward the faint sound of machinery.",
        "Listen carefully for anything nearby."
    };

    EXPECT_EQ(room.GetOptions(), expectedOptions);
    EXPECT_TRUE(room.HasCombat());
}

TEST(RoomTest, RoomWithNoCombat) {
    std::ofstream file("no_combat_room.txt");
    file << "Lounge\n";
    file << "A quiet room with old couches and flickering lights.\n";
    file << "What do you want to do?\n";
    file << "2\n";
    file << "Sit and rest.\n";
    file << "Check the vending machine.\n";
    file << "0\n";  // No combat
    file.close();

    Room room("no_combat_room.txt");

    EXPECT_FALSE(room.HasCombat());
}

TEST(RoomTest, MissingFileThrows) {
    EXPECT_THROW(Room room("nonexistent_file.txt"), std::runtime_error);
}

TEST(RoomTest, MalformedFileThrows) {
    std::ofstream file("malformed_room.txt");
    file << "IncompleteRoom\n";
    file << "This room is missing data.\n";
    file << "What do you do?\n";
    file << "2\n";  // Declares 2 options, but only 1 is provided
    file << "Option 1\n";
    file.close();

    EXPECT_THROW(Room room("malformed_room.txt"), std::runtime_error);
}

TEST(RoomTest, MissingPositionThrows) {
    std::ofstream file("missing_position.txt");
    file.close();

    EXPECT_THROW(Room room("missing_position.txt"), std::runtime_error);
}

TEST(RoomTest, MissingDescriptionThrows) {
    std::ofstream file("missing_description.txt");
    file << "OnlyPosition\n";
    file.close();

    EXPECT_THROW(Room room("missing_description.txt"), std::runtime_error);
}

TEST(RoomTest, MissingChoiceThrows) {
    std::ofstream file("missing_choice.txt");
    file << "PositionLine\n";
    file << "DescriptionLine\n";
    file.close();

    EXPECT_THROW(Room room("missing_choice.txt"), std::runtime_error);
}

TEST(RoomTest, InvalidNumOptionsThrows) {
    std::ofstream file("invalid_num_options.txt");
    file << "Position\n";
    file << "Description\n";
    file << "Choice\n";
    file << "XYZ\n"; 

    EXPECT_THROW(Room room("invalid_num_options.txt"), std::runtime_error);
}

TEST(RoomTest, InvalidNumOptionsThrows2) {
    std::ofstream file("invalid_num_options2.txt");
    file << "Position\n";
    file << "Description\n";
    file << "Choice\n";
    file << "XYZ\n"; 
    file.close();

    EXPECT_THROW(Room room("invalid_num_options.txt"), std::runtime_error);
}

TEST(RoomTest, MissingOptionsThrows) {
    std::ofstream file("missing_options.txt");
    file << "Position\n";
    file << "Description\n";
    file << "Choice\n";
    file << "3\n"; 
    file << "Option 1\n"; 
    file.close();

    EXPECT_THROW(Room room("missing_options.txt"), std::runtime_error);
}

TEST(RoomTest, InvalidHasCombatThrows) {
    std::ofstream file("invalid_combat_value.txt");
    file << "Position\n";
    file << "Description\n";
    file << "Choice\n";
    file << "2\n"; 
    file << "Option 1\n";
    file << "Option 2\n";
    file << "XYZ\n"; 
    file.close();

    EXPECT_THROW(Room room("invalid_combat_value.txt"), std::runtime_error);
}

TEST(RoomTest, UnexpectedFileErrorThrows) {
    std::ofstream file("corrupt_file.txt");
    file << "Position\n";
    file << "Description\n";
    file << "Choice\n";
    file << "3\n";
    file << "Option 1\n";
    file << "Option 2\n";
    file << "Option 3\n";
    file << "1\n";  
    file.close();

    chmod("corrupt_file.txt", 0000);  

    EXPECT_THROW(Room room("corrupt_file.txt"), std::runtime_error);

    chmod("corrupt_file.txt", 0644); 
}