#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <memory>

template<class ItemType>
class BinaryNode {
    private:
        ItemType item;
        std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
        std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;
    public:
        BinaryNode();
        BinaryNode(const ItemType& item);
        BinaryNode(const ItemType& item, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr);
        void setItem(const ItemType& item);
        ItemType getItem() const;
        bool isLeaf() const;
        auto getLeftChildPtr() const;
        auto getRightChildPtr const;
        void setLeftChild(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
        void setRightChild(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
};

#include "BinaryNode.cpp"
#endif