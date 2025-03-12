#include "gtest/gtest.h"
#include "RoomDisplay.h"

TEST(RoomDisplayTest, ShowRoom) {
    Room r("room1.txt");
    Character player("Hero", 1, {100, 10, 10, 10});

    RoomDisplay rd;
    EXPECT_NO_THROW(rd.DisplayRoom(r, player));
}