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
        Node<ItemType>* insertNode(int newPosition, Node<ItemType>* newNode, Node<ItemType>* subChainPointer);
    public:
        LinkedList();
        LinkedList(const LinkedList<ItemType>& list);
        virtual ~LinkedList();
        bool operator==(const LinkedList<ItemType>& rightHandSide) const; // overloading the == operator when we call it with another linkedlist comparison

        // friend access gives methods access to private members of the class even if they are not a member of the class
        template<class friendItemType> // because the << is not a member of the LinkedList class you must declare another template item type for the LinkedList parameter
        friend std::ostream& operator<<(std::ostream& outputStream, const LinkedList<friendItemType>& outputList);

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