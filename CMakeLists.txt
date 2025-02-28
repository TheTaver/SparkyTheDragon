cmake_minimum_required(VERSION 3.10)
project(PlayerTests)


set(CMAKE_CXX_STANDARD 17)


add_library(player_lib
    src/Player.cpp
)


target_include_directories(player_lib PUBLIC include)

# Enable testing
enable_testing()


add_subdirectory(test)
