#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <memory>
#include "ListInterface.h"
#include "../Node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
    private:
        std::shared_ptr<Node<ItemType>> head;
        int itemCount;
        auto getNode(int position) const;
        auto insertNode(int newPosition, std::shared_ptr<Node<ItemType>> newNode, std::shared_ptr<Node<ItemType>> subChainPointer);
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
        bool insertRecursion(int newPosition, const ItemType& newEntry);
};


#include "LinkedList.cpp"
#endif