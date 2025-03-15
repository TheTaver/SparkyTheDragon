cmake_minimum_required(VERSION 3.26)
project(cs100-final-project)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS --coverage)
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

set(SOURCE_FILES
  src/Attack.cpp
  src/Character.cpp
  src/CombatController.cpp
  src/CombatInfoDisplay.cpp
  src/CombatUI.cpp
  src/Duelist.cpp
  src/MenuDisplay.cpp
  src/npc.cpp
  src/Player.cpp
  src/Room.cpp
  src/Shooter.cpp
  src/Shooter.cpp
  src/GameController.cpp
  src/brawler.cpp
  )

include_directories(${CMAKE_SOURCE_DIR}/header)

add_executable(cuitest
    tests/combatuitest.cpp
    src/Character.cpp
    src/Attack.cpp
    src/Player.cpp
    src/CombatInfoDisplay.cpp
    src/CombatUI.cpp
    src/Duelist.cpp
)

add_executable(combattest
    tests/combattest.cpp
    src/Character.cpp
    src/Attack.cpp
    src/Player.cpp
    src/CombatInfoDisplay.cpp
    src/CombatUI.cpp
    src/CombatController.cpp
    src/Duelist.cpp
    src/Shooter.cpp
    src/brawler.cpp
    src/MenuDisplay.cpp
)

add_executable(trpg
  src/main.cpp
  ${SOURCE_FILES}
)

TARGET_LINK_LIBRARIES(trpg
PRIVATE ftxui::screen
PRIVATE ftxui::dom
PRIVATE ftxui::component
)

TARGET_LINK_LIBRARIES(cuitest
PRIVATE ftxui::screen
PRIVATE ftxui::dom
PRIVATE ftxui::component
)

TARGET_LINK_LIBRARIES(combattest
PRIVATE ftxui::screen
PRIVATE ftxui::dom
PRIVATE ftxui::component
)

add_executable(allTests
  tests/attacktest.cpp
  tests/chartest.cpp
  # tests/combattest.cpp
  # tests/combatuitest.cpp
  tests/duelistTest.cpp
  tests/brawlertest.cpp
  tests/npctest.cpp
  tests/roomTest.cpp
  tests/shootertest.cpp
  tests/test.cpp
  ${SOURCE_FILES}
)


target_link_libraries(allTests
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  gtest
  gtest_main
  pthread
)
