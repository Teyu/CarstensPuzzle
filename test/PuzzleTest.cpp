#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <Puzzle.h>

#define SEED 0
#define NUM_ITEMS 10

class MockItem {};

class MockListener : public PuzzleListener {
public:
    MockListener() : onStartCalled(false), onFinishCalled(false) {}
    void onCreateItem(int rand) override { itemsCreated.push_back (rand);}
    void onStart() override { onStartCalled = true;}
    void onFinish() override { onFinishCalled = true;}
public:
    bool onStartCalled;
    bool onFinishCalled;
    std::list<int> itemsCreated;
};

class MockRandomizer : public Randomizer {
public:
    using Randomizer::Randomizer;
    MockRandomizer(const MockRandomizer& other) : Randomizer((Randomizer)other){}
    MOCK_METHOD(std::list<int>, createRandomNumbers, (int num_numbers, int seed), ());
};

class SolvedPuzzle : public Puzzle<MockItem, MockListener> {
public:
    using Puzzle<MockItem, MockListener>::Puzzle;
    bool isSolved() override {
        return true;
    }
};

class UnsolvedPuzzle : public Puzzle<MockItem, MockListener> {
public:
    using Puzzle<MockItem, MockListener>::Puzzle;
    bool isSolved() override {
        return false;
    }
};

using namespace testing;

using ::testing::NaggyMock;

TEST(TestPuzzle, noListenersStartOnCreateItemsNotified) {
    // Init
    MockRandomizer randomizer;
    MockListener listener;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    std::list<int> returnList = {0,1,2};
    int numNumbers = returnList.size();

    ON_CALL (randomizer, createRandomNumbers (numNumbers, SEED)).
        WillByDefault(Return(returnList));

    // Execute
    unsolvedPuzzle.start (NUM_ITEMS);

    // Verify
    ASSERT_TRUE (listener.itemsCreated.empty ());
}

TEST(TestPuzzle, hasListenersStartOnCreateItemsNotified) {
    // Init
    MockRandomizer randomizer;
    MockListener listener1, listener2;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    std::list<int> returnList = {0,1,2};
    int numNumbers = returnList.size();

    ON_CALL (randomizer, createRandomNumbers (numNumbers, SEED)).
        WillByDefault(Return(returnList));

    // Execute
    unsolvedPuzzle.addListener (&listener1);
    unsolvedPuzzle.addListener (&listener2);
    unsolvedPuzzle.start (NUM_ITEMS);

    // Verify
    ASSERT_THAT (returnList, ContainerEq(listener1.itemsCreated));
    ASSERT_THAT (returnList, ContainerEq(listener2.itemsCreated));
}

TEST(TestPuzzle, noListenersOnStartNotified) {
    // Init
    MockRandomizer randomizer;
    MockListener listener;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.start(NUM_ITEMS);

    // Verify
    ASSERT_FALSE(listener.onStartCalled);
}

TEST(TestPuzzle, hasListenersOnStartNotified) {
    // Init
    MockRandomizer randomizer;
    MockListener listener1, listener2;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.addListener (&listener1);
    unsolvedPuzzle.addListener (&listener2);
    unsolvedPuzzle.start(NUM_ITEMS);

    // Verify
    ASSERT_TRUE(listener1.onStartCalled);
    ASSERT_TRUE(listener1.onStartCalled);
}

TEST(TestPuzzle, modifyPuzzleUnsolvedDoNotFinish) {
    // Init
    MockItem modifyItem;
    MockRandomizer randomizer;
    MockListener listener;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.addListener (&listener);
    unsolvedPuzzle.modifyItem (modifyItem);

    // Verify
    ASSERT_FALSE(listener.onFinishCalled);
}

TEST(TestPuzzle, puzzleSolvedNoListenersOnFinishNotified) {
    // Init
    MockItem modifyItem;
    MockRandomizer randomizer;
    MockListener listener;
    SolvedPuzzle solvedPuzzle(&randomizer);

    // Execute
    solvedPuzzle.modifyItem (modifyItem); // invoke onFinish

    // Verify
    ASSERT_FALSE(listener.onFinishCalled);
}

TEST(TestPuzzle, puzzleSolvedHasListenersOnFinishNotified) {
    // Init
    MockItem modifyItem;
    MockRandomizer randomizer;
    MockListener listener1, listener2;
    SolvedPuzzle solvedPuzzle(&randomizer);

    // Execute
    solvedPuzzle.addListener (&listener1);
    solvedPuzzle.addListener (&listener2);
    solvedPuzzle.modifyItem (modifyItem); // invoke onFinish

    // Verify
    ASSERT_TRUE(listener1.onFinishCalled);
    ASSERT_TRUE(listener2.onFinishCalled);
}
