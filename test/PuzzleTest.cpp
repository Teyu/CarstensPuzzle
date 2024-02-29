#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <Puzzle.h>

#define SEED 0
#define NUM_ITEMS 10

using namespace testing;
using ::testing::NiceMock;

//TODO: extract Mocks to header-file
class MockItem {
public:
    MockItem() : id(0) {}
    MockItem(int id) : id(id) {}
    bool operator== (const MockItem& other) {
        return id == other.id;
    }
private:
    int id;
};

class MockListener : public PuzzleListener {
public:
    MockListener() : onCreateCalled(false), onSolvedCalled(false) {}
    void onCreateItem(int rand) override { itemsCreated.push_back (rand);}
    void onCreate() override { onCreateCalled = true;}
    void onSolved() override { onSolvedCalled = true;}
public:
    bool onCreateCalled;
    bool onSolvedCalled;
    std::list<int> itemsCreated;
};

class MockRandomizer : public Randomizer { //TODO: class names should be CName
public:

    MockRandomizer() : Randomizer () {}
    MockRandomizer(const MockRandomizer& other) : Randomizer(other){}

    MOCK_METHOD(std::list<int>, createRandomNumbers, (int num_numbers, int seed), ());

    void delegateToMock(std::list<int> returnList, int seed) {
        ON_CALL (*this, createRandomNumbers (returnList.size(), seed)).
            WillByDefault(Return(returnList));
    }
};

class SolvedPuzzle : public Puzzle<MockItem, MockListener> {
public:
    SolvedPuzzle(MockRandomizer* randomizer) : Puzzle<MockItem, MockListener> (randomizer) {}

    bool isSolved() override {
        return true;
    }

    const MockItem createItem(int rand) override {
        return MockItem(rand);
    }
};

class UnsolvedPuzzle : public Puzzle<MockItem, MockListener> {
public:
    UnsolvedPuzzle(MockRandomizer* randomizer) : Puzzle<MockItem, MockListener> (randomizer) {}

    bool isSolved() override {
        return false;
    }

    const MockItem createItem(int rand) override {
        return MockItem(rand);
    }
};

TEST(TestPuzzle, noListenersStartOnCreateItemsNotified) {
    // Init
    std::list<int> returnList = {0,1,2};
    int numNumbers = returnList.size();

    MockRandomizer randomizer = MockRandomizer();
    randomizer.delegateToMock (returnList, SEED);

    MockListener listener;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.create (numNumbers, SEED);

    // Verify
    ASSERT_TRUE (listener.itemsCreated.empty ());
}

TEST(TestPuzzle, hasListenersStartOnCreateItemsNotified) {
    // Init
    std::list<int> returnList = {0,1,2};
    int numNumbers = returnList.size();

    MockRandomizer randomizer = MockRandomizer();
    randomizer.delegateToMock (returnList, SEED);

    MockListener listener1, listener2;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.addListener (&listener1);
    unsolvedPuzzle.addListener (&listener2);
    unsolvedPuzzle.create (numNumbers, SEED);

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
    unsolvedPuzzle.create(NUM_ITEMS, SEED);

    // Verify
    ASSERT_FALSE(listener.onCreateCalled);
}

TEST(TestPuzzle, hasListenersOnStartNotified) {
    // Init
    MockRandomizer randomizer;
    MockListener listener1, listener2;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.addListener (&listener1);
    unsolvedPuzzle.addListener (&listener2);
    unsolvedPuzzle.create(NUM_ITEMS, SEED);

    // Verify
    ASSERT_TRUE(listener1.onCreateCalled);
    ASSERT_TRUE(listener1.onCreateCalled);
}

TEST(TestPuzzle, modifyPuzzleUnsolvedDoNotFinish) {
    // Init
    MockItem item(1), newItem(2);
    MockRandomizer randomizer;
    MockListener listener;
    UnsolvedPuzzle unsolvedPuzzle(&randomizer);

    // Execute
    unsolvedPuzzle.addListener (&listener);
    unsolvedPuzzle.modifyItem (&item, &newItem);

    // Verify
    ASSERT_FALSE(listener.onSolvedCalled);
}

TEST(TestPuzzle, puzzleSolvedNoListenersOnFinishNotified) {
    // Init
    MockItem item(1), newItem(2);
    MockRandomizer randomizer;
    MockListener listener;
    SolvedPuzzle solvedPuzzle(&randomizer);

    // Execute
    solvedPuzzle.modifyItem (&item, &newItem); // invoke onFinish

    // Verify
    ASSERT_FALSE(listener.onSolvedCalled);
}

TEST(TestPuzzle, puzzleSolvedHasListenersOnFinishNotified) {
    // Init
    MockItem item(1), newItem(2);
    MockRandomizer randomizer;
    MockListener listener1, listener2;
    SolvedPuzzle solvedPuzzle(&randomizer);

    // Execute
    solvedPuzzle.addListener (&listener1);
    solvedPuzzle.addListener (&listener2);
    solvedPuzzle.modifyItem (&item, &newItem); // invoke onFinish

    // Verify
    ASSERT_TRUE(listener1.onSolvedCalled);
    ASSERT_TRUE(listener2.onSolvedCalled);
}
