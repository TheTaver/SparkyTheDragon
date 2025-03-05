cmake_minimum_required(VERSION 3.26)
project(cs100-final-project)

# -----------------------------------

include(FetchContent)
FetchContent_Declare(ftxui
GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
FetchContent_Populate(ftxui)
add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ---------------------------------

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
add_subdirectory("_deps/googletest")


include_directories(${CMAKE_SOURCE_DIR}/header)


add_executable(test
    tests/test.cpp
    src/Character.cpp
    src/Attack.cpp
    src/Player.cpp
)

add_executable(chartest
    tests/chartest.cpp
    src/Character.cpp
    src/Attack.cpp
)

add_executable(attacktest
    tests/attacktest.cpp
    src/Character.cpp
    src/Attack.cpp
)

add_executable(trpg
    src/main.cpp
    src/Character.cpp
    src/Attack.cpp
    src/Player.cpp
    src/CombatInfoDisplay.cpp
)

TARGET_LINK_LIBRARIES(test 
ftxui::dom
gtest
)

TARGET_LINK_LIBRARIES(chartest
  gtest
)

TARGET_LINK_LIBRARIES(attacktest
  gtest
)

TARGET_LINK_LIBRARIES(trpg
PRIVATE ftxui::screen
PRIVATE ftxui::dom
PRIVATE ftxui::component
)

# include_directories(
  #   ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  #   ${CMAKE_SOURCE_DIR}/deps/FTXUI/include/ftxui/
  # )
  
add_executable(runTests
  tests/test.cpp
  src/Character.cpp
  src/Attack.cpp
  src/Player.cpp
)

target_link_libraries(runTests
  ftxui::dom
  gtest
  gtest_main
  pthread
)