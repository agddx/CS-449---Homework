cmake_minimum_required(VERSION 3.10)
project(unittesting)

set(CMAKE_CXX_STANDARD 14)

# Library
add_library(tictactoe_lib
    src/Player.cpp
    src/Board.cpp
    src/TicTacToe.cpp
)

target_include_directories(tictactoe_lib PUBLIC src)

# Main executable
add_executable(unittesting src/main.cpp)
target_link_libraries(unittesting tictactoe_lib)

# Google Test setup
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
add_executable(runTests tests/test_tictactoe.cpp)
target_link_libraries(runTests tictactoe_lib GTest::GTest GTest::Main pthread)
