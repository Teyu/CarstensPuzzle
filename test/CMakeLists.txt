# Julia Michaely

include(FetchContent)
set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable ( TestRandomizer
    RandomizerTest.cpp
    ${PROJECT_SOURCE_DIR}/include/Randomizer.h
    ${PROJECT_SOURCE_DIR}/src/Randomizer.cpp
)
 
target_link_libraries( TestRandomizer
  gtest
  gtest_main
  gmock
  gmock_main
)

add_executable ( TestPuzzle
    PuzzleTest.cpp
    ${PROJECT_SOURCE_DIR}/include/Puzzle.h
)

target_link_libraries( TestPuzzle
  gtest
  gtest_main
  gmock
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(TestRandomizer)
gtest_discover_tests(TestPuzzle)

