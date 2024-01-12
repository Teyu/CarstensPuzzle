add_test([=[HelloTest.BasicAssertions]=]  /home/julia/Documents/carstens_puzzle/build/test/HelloTest [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /home/julia/Documents/carstens_puzzle/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  HelloTest_TESTS HelloTest.BasicAssertions)
