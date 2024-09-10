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