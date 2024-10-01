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
	if (top < DEFAULT_CAPACITY - 1) { // checks to make sure we haven't reached the max size of array and increase the top index to include the new item
		top++;
		items[top] = newEntry;
		result = true;
	}
	return result;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) { // checks if array is empty and reduce the top index by 1 so the last item falls out of scope
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