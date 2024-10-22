#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<class ItemType>
class DoubleNode {
    private:
        ItemType item;
        std::shared_ptr<DoubleNode<ItemType>> next;
        std::weak_ptr<DoubleNode<ItemType>> previous; // the previous pointer is a weak pointer because when we look to deallocate if this was a shared pointer and we invalidate this node by setting it to nullptr it would still have a reference to the previous node, thus we make it a weak_ptr so when the previous node head pointer gets invalidated this weak pointer will also be invalidated automatically
    public:
};

#endif