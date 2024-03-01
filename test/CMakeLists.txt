# Julia Michaely

include(FetchContent)
set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(puzzle)
add_subdirectory(randomizer)


