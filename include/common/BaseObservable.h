// Julia Michaely

#include <list>

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
