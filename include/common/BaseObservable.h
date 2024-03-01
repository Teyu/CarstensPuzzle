// Julia Michaely

#include <list>

#ifndef BASE_OBSERVABLE_H
#define BASE_OBSERVABLE_H

template <class Listener>
class BaseObservable{
public:
    void addListener(Listener* listener) {
        mListeners.push_back (listener);
    }
    void removeListener(Listener* listener) {
        mListeners.remove (listener);
    }
    std::list<Listener*> getListeners() {
        return mListeners;
    }

protected:
    std::list<Listener*> mListeners;
};

#endif // BASE_OBSERVABLE_H
