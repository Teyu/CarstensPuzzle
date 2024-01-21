// Julia Michaely

#include <list>
#include <Randomizer.h>
#include <common/BaseObservable.h>

#ifndef PUZZLE_H
#define PUZZLE_H

class PuzzleListener {
public :
    virtual ~PuzzleListener(){}
    virtual void onCreateItem(int rand) = 0;
    virtual void onStart() = 0;
    virtual void onFinish() = 0;
};

template <class Item, class Listener>
class Puzzle : public BaseObservable<Listener>{
public:
    Puzzle(Randomizer* randomizer) :
    mRandomizer(randomizer) {};
    ~Puzzle(){};
    void start(int numItems) {}
    void modifyItem(Item item) {};

protected:
    virtual bool isSolved() = 0;

protected:
    std::list<Item> mPuzzle;
    Randomizer* mRandomizer;
};

#endif // PUZZLE_H
