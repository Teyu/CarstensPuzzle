// Julia Michaely

#include <list>
#include <algorithm>
#include <Randomizer.h>
#include <common/BaseObservable.h>

#ifndef PUZZLE_H
#define PUZZLE_H

class PuzzleListener {
public :
    virtual ~PuzzleListener() = default;
    virtual void onCreateItem(int rand) = 0;
    virtual void onCreate() = 0;
    virtual void onSolved() = 0;
};

template <class Item, class Listener>
class Puzzle : public BaseObservable<Listener>{

public:
    Puzzle(Randomizer* randomizer) :
    mRandomizer(randomizer) {};
    void create(int numItems, int seed);
    void modifyItem(Item* item, const Item* newItem);

protected:
    virtual bool isSolved() = 0;
    virtual const Item createItem(int rand) = 0;

protected:
    std::list<Item> mItems;
    Randomizer* mRandomizer;

private:
    void notifySolved(); //TODO: notifiedSolved??
    void notifyItemsCreated(std::list<int> rands);
    void notifyCreated();
};

#endif // PUZZLE_H

#include "Puzzle.inl"

