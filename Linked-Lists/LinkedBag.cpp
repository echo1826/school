#include "LinkedBag.h"

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : itemCount(0), headPointer(nullptr) {}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& bag) {
	itemCount = bag.itemCount;
	Node<ItemType>* originalChainPointer = bag.headPointer;
	if (originalChainPointer == nullptr) {
		headPointer = nullptr;
	}
	else {
		headPointer = new Node<ItemType>();
		headPointer->setItem(originalChainPointer->getItem());
		Node<ItemType>* newChainPointer = headPointer;
		originalChainPointer = originalChainPointer->getNext();
		while (originalChainPointer != nullptr) {
			ItemType nextItem = originalChainPointer->getItem();
			Node<ItemType>* newNodePointer = new Node<ItemType>(nextItem);
			newChainPointer->setNext(newNodePointer);

			newChainPointer = newChainPointer->getNext();
			newChainPointer = originalChainPointer->getNext();
		}
		newChainPointer->setNext(nullptr);
	}
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
	clear();
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& entry) {
	Node<ItemType>* newNodePointer = new Node<ItemType>();
	newNodePointer->setItem(entry);
	newNodePointer->setNext(headPointer);
	headPointer = newNodePointer;
	itemCount++;
	return true;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
	Node<ItemType>* currentPointer = headPointer;
	std::vector<ItemType> contents;
	while (currentPointer != nullptr) {
		contents.push_back(currentPointer->getItem());
		currentPointer = currentPointer->getNext();
	}
	return contents;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& item) const {
	Node<ItemType>* current = headPointer;
	int frequency = 0;
	while (current != nullptr) {
		if (current->getItem() == item) {
			frequency++;
		}
		current = current->getNext();
	}
	return frequency;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerToTarget(const ItemType& target) const {
	
	Node<ItemType>* current = headPointer;
	while (current != nullptr) {
		if (target == current->getItem()) {
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& target) const {
	return getPointerToTarget(target) != nullptr;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& target) {
	Node<ItemType>* entryPointer = getPointerToTarget(target);
	if (!isEmpty() && (entryPointer != nullptr)) {
		entryPointer->setItem(headPointer->getItem());

		Node<ItemType>* nodeToDelete = headPointer;
		headPointer = headPointer->getNext();

		nodeToDelete->setNext(nullptr);
		delete nodeToDelete;
		nodeToDelete = nullptr;

		itemCount--;
		return true;
	}
	return false;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
	Node<ItemType>* deletePointer = headPointer;
	while (headPointer != nullptr) {
		headPointer = headPointer->getNext();
		delete deletePointer;
		deletePointer = headPointer;
	}
	itemCount = 0;
}