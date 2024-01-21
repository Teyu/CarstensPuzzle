#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <Randomizer.h>

#define RANGE_ERROR_MSG std::string(negation ? "isn't" : "is") + " in range of " + PrintToString (minValue) + " and " + PrintToString (maxValue)

using namespace testing;

MATCHER_P2 (IsInRange, minValue, maxValue, RANGE_ERROR_MSG) { return arg >= minValue && arg <= maxValue; }

TEST(TestRandomizer, setMaxMinRange) {
    // Init
    int minValue = -5, maxValue = 10;
    Randomizer randomizer = Randomizer();
    int success = true;

    // Execute
    success = randomizer.setMaxMinRange(maxValue, minValue);

    // Verify
    EXPECT_EQ (minValue, randomizer.getMinValue());
    EXPECT_EQ (maxValue, randomizer.getMaxValue());
    ASSERT_TRUE (success);
}

TEST(TestRandomizer, noMaxMinRange) {
    // Init
    int minValue = 0, maxValue = 0;
    Randomizer randomizer = Randomizer();

    // Verify
    EXPECT_EQ (minValue, randomizer.getMinValue());
    EXPECT_EQ (maxValue, randomizer.getMaxValue());
}

TEST(TestRandomizer, invalidRange) {
    // Init
    int minValue = 10, maxValue = 0;
    Randomizer randomizer = Randomizer();
    int success = true;

    // Execute
    success = randomizer.setMaxMinRange(maxValue, minValue);

    // Verify
    ASSERT_FALSE (success);
}

TEST(TestRandomizer, invalidRangeMinEqualsMax) {
    // Init
    int minValue = 10, maxValue = minValue;
    Randomizer randomizer = Randomizer();
    int success = true;

    // Execute
    success = randomizer.setMaxMinRange(maxValue, minValue);

    // Verify
    ASSERT_FALSE (success);
}

TEST(TestRandomizer, createRandomNumbers_numNumbersCreated) {

    // Init
    Randomizer randomizer = Randomizer();
    std::list<int> randsOut;
    int numNumbers = 12;

    // Execute
    randomizer.setMaxMinRange(5, 14);
    randsOut = randomizer.createRandomNumbers(numNumbers);

    // Verify
    EXPECT_EQ (randsOut.size (), numNumbers);
}

TEST(TestRandomizer, createRandomNumbers_noRangeSet) {

    // Init
    Randomizer randomizer = Randomizer();
    std::list<int> randsOut;
    int numNumbers = 12;

    // Execute
    randsOut = randomizer.createRandomNumbers(numNumbers);

    // Verify
    EXPECT_EQ (randsOut.size (), numNumbers);
    ASSERT_THAT (randsOut, Each (Eq(0)));
}

TEST(TestRandomizer, createRandomNumbers_noRange) {

    // Init
    Randomizer randomizer = Randomizer();
    std::list<int> rands;
    std::list<int> expectedRandsOut = {0, 0, 0, 0, 0};
    int numNumbers = expectedRandsOut.size ();

    // Execute
    rands = randomizer.createRandomNumbers(numNumbers);

    // Verify
    EXPECT_EQ (rands.size (), numNumbers);
    ASSERT_THAT (rands, ContainerEq (expectedRandsOut));
}

TEST(TestRandomizer, createRandomNumbers_smallRange) {

    // Init
    Randomizer randomizer = Randomizer();
    int minValue = 2, maxValue = 3; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    int repetitions = 10;
    std::list<int> rands;
    int numNumbers = 10;

    for (int i = 0; i < repetitions; i++) {
        // Execute
        rands = randomizer.createRandomNumbers(numNumbers, time(0));

        // Verify
        EXPECT_EQ (rands.size (), numNumbers);
        ASSERT_THAT (rands, Each (IsInRange (minValue, maxValue)));
    }
}

TEST(TestRandomizer, createRandomNumbers_largeRange) {

    // Init
    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 1000; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    int repetitions = 10;
    std::list<int> rands;
    int numNumbers = 10;

    for (int i = 0; i < repetitions; i++) {
        // Execute
        rands = randomizer.createRandomNumbers(numNumbers, time(0));

        // Verify
        EXPECT_EQ (rands.size (), numNumbers);
        ASSERT_THAT (rands, Each (IsInRange (minValue, maxValue)));
    }
}

TEST(TestRandomizer, createRandomNumbers_sameSeedValues) {

    // Init
    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 10; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    std::list<int> rands_1, rands_2;
    int numNumbers = 10;
    int seed = 1234;

    // Execute
    rands_1 = randomizer.createRandomNumbers(numNumbers, seed);
    rands_2 = randomizer.createRandomNumbers(numNumbers, seed);

    // Verify
    EXPECT_EQ (rands_1.size (), numNumbers);
    EXPECT_EQ (rands_2.size (), numNumbers);
    EXPECT_THAT (rands_1, Each (IsInRange (minValue, maxValue)));
    EXPECT_THAT (rands_2, Each (IsInRange (minValue, maxValue)));
    ASSERT_THAT (rands_1, ContainerEq (rands_2));
}

TEST(TestRandomizer, createRandomNumbers_differentSeedValues) {

    // Init
    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 10; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    std::list<int> rands_1, rands_2;
    int numNumbers = 1000; // choose many
    int seed_1 = 1234;
    int seed_2 = 5678;

    // Execute
    rands_1 = randomizer.createRandomNumbers(numNumbers, seed_1);
    rands_2 = randomizer.createRandomNumbers(numNumbers, seed_2);

    // Verify
    EXPECT_EQ (rands_1.size (), numNumbers);
    EXPECT_EQ (rands_2.size (), numNumbers);
    EXPECT_THAT (rands_1, Each (IsInRange (minValue, maxValue)));
    EXPECT_THAT (rands_2, Each (IsInRange (minValue, maxValue)));
    ASSERT_THAT (rands_1, Not (ContainerEq (rands_2)));
}

TEST(TestRandomizer, createRandomNumbers_noSeedValue) {

    // Init
    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 10; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    std::list<int> rands_1, rands_2;
    int numNumbers = 1000; // choose many

    // Execute
    rands_1 = randomizer.createRandomNumbers(numNumbers);
    rands_2 = randomizer.createRandomNumbers(numNumbers);

    // Verify
    EXPECT_EQ (rands_1.size (), numNumbers);
    EXPECT_EQ (rands_2.size (), numNumbers);
    EXPECT_THAT (rands_1, Each (IsInRange (minValue, maxValue)));
    EXPECT_THAT (rands_2, Each (IsInRange (minValue, maxValue)));
    ASSERT_THAT (rands_1, ContainerEq (rands_2));
}
