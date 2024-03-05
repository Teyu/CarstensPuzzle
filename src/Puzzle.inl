#ifndef PUZZLE_INL
#define PUZZLE_INL

template <class Item, class Listener>
void Puzzle<Item, Listener>::create(std::list<int> uniqueRands) {

    for (int rand : uniqueRands){
        mItems.push_back (createItem(rand));
    }
}

template <class Item, class Listener>
void Puzzle<Item, Listener>::clear() {

    if (mItems.empty()) {
        return;
    }

    mItems.clear();
}

template <class Item, class Listener>
STATUS Puzzle<Item, Listener>::modifyItem(Item* item, const Item* newItem) {

    STATUS status = NO_SUCCESS;

    if (mItems.empty()) {
        return status;
    }

    typename std::list<Item>::iterator first = mItems.begin();
    for (; first != mItems.end(); ++first) {
        if (*first == *item) {
            *first = *newItem;
            status = SUCCESS;
            break;
        }
    }

    if (this->isSolved ()){
        notifySolved();
    }

    return status;
};

template <class Item, class Listener>
void Puzzle<Item, Listener>::notifySolved() {
    for (Listener* listener : this->getListeners()){
        listener->onSolved();
    }
}

#endif // PUZZLE_INL
