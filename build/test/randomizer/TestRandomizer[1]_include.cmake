if(EXISTS "/home/julia/Documents/carstens_puzzle/build/test/randomizer/TestRandomizer[1]_tests.cmake")
  include("/home/julia/Documents/carstens_puzzle/build/test/randomizer/TestRandomizer[1]_tests.cmake")
else()
  add_test(TestRandomizer_NOT_BUILT TestRandomizer_NOT_BUILT)
endif()