#include "LinkedQueue.h"

#include <memory>

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : head(nullptr), tail(nullptr) {}

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& queue)
    : head(queue.head), tail(queue.tail) {}

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
  return head == nullptr;
}

template <class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& entry) {
  auto newNode = std::make_shared<Node<ItemType>>(entry);
  if (isEmpty()) {
    head = newNode;
  } else {
    tail->setNext(newNode);
  }
  tail = newNode;
  return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    bool result = false;
    if(!isEmpty()) {
        auto deleteNode = head;
        if(head == tail) {
            head.reset();
            tail.reset();
        } else {
            head = head->getNext();
        }
        deleteNode->setNext(nullptr);
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    if(!isEmpty()) {
        return head->getItem();
    }
    return NULL;
}