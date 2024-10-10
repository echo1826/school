#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType> {
    private:
        static const int DEFAULT_CAPACITY = 100;
        ItemType items[DEFAULT_CAPACITY + 1];
        int itemCount;
        int maxItems;
    public:
        ArrayList();
        bool isEmpty() const;
        int getLength() const;
        bool insert(int position, const ItemType& newEntry);
        bool remove(int position);
        void clear();

        ItemType getEntry(int position) const;
        ItemType replace(int position, const ItemType& newEntry);
};

#include "ArrayList.cpp"
#endif