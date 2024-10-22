#include "LinkedList.h"
#include <stdexcept>
#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : head(nullptr), itemCount(0) {}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& list) {
    itemCount = list.itemCount;
    Node<ItemType>* originalListPointer = list.head;
    if(originalListPointer == nullptr) {
        head = nullptr;
    } else {
        head = new Node<ItemType>(originalListPointer->getItem());
        Node<ItemType>* newListPointer = head;
        originalListPointer = originalListPointer->getNext();
        while(originalListPointer != nullptr) {
            Node<ItemType>* newNode = new Node<ItemType>(originalListPointer->getItem());
            newListPointer->setNext(newNode);
            newListPointer = newListPointer->getNext();
            originalListPointer = originalListPointer->getNext();
        }
        newListPointer->setNext(nullptr);
    }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const  {
    return itemCount;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    if(position < 1 || position > itemCount) {
        throw std::logic_error("getEntry at invalid position");
    }
    Node<ItemType>* nodePointer = getNode(position);
    return nodePointer->getItem();
}

template<class ItemType>
auto LinkedList<ItemType>::getNode(int position) const {
    assert(position >= 1 && position <= itemCount);
    Node<ItemType>* current = head;
    for(int i = 1; i < position; i++) {
        current = current->getNext();
    }
    return current;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& item) {
    if(position < 1 || position > itemCount + 1) {
        return false;
    }
    auto newItem = std::make_shared<Node<ItemType>>(newEntry);
    if(position == 1) {
        newItem->setNext(head);
        head = newItem;
    } else {
        auto previousPointer = getNode(position - 1);
        newItem->setNext(previousPointer->getNext());
        previousPointer->setNext(newItem);
    }
    itemCount++;
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    if(position < 1 || position > itemCount || isEmpty()) {
        return false;
    }
    if(position == 1) {
        head = head->getNext();
    } else {
        auto previousItem = getNode(position - 1);
        auto current = previousItem->getNext();
        previousItem->setNext(current->getNext());
    }
    current->setNext(nullptr);
    --itemCount;
    return true;
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    // since we are using smart pointers now we do not need to manually call delete on every node pointer in the list, the smart pointers will handle deallocation automatically
    head = nullptr;
    itemCount = 0;
}

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) {
    if(position > itemCount) {
        throw std::logic_error("replace at invalid position");
    }
    Node<ItemType>* newCurrent = new Node<ItemType>(newEntry);
    Node<ItemType>* current = nullptr;
    if(position == 1) {
        current = head;
        Node<ItemType>* next = current->getNext();
        newCurrent->setNext(next);
        head = newCurrent;
        head->setNext(nullptr);
    } else {
        Node<ItemType>* previous = getNode(position - 1);
        current = previous->getNext();
        newCurrent->setNext(current->getNext());
        previous->setNext(newCurrent);
        current->setNext(nullptr);
    }
    return current->getItem();
}

template<class ItemType>
auto LinkedList<ItemType>::insertNode(int position, std::shared_ptr<Node<ItemType>> newNodePointer, std::shared_ptr<Node<ItemType>> subChainPointer) {
    if(position == 1) {
        newNodePointer->setNext(subChainPointer);
        subChainPointer = newNodePointer;
        itemCount++;
    } else {
        Node<ItemType>* afterPointer = insertNode(position - 1, newNodePointer, subChainPointer->getNext());
        subChainPointer->setNext(afterPointer);
    }
    return subChainPointer;
}

template<class ItemType>
bool LinkedList<ItemType>::insertRecursion(int position, const ItemType& newItem) {
    if(position < 1 || position > itemCount + 1) {
        return false;
    }
    Node<ItemType>* newNodePointer = new Node<ItemType>(newItem);
    head = insertNode(position, newNodePointer, head);
    return true;
}