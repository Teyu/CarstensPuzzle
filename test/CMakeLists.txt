# Julia Michaely

INCLUDE(FetchContent)
set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

ENABLE_TESTING()

ADD_EXECUTABLE ( HelloTest
    hello_test.cpp
)
 
TARGET_LINK_LIBRARIES(
  HelloTest
  gtest
  gtest_main
)

INCLUDE(GoogleTest)
gtest_discover_tests(HelloTest)

