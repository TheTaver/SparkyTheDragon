cmake_minimum_required(VERSION 3.26)
project(cs100-final-project)

set(CMAKE_BUILD_TYPE Debug)
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
  src/NPCReader.cpp
  src/npc.cpp
  src/Player.cpp
  )

include_directories(${CMAKE_SOURCE_DIR}/header)


add_executable(test
    tests/test.cpp
    src/Character.cpp
    src/Attack.cpp
    src/Player.cpp
    src/Shooter.cpp
    src/Duelist.cpp
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
add_executable(NPCTests
  tests/npctest.cpp
  src/Character.cpp
  src/Attack.cpp
  src/npc.cpp
)

add_executable(roomTest
    tests/roomTest.cpp
    src/Room.cpp

)

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
    src/NPCReader.cpp
    src/Duelist.cpp
)

add_executable(duelistTests
    tests/duelistTest.cpp
    src/Duelist.cpp
    src/Attack.cpp
    src/Character.cpp
    src/Player.cpp
    )

add_executable(trpg
  src/main.cpp
  ${SOURCE_FILES}
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

TARGET_LINK_LIBRARIES(roomTest
PRIVATE gtest
PRIVATE gtest_main
PRIVATE pthread
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

# include_directories(
  #   ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  #   ${CMAKE_SOURCE_DIR}/deps/FTXUI/include/ftxui/
  # )
  
add_executable(runTests
  tests/test.cpp
  src/Character.cpp
  src/Attack.cpp
  src/Player.cpp
  src/Duelist.cpp
  src/Shooter.cpp
)

add_executable(shooterTest
  tests/shootertest.cpp
  src/Attack.cpp
  src/Shooter.cpp
  src/Character.cpp
  src/Player.cpp
)

target_link_libraries(shooterTest
 gtest
 gtest_main
 pthread
)

target_link_libraries(runTests
  ftxui::dom
  gtest
  gtest_main
  pthread
)

TARGET_LINK_LIBRARIES(NPCTests
  PRIVATE gtest
  PRIVATE gtest_main
  PRIVATE pthread
)

TARGET_LINK_LIBRARIES(duelistTests
  PRIVATE gtest
  PRIVATE gtest_main
  PRIVATE pthread
)
