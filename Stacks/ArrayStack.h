#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6; // max capacity of array
	ItemType items[DEFAULT_CAPACITY]; // stack
	int top; // top of stack
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	ItemType peek() const;
};

#include "ArrayStack.cpp"
#endif