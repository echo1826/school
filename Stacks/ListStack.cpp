#include "ListStack.h"
#include <cassert>

template<class ItemType>
ListStack<ItemType>::ListStack() : topPointer(nullptr) {}

template<class ItemType>
ListStack<ItemType>::ListStack(const ListStack<ItemType>& stack) { // copy constructor to copy a stack over entirely
	Node<ItemType>* originalStackPointer = stack.topPointer;
	if (originalStackPointer == nullptr) {
		topPointer = nullptr;
	}
	else {
		topPointer = new Node<ItemType>();
		topPointer->setItem(originalStackPointer->getItem());

		Node<ItemType>* newStackPointer = topPointer;

		originalStackPointer = originalStackPointer->getNext();

		while (originalStackPointer != = nullptr) {
			ItemType nextItem = originalStackPointer->getItem();
			Node<ItemType>* newNodePointer = new Node<ItemType>(nextItem);
			newStackPointer->setNext(newNodePointer);
			newStackPointer = newStackPointer->getNext();
			originalStackPointer->getNext();
		}
		newStackPointer->setNext(nullptr);
	}
}

template<class ItemType>
ListStack<ItemType>::~ListStack() { // destructor to deallocate the stack memory
	while (!isEmpty()) {
		pop();
	}
}

template<class ItemType>
bool ListStack<ItemType>::push(const ItemType& newItem) {
	Node<ItemType>* newNodePointer = new Node<ItemType>(newItem, topPointer); // node constructor handles assigning the new top pointer's next to the original top pointer
	topPtr = newNodePtr;
	newNodePtr = nullptr;
	return true;
}

template<class ItemType>
bool ListStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) {
		Node<ItemType>* nodeToDeletePointer = topPointer; // temp location to hold the pointer to delete
		topPointer = topPointer->getNext(); // reassign the top pointer to the next item in list
		nodeToDeletePointer->setNext(nullptr); // break the pointer to delete connection to the stack
		delete nodeToDeletePointer;
		nodeToDeletePointer = nullptr;
		result = true;
	}
	return result;
}

template<class ItemType>
ItemType ListStack<ItemType>::peek() const {
	assert(!isEmpty());
	return topPtr->getItem();
}

template<class ItemType>
bool ListStack<ItemType>::isEmpty() const {
	return topPointer == nullptr;
}