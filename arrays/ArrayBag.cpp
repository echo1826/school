#include "ArrayBag.h"
#include <vector>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& item) {
    bool hasRoom = itemCount < maxItems;
    if (hasRoom) {
        items[itemCount] = item;
        itemCount++;
    }
    return hasRoom;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
    std::vector<ItemType> contents;
    // itemCount is already pointint to the next index to insert at so if the bag is full it should be at the DEFAULT_CAPACITY value (6) which is why you don't need to add 1 to it
    for (int i = 0; i < itemCount; i++) {
        contents.push_back(items[i]);
    }
    return contents;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& item) {
    return false;
}

template<class ItemType>
void ArrayBag<ItemType>::clear() {

}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& item) const {
    int frequency = 0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == item) {
            frequency++;
        }
    }
    return frequency;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& item) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == item) {
            return true;
        }
    }
    return false;
}