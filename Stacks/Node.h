#ifndef NODE_
#define NODE_

template <class ItemType>
class Node {
private:
	ItemType item;
	Node<ItemType>* next;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType&, Node<ItemType>* nextNode);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNode);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};

#include "Node.cpp"
#endif

