

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

include(GoogleTest)
gtest_discover_tests(TestRandomizer)
