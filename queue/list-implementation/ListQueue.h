#ifndef LIST_QUEUE_
#define LIST_QUEUE_

#include "../QueueInterface.h"
#include "LinkedList.h"
#include <memory>

template<class ItemType>
class ListQueue : public QueueInterface<ItemType> {
    private:
        std::unique_ptr<LinkedList<ItemType>> listPtr;
    public:
        ListQueue();
        ListQueue(const ListQueue& queue);
        ~ListQueue();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        ItemType peekFront() const;
};

#include "ListQueue.cpp"
#endif