#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType> {
private:
	Node<ItemType>* headPointer; // pointer of the first node in linked list
	int itemCount; // current count of bag items
	Node<ItemType>* getPointerToTarget(const ItemType& target) const; // returns either a pointer to the node containing a given entry or the null pointer if the entry is not in the bag
public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>& bag); // copy constructor
	virtual ~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& entry);
	void clear();
	bool contains(const ItemType& entry) const;
	int getFrequencyOf(const ItemType& entry) const;
	std::vector<ItemType> toVector() const;
	//std::vector<ItemType> toVectorRecursion() const;
};

#include "LinkedBag.cpp"
#endif