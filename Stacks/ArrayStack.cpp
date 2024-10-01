#include "ArrayStack.h"
#include <cassert>

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1) {}

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
	return top < 0;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry) {
	bool result = false;
	if (top < DEFAULT_CAPACITY - 1) {
		top++;
		items[top] = newEntry;
		result = true;
	}
	return result;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) {
		top--;
		result = true;
	}
	return result;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
	assert(!isEmpty());
	return items[top];
}