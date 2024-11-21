#ifndef BINARY_TREE_INTERFACE_
#define BINARY_TREE_INTERFACE_

template<class ItemType>
class BinaryTreeInterface {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getHeight() const = 0;
        virtual ItemType getRootData() const = 0;
        virtual void setRoot(const ItemType& newData) = 0;
        virtual bool add(const ItemType& newData) = 0;
        virtual bool remove(const ItemType& target) = 0;
        virtual void clear() = 0;
        virtual ItemType getEntry(const ItemType& target) const = 0;
        virtual bool contains(const ItemType& target) const = 0;
        virtual void preorderTraverse(void action(ItemType&)) const = 0;
        virtual void inorderTraverse(void action(ItemType&)) const = 0;
        virtual void postorderTraverse(void action(ItemType&)) const = 0;

        virtual ~BinaryTreeInterface() {};
};

#endif