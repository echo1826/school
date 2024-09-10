#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"
template<class ItemType>
class ArrayBag : public BagInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 6;
    ItemType items[DEFAULT_CAPACITY];
    int itemCount;
    int maxItems;
    int getIndexOf(const ItemType& target) const;

public:
    ArrayBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& entry);
    void clear();
    bool contains(const ItemType& entry) const;
    int getFrequencyOf(const ItemType& entry) const;
    std::vector<ItemType> toVector() const;

};

#include "ArrayBag.cpp"
#endif