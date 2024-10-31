#include "LinkedSortedList.h"

#include <cassert>

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList()
    : headPointer(nullptr), itemCount(0) {}

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(
    const LinkedSortedList<ItemType>& list) {
  headPointer = copyChain(list.headPointer);
  itemCount = list.itemCount;
}

template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList() {
  clear();
}

template <class ItemType>
auto LinkedSortedList<ItemType>::copyChain(
    const std::shared_ptr<Node<ItemType>>& head) {
  std::shared_ptr<Node<ItemType>> copyPointer;
  if (head != nullptr) {
    copyPointer = std::make_shared<Node<ItemType>>(head->getItem());
    copyPointer->setNext(copyChain(head->getNext()));
  }
  return copyPointer;
}

template <class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const {
  assert(position >= 1 && position <= itemCount);
  auto current = headPointer;
  for (int i = 1; i < position; i++) {
    current = current->getNext();
  }
  return current;
}

template <class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& entry) const {
  auto current = headPointer;
  std::shared_ptr<Node<ItemType>> previous;
  while (current != nullptr && entry > current->getItem()) {
    previous = current;
    current = current->getNext();
  }
  return previous;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {
  bool ableToRemove = position >= 1 && position <= itemCount;
  if (ableToRemove) {
    std::shared_ptr<Node<ItemType>> current;
    if (position == 1) {
      current = headPointer;
      headPointer->getNext();
    } else {
      auto previous = getNodeAt(position - 1);
      current = previous->getNext();
      previous->setNext(current->getNext());
    }
    itemCount--;
  }
  return ableToRemove;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {
  return itemCount > 0;
}

template <class ItemType>
void LinkedSortedList<ItemType>::clear() {
  while (!isEmpty()) {
    remove(1);
  }
}

template <class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& item) {
  auto newNode(std::make_shared<Node<ItemType>>(item));
  auto previous = getNodeBefore(item);
  if (isEmpty() || previous == nullptr) {
    newNode->setNext(headPointer);
    headPointer = newNode;
  } else {
    auto after = previous->getNext();
    newNode->setNext(after);
    previous->setNext(newNode);
  }
  itemCount++;
  return true;
}

template <class ItemType>
int LinkedSortedList<ItemType>::getLength() const {
  return itemCount;
}

template <class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const {
  assert(position > 0 && position <= itemCount);
  auto node = getNodeAt(position);
  return node->getItem();
}

template <class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& entry) const {
  int position = 1;
  while (position <= itemCount) {
    if (getEntry(position) == entry) {
      return position;
    }
  }
  return -position;
}

template <class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& entry) {
  int position = getPosition(entry);
  if (position > 0) {
    return remove(position);
  }
  return false;
}