#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <Randomizer.h>

#define RANGE_ERROR_MSG std::string(negation ? "isn't" : "is") + " in range of " + PrintToString (minValue) + " and " + PrintToString (maxValue)

using namespace testing;

MATCHER_P2 (IsInRange, minValue, maxValue, RANGE_ERROR_MSG) { return arg >= minValue && arg <= maxValue; }

TEST(TestRandomizer, setMaxMinRange_validRangeSucess) {

    int minValue = -5, maxValue = 10;
    Randomizer randomizer = Randomizer();
    int success = true;

    success = randomizer.setMaxMinRange(maxValue, minValue);

    EXPECT_EQ (minValue, randomizer.getMinValue());
    EXPECT_EQ (maxValue, randomizer.getMaxValue());
    ASSERT_TRUE (success);
}

TEST(TestRandomizer, noMaxMinRange_returnDefault) {
    int minValue = 0, maxValue = 0;
    Randomizer randomizer = Randomizer();

    EXPECT_EQ (minValue, randomizer.getMinValue());
    EXPECT_EQ (maxValue, randomizer.getMaxValue());
}

TEST(TestRandomizer, invalidRange_noSuccess) {
    int minValue = 10, maxValue = 0;
    Randomizer randomizer = Randomizer();
    int success = true;

    success = randomizer.setMaxMinRange(maxValue, minValue);

    ASSERT_FALSE (success);
}

TEST(TestRandomizer, invalidRangeMinEqualsMax_noSuccess) {
    int minValue = 10, maxValue = minValue;
    Randomizer randomizer = Randomizer();
    int success = true;

    success = randomizer.setMaxMinRange(maxValue, minValue);

    ASSERT_FALSE (success);
}

TEST(TestRandomizer, createRandomNumbers_numNumbersCreated) {

    Randomizer randomizer = Randomizer();
    std::list<int> randsOut;
    int numNumbers = 12;

    randomizer.setMaxMinRange(5, 14);
    randsOut = randomizer.createRandomNumbers(numNumbers);

    EXPECT_EQ (randsOut.size (), numNumbers);
}

TEST(TestRandomizer, createRandomNumbers_noRangeReturnDefaultValues) {

    Randomizer randomizer = Randomizer();
    std::list<int> randsOut;
    int numNumbers = 12;

    randsOut = randomizer.createRandomNumbers(numNumbers);

    EXPECT_EQ (randsOut.size (), numNumbers);
    ASSERT_THAT (randsOut, Each (Eq(0)));
}

TEST(TestRandomizer, createRandomNumbers_smallRangeRandsOutInRange) {

    Randomizer randomizer = Randomizer();
    int minValue = 2, maxValue = 3; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    int repetitions = 10;
    std::list<int> rands;
    int numNumbers = 10;

    for (int i = 0; i < repetitions; i++) {
        rands = randomizer.createRandomNumbers(numNumbers, time(0));

        EXPECT_EQ (rands.size (), numNumbers);
        ASSERT_THAT (rands, Each (IsInRange (minValue, maxValue)));
    }
}

TEST(TestRandomizer, createRandomNumbers_largeRangeRandsOutInRange) {

    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 1000; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    int repetitions = 10;
    std::list<int> rands;
    int numNumbers = 10;

    for (int i = 0; i < repetitions; i++) {
        rands = randomizer.createRandomNumbers(numNumbers, time(0));

        EXPECT_EQ (rands.size (), numNumbers);
        ASSERT_THAT (rands, Each (IsInRange (minValue, maxValue)));
    }
}

TEST(TestRandomizer, createRandomNumbers_sameSeedValuesSameRandomNumbers) {

    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 10; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    std::list<int> rands_1, rands_2;
    int numNumbers = 10;
    int seed = 1234;

    rands_1 = randomizer.createRandomNumbers(numNumbers, seed);
    rands_2 = randomizer.createRandomNumbers(numNumbers, seed);

    EXPECT_EQ (rands_1.size (), numNumbers);
    EXPECT_EQ (rands_2.size (), numNumbers);
    EXPECT_THAT (rands_1, Each (IsInRange (minValue, maxValue)));
    EXPECT_THAT (rands_2, Each (IsInRange (minValue, maxValue)));
    ASSERT_THAT (rands_1, ContainerEq (rands_2));
}

TEST(TestRandomizer, createRandomNumbers_differentSeedValuesDifferentRandomNumbers) {

    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 10; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    std::list<int> rands_1, rands_2;
    int numNumbers = 1000; // choose many
    int seed_1 = 1234;
    int seed_2 = 5678;

    rands_1 = randomizer.createRandomNumbers(numNumbers, seed_1);
    rands_2 = randomizer.createRandomNumbers(numNumbers, seed_2);

    EXPECT_EQ (rands_1.size (), numNumbers);
    EXPECT_EQ (rands_2.size (), numNumbers);
    EXPECT_THAT (rands_1, Each (IsInRange (minValue, maxValue)));
    EXPECT_THAT (rands_2, Each (IsInRange (minValue, maxValue)));
    ASSERT_THAT (rands_1, Not (ContainerEq (rands_2)));
}

TEST(TestRandomizer, createRandomNumbers_noSeedValueSameRandomNumbers) {

    Randomizer randomizer = Randomizer();
    int minValue = 5, maxValue = 10; // choose minValue > 0
    randomizer.setMaxMinRange (maxValue, minValue);
    std::list<int> rands_1, rands_2;
    int numNumbers = 1000; // choose many

    rands_1 = randomizer.createRandomNumbers(numNumbers);
    rands_2 = randomizer.createRandomNumbers(numNumbers);

    EXPECT_EQ (rands_1.size (), numNumbers);
    EXPECT_EQ (rands_2.size (), numNumbers);
    EXPECT_THAT (rands_1, Each (IsInRange (minValue, maxValue)));
    EXPECT_THAT (rands_2, Each (IsInRange (minValue, maxValue)));
    ASSERT_THAT (rands_1, ContainerEq (rands_2));
}
