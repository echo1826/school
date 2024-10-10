#include "ArrayList.h"
#include <stdexcept>

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int position, const ItemType& item) {
    if(position < 1 || position > itemCount + 1 || itemCount >= maxItems) {
        return false;
    }
    for(int i = itemCount; i >= position; i--) {
        items[i + 1] = items[i];
    }
    items[position] = item;
    itemCount++;
    return true;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
    if(position > itemCount) {
        throw std::logic_error("getEntry at invalid position");
    }
    return items[position];
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
    if(position < 1 || position > itemCount + 1 || itemCount == 0) {
        return false;
    }
    for(int i = position; i < itemCount; i++) {
        items[i] = items[i + 1];
    }
    itemCount--;
    return true;
}

template<class ItemType>
void ArrayList<ItemType>::clear() {
    itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& item) {
    if(position > itemCount) {
        throw std::logic_error("replace at invalid position");
    }
    ItemType replaced = items[position];
    items[position] = item;
    return replaced;
}