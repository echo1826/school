#ifndef NODE_
#define NODE_
#include <memory>

template <class ItemType>
class Node {
private:
	ItemType item;
	std::shared_ptr<Node<ItemType>> next; // can now use smart pointer for the next pointer on the node object
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType&, std::shared_ptr<Node<ItemType>> nextNode);
	void setItem(const ItemType& anItem);
	void setNext(std::shared_ptr<Node<ItemType>> nextNode);
	ItemType getItem() const;
	auto getNext() const; // let the compilier determine what getNext will return which will be a smart pointer of the next node
};

#include "Node.cpp"
#endif

