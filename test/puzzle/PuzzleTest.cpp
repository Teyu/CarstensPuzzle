#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <Puzzle.h>
#include "MockItem.h"
#include "MockListener.h"

using namespace testing;
using ::testing::NiceMock;

class SolvedPuzzle : public Puzzle<MockItem, MockListener> {
public:
    SolvedPuzzle() : Puzzle<MockItem, MockListener>() {}

    bool isSolved() override {
        return true;
    }

    const MockItem createItem(int rand) override {
        return MockItem(rand);
    }
};

class UnsolvedPuzzle : public Puzzle<MockItem, MockListener> {
public:
    UnsolvedPuzzle() : Puzzle<MockItem, MockListener> () {}

    bool isSolved() override {
        return false;
    }

    const MockItem createItem(int rand) override {
        return MockItem(rand);
    }
};

#define RANDOM_INTS { 0, 1, 13, 2, 4, 7, 1, 0, 28, 3}
#define EXISTING_RAND 1
#define SOME_RAND 3
#define NON_EXISTING_RAND 99

class TestPuzzle : public ::testing::Test {

protected:
    SolvedPuzzle *pSolvedPuzzle;
    UnsolvedPuzzle *pUnsolvedPuzzle;

    MockListener *pMockListener1, *pMockListener2;
    MockItem *pMockExistingItem, *pMockNewItem, *pMockNonExistingItem;
protected:

    TestPuzzle() {
    }

    virtual ~TestPuzzle() {
    }

    virtual void SetUp() {
        pSolvedPuzzle = new SolvedPuzzle();
        pUnsolvedPuzzle = new UnsolvedPuzzle();

        pMockListener1 = new MockListener();
        pMockListener2 = new MockListener();

        pMockExistingItem = new MockItem(EXISTING_RAND);
        pMockNewItem = new MockItem(SOME_RAND);
        pMockNonExistingItem = new MockItem(NON_EXISTING_RAND);
    }

    virtual void TearDown() {
        delete pSolvedPuzzle;
        delete pUnsolvedPuzzle;

        delete pMockListener1;
        delete pMockListener2;

        delete pMockExistingItem;
        delete pMockNewItem;
        delete pMockNonExistingItem;
    }
};

//TODO: test multiple calls of modify item
//TODO: test execution of modify item
//TODO: test multiple calls of create (will delete previous? Or seperate delete function?)

TEST_F(TestPuzzle, modifiedItemNotExistingReturnNoSuccess) {

    pUnsolvedPuzzle->create (RANDOM_INTS);
    STATUS status = pUnsolvedPuzzle->modifyItem (this->pMockNonExistingItem, this->pMockNewItem);
    ASSERT_EQ(status, NO_SUCCESS);
}

TEST_F(TestPuzzle, modifiedItemExistsReturnSuccess) {

    pUnsolvedPuzzle->create (RANDOM_INTS);
    STATUS status = pUnsolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
    ASSERT_EQ(status, SUCCESS);
}

TEST_F(TestPuzzle, notCreatedModifyItemReturnNoSuccess) {

    STATUS status = pUnsolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
    ASSERT_EQ(status, NO_SUCCESS);
}

TEST_F(TestPuzzle, modifyPuzzleUnsolvedDoNotNotify) {

    pUnsolvedPuzzle->addListener (this->pMockListener1);
    pUnsolvedPuzzle->addListener (this->pMockListener2);

    EXPECT_CALL(*pMockListener1, onSolved()).Times(0);
    EXPECT_CALL(*pMockListener2, onSolved()).Times(0);

    pUnsolvedPuzzle->create (RANDOM_INTS);
    pUnsolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
}

TEST_F(TestPuzzle, puzzleSolvedNoListenersNotNotified) {

    EXPECT_CALL(*pMockListener1, onSolved()).Times(0);
    EXPECT_CALL(*pMockListener2, onSolved()).Times(0);

    pSolvedPuzzle->create (RANDOM_INTS);
    pSolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
}

TEST_F(TestPuzzle, puzzleSolvedHasListenersNotified) {

    EXPECT_CALL(*pMockListener1, onSolved());
    EXPECT_CALL(*pMockListener2, onSolved());

    pSolvedPuzzle->addListener (this->pMockListener1);
    pSolvedPuzzle->addListener (this->pMockListener2);

    pSolvedPuzzle->create (RANDOM_INTS);
    pSolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
}

TEST_F(TestPuzzle, puzzleNotSolvedNoListenersNotified) {

    pUnsolvedPuzzle->create (RANDOM_INTS);
    pUnsolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);

    EXPECT_CALL(*pMockListener1, onSolved()).Times(0);
    EXPECT_CALL(*pMockListener2, onSolved()).Times(0);
}

TEST_F(TestPuzzle, puzzleNotSolvedHasListenersNotNotified) {

    pUnsolvedPuzzle->addListener (this->pMockListener1);
    pUnsolvedPuzzle->addListener (this->pMockListener2);

    EXPECT_CALL(*pMockListener1, onSolved()).Times(0);
    EXPECT_CALL(*pMockListener2, onSolved()).Times(0);

    pUnsolvedPuzzle->create (RANDOM_INTS);
    pUnsolvedPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
}
