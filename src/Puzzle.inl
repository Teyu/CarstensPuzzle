#ifndef PUZZLE_INL
#define PUZZLE_INL

template <class Item, class Listener>
void Puzzle<Item, Listener>::create(int numItems, int seed) {

    std::list<int> rands = mRandomizer->createRandomNumbers (numItems, seed);

    for (int rand : rands){
        mItems.push_back (createItem(rand));
    }

    notifyItemsCreated (rands);
    notifyCreated ();
}

template <class Item, class Listener>
void Puzzle<Item, Listener>::modifyItem(Item* item, const Item* newItem) {

    std::replace (mItems.begin(), mItems.end(), *item, *newItem);

    if (this->isSolved ()){
        notifySolved();
    }
};

template <class Item, class Listener>
void Puzzle<Item, Listener>::notifySolved() {
    for (Listener* listener : this->getListeners()){
        listener->onSolved();
    }
}

template <class Item, class Listener>
void Puzzle<Item, Listener>::notifyItemsCreated(std::list<int> rands) {
    for (Listener* listener : this->getListeners()){
        for (int rand : rands){
            listener->onCreateItem(rand);
        }
    }
};

template <class Item, class Listener>
void Puzzle<Item, Listener>::notifyCreated() {
    for (Listener* listener : this->getListeners()){
        listener->onCreate();
    }
};

#endif // PUZZLE_INL
