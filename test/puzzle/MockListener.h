#include "gmock/gmock.h"
#include <Puzzle.h>

#ifndef MOCK_LISTENER_H
#define MOCK_LISTENER_H

class MockListener : public PuzzleListener {
public:
    MockListener() {}
    MOCK_METHOD(void, onSolved, (), ());
};

#endif // MOCK_LISTENER_H
