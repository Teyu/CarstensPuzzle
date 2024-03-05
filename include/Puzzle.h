// Julia Michaely

#include <list>
#include <algorithm>
#include <Randomizer.h>
#include <common/BaseObservable.h>

#ifndef PUZZLE_H
#define PUZZLE_H

enum STATUS { SUCCESS, NO_SUCCESS };

class PuzzleListener {
public :
    virtual ~PuzzleListener() = default;
    virtual void onSolved() = 0;
};

template <class Item, class Listener>
class Puzzle : public BaseObservable<Listener>{

public:
    Puzzle() {};

    void create(std::list<int> uniqueRands);
    void clear();
    STATUS modifyItem(Item* item, const Item* newItem);

protected:
    virtual bool isSolved() = 0;
    virtual const Item createItem(int rand) = 0;

protected:
    std::list<Item> mItems;

private:
    void notifySolved();
};

#endif // PUZZLE_H

#include "Puzzle.inl"

