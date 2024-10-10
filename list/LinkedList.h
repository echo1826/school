#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
    private:
        Node<ItemType>* head;
        int itemCount;
        Node<ItemType>* getNode(int position) const;
    public:
        LinkedList();
        LinkedList(const LinkedList<ItemType>& list);
        virtual ~LinkedList();
        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ItemType& newEntry);
        bool remove(int position);
        void clear();
        ItemType getEntry(int position) const;
        ItemType replace(int position, const ItemType& newEntry);

};


#include "LinkedList.cpp"
#endif