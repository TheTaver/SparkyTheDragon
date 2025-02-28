cmake_minimum_required(VERSION 3.10)
project(RPGGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(runTests
    src/Character.cpp
    src/Attack.cpp
    tests/test.cpp
)

target_link_libraries(runTests
    gtest
    gtest_main
    pthread
)
