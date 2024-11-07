#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "../QueueInterface.h"
#include "../Node.h"
#include <memory>

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
    private:
        std::shared_ptr<Node<ItemType>> head;
        std::shared_ptr<Node<ItemType>> tail;
    public:
        LinkedQueue();
        LinkedQueue(const LinkedQueue& queue);
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        ItemType peekFront() const;
};

#include "LinkedQueue.cpp"
#endif