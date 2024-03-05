#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <Puzzle.h>
#include "MockItem.h"
#include "MockListener.h"


#define EXISTING_RAND 1
#define NEW_RAND 3
#define NON_EXISTING_RAND 99
#define RANDOM_INTS_DEFAULT { 0, EXISTING_RAND, 13, 2, 4, 7, 5, 0, 28, 3 }
#define RANDOM_INTS_WITH_NEW { 0, NEW_RAND, 13, 2, 4, 7, 5, 0, 28, 3 }
#define RANDOM_INTS_WITH_NON_EXISTING { 0, NON_EXISTING_RAND, 13, 2, 4, 7, 5, 0, 28, 3 }

using namespace testing;
using ::testing::NiceMock;

class MockPuzzle : public Puzzle<MockItem, MockListener> {
public:
    MockPuzzle() : Puzzle<MockItem, MockListener> () {}

    bool isSolved() override {
        return std::equal (mItems.begin(), mItems.end (), mSolution.begin ());
    }

    void setSolution (std::list<MockItem> solution) {
        mSolution = solution;
    }

    const MockItem createItem(int rand) override {
        return MockItem(rand);
    }
private:
    std::list<MockItem> mSolution;
};

class TestPuzzle : public ::testing::Test {

protected:
    MockPuzzle *pMockPuzzle;

    MockListener *pMockListener1, *pMockListener2;
    MockItem *pMockExistingItem, *pMockNewItem, *pMockNonExistingItem;
protected:

    TestPuzzle() {
    }

    virtual ~TestPuzzle() {
    }

    virtual void SetUp() {
        pMockPuzzle = new MockPuzzle();

        pMockListener1 = new MockListener();
        pMockListener2 = new MockListener();

        pMockExistingItem = new MockItem(EXISTING_RAND);
        pMockNewItem = new MockItem(NEW_RAND);
        pMockNonExistingItem = new MockItem(NON_EXISTING_RAND);
    }

    virtual void TearDown() {
        delete pMockPuzzle;

        delete pMockListener1;
        delete pMockListener2;

        delete pMockExistingItem;
        delete pMockNewItem;
        delete pMockNonExistingItem;
    }
};

TEST_F(TestPuzzle, modifiedItemExistsReturnSuccess) {

    pMockPuzzle->create (RANDOM_INTS_DEFAULT);
    STATUS status = pMockPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
    ASSERT_EQ(status, SUCCESS);
}

TEST_F(TestPuzzle, modifiedItemNotExistingReturnNoSuccess) {

    pMockPuzzle->create (RANDOM_INTS_DEFAULT);
    STATUS status = pMockPuzzle->modifyItem (this->pMockNonExistingItem, this->pMockNewItem);
    ASSERT_EQ(status, NO_SUCCESS);
}

TEST_F(TestPuzzle, notCreatedModifyItemReturnNoSuccess) {
    STATUS status = pMockPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
    ASSERT_EQ(status, NO_SUCCESS);
}

TEST_F(TestPuzzle, modifiedPuzzleUnsolvedDoNotNotify) {

    pMockPuzzle->setSolution (RANDOM_INTS_DEFAULT);

    pMockPuzzle->addListener (this->pMockListener1);
    pMockPuzzle->addListener (this->pMockListener2);

    EXPECT_CALL(*pMockListener1, onSolved()).Times(0);
    EXPECT_CALL(*pMockListener2, onSolved()).Times(0);

    pMockPuzzle->create (RANDOM_INTS_DEFAULT);
    pMockPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
}

TEST_F(TestPuzzle, modifiedPuzzleSolvedNotify) {

    pMockPuzzle->setSolution (RANDOM_INTS_WITH_NEW);

    EXPECT_CALL(*pMockListener1, onSolved());
    EXPECT_CALL(*pMockListener2, onSolved());

    pMockPuzzle->addListener (this->pMockListener1);
    pMockPuzzle->addListener (this->pMockListener2);

    pMockPuzzle->create (RANDOM_INTS_DEFAULT);
    pMockPuzzle->modifyItem (this->pMockExistingItem, this->pMockNewItem);
}

TEST_F(TestPuzzle, multipleModificationsSolvedNotify) {

    pMockPuzzle->setSolution (RANDOM_INTS_WITH_NEW);
    MockItem *intermediate = new MockItem(NEW_RAND + 1);

    EXPECT_CALL(*pMockListener1, onSolved()).Times (1);
    EXPECT_CALL(*pMockListener2, onSolved()).Times (1);

    pMockPuzzle->addListener (this->pMockListener1);
    pMockPuzzle->addListener (this->pMockListener2);

    pMockPuzzle->create (RANDOM_INTS_DEFAULT);
    pMockPuzzle->modifyItem (this->pMockExistingItem, intermediate);
    pMockPuzzle->modifyItem (intermediate, this->pMockNewItem);

    delete intermediate;
}

TEST_F(TestPuzzle, multipleModificationsUnsolvedDoNotNotify) {

    pMockPuzzle->setSolution (RANDOM_INTS_WITH_NEW);
    MockItem *intermediate = new MockItem(NEW_RAND + 1);

    EXPECT_CALL(*pMockListener1, onSolved()).Times(0);
    EXPECT_CALL(*pMockListener2, onSolved()).Times(0);

    pMockPuzzle->addListener (this->pMockListener1);
    pMockPuzzle->addListener (this->pMockListener2);

    pMockPuzzle->create (RANDOM_INTS_DEFAULT);
    pMockPuzzle->modifyItem (this->pMockExistingItem, intermediate);
    pMockPuzzle->modifyItem (intermediate, this->pMockNonExistingItem);

    delete intermediate;
}

TEST_F(TestPuzzle, multipleCreatesPreviousReplaced) {

    pMockPuzzle->setSolution (RANDOM_INTS_WITH_NEW);

    pMockPuzzle->create (RANDOM_INTS_WITH_NON_EXISTING);
    pMockPuzzle->clear ();
    pMockPuzzle->create (RANDOM_INTS_DEFAULT);

    STATUS status = pMockPuzzle->modifyItem (this->pMockNonExistingItem, this->pMockNewItem);
    EXPECT_EQ(status, NO_SUCCESS);
    status = pMockPuzzle->modifyItem (this->pMockExistingItem, this->pMockNonExistingItem);
    EXPECT_EQ(status, SUCCESS);

}

