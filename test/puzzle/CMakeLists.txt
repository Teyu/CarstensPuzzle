
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable ( TestPuzzle
    PuzzleTest.cpp
    ${PROJECT_SOURCE_DIR}/src/Randomizer.cpp
    ${PROJECT_SOURCE_DIR}/src/Puzzle.inl
    ${PROJECT_SOURCE_DIR}/include/Puzzle.h
)

target_link_libraries( TestPuzzle
  gtest
  gtest_main
  gmock
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(TestPuzzle)
