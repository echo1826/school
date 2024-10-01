#ifndef LIST_STACK_
#define LIST_STACK_

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class ListStack : public StackInterface<ItemType>
{
private:
	Node<ItemType>* topPointer;
public:
	ListStack();
	ListStack(const ListStack<ItemType>& stack);
	virtual ~ListStack();
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	ItemType peek() const;
};

#include "ListStack.cpp"
#endif