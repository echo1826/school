#include "ListQueue.h"

#include <cassert>
#include <memory>

template <class ItemType>
ListQueue<ItemType>::ListQueue()
    : listPtr(std::make_unique<LinkedList<ItemType>>) {}

template <class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& queue)
    : listPtr(queue.listPtr) {}

template <class ItemType>
ListQueue<ItemType>::~ListQueue() {}

template <class ItemType>
bool ListQueue<ItemType>::isEmpty() const {
  return listPtr->isEmpty();
}

template <class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& entry) {
  return listPtr->insert(listPtr->getLength() + 1, entry);
}

template <class ItemType>
bool ListQueue<ItemType>::dequeue() {
  return listPtr->remove(1);
}

template <class ItemType>
ItemType ListQueue<ItemType>::peekFront() const {
  assert(!listPtr->isEmpty());
  return listPtr->getEntry(1);
}