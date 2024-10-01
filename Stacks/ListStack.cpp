#include "ListStack.h"
#include <cassert>

template<class ItemType>
ListStack<ItemType>::ListStack() : topPointer(nullptr) {}

template<class ItemType>
ListStack<ItemType>::ListStack(const ListStack<ItemType>& stack) {
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
ListStack<ItemType>::~ListStack() {
	while (!isEmpty()) {
		pop();
	}
}

template<class ItemType>
bool ListStack<ItemType>::push(const ItemType& newItem) {
	Node<ItemType>* newNodePointer = new Node<ItemType>(newItem, topPointer);
	topPtr = newNodePtr;
	newNodePtr = nullptr;
	return true;
}

template<class ItemType>
bool ListStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) {
		Node<ItemType>* nodeToDeletePointer = topPointer;
		topPointer = topPointer->getNext();
		nodeToDeletePointer->setNext(nullptr);
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