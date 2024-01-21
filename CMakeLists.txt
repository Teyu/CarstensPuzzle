# Julia Michaely

cmake_minimum_required (VERSION 3.24) # use feature: fetch content via URL
cmake_policy(VERSION 3.24)

project(CarstensPuzzle)
project(TestRandomizer)
project(TestPuzzle)

include_directories("include")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)
