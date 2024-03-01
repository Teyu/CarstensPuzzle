

#ifndef MOCK_ITEM_H
#define MOCK_ITEM_H

class MockItem {
public:
    MockItem() : id(0) {}
    MockItem(int id) : id(id) {}
    bool operator== (const MockItem& other) {
        return id == other.id;
    }
private:
    int id;
};

#endif // MOCK_ITEM_H
