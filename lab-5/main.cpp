// Lab 5: Binary Trees & Binary Search Trees
// Due Date: Dec 15, 2024 11:59 PM

// Intro

// The goal of this lab is to get some experience working with the recursive implementations commonly used with tree data
// structures. Often times these recursive methods will return a new root or subtree that then gets applied by
// the calling function to either the left or right side of a node. This is the mechanism by which the whole tree
// is modified. Keep in mind these methods can return nullptr at various times, and we need to think about how the
// values come back together.

// Part 1: Finish implementing the two remove methods (marked with TODOs) for both the regular binary tree and the binary
//         search tree. A few extra references are provided. Feel free to use other sources as well.

// Part 2: Much of this code was taken from the text, but none of it has been tested. Write several tests for the basic
//         functionality of both tree types. Ensure a tree can be created. And make sure the add and remove methods
//         work as expected. Also make sure the clear and destructors are working properly.
//
//         Write the tests to your own satisfaction. But include your work and tests in your submission. You may need
//         to create methods to display a tree's contents. Don't forget to test edge cases like removing the root
//         node of a singleton tree containing only one value. You may use asserts or visual testing using console output.

// BONUS: Implement move constructors.

// Turn in this one file with finished implementations and tests into blackboard.

#include <iostream>
#include <memory>

template<class ItemType>
class BinaryNode
{
private:
    ItemType                              item;          // Data portion

    std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;  // Pointer to left child
    std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; // Pointer to right child

public:
    BinaryNode() : item{}, leftChildPtr(nullptr), rightChildPtr(nullptr) { }
    explicit BinaryNode(const ItemType& anItem) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {}

    BinaryNode(const ItemType& anItem,
               std::shared_ptr<BinaryNode<ItemType>> leftPtr,
               std::shared_ptr<BinaryNode<ItemType>> rightPtr) : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) {
    }

    void setItem(const ItemType& anItem) {
        item = anItem;
    }
    ItemType getItem() const {
        return item;
    }

    bool isLeaf() const {
        return leftChildPtr == nullptr && rightChildPtr == nullptr;
    }

    auto getLeftChildPtr() const {
        return leftChildPtr;
    }
    auto getRightChildPtr() const {
        return rightChildPtr;
    }

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr) {
        leftChildPtr = leftPtr;
    }
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
        rightChildPtr = rightPtr;
    }
}; // end BinaryNode

template<class ItemType>
class BinaryTreeInterface
{
public:
    /** Tests whether this binary tree is empty.
     @return  True if the binary tree is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Gets the height of this binary tree.
     @return  The height of the binary tree. */
    virtual int getHeight() const = 0;

    /** Gets the number of nodes in this binary tree.
     @return  The number of nodes in the binary tree. */
    virtual int getNumberOfNodes() const = 0;

    /** Gets the data that is in the root of this binary tree.
     @pre  The binary tree is not empty.
     @post  The root's data has been returned, and the binary tree is unchanged.
     @return  The data in the root of the binary tree. */
    virtual ItemType getRootData() const = 0;

    /** Replaces the data in the root of this binary tree with the given data,
     if the tree is not empty. However, if the tree is empty, inserts a new
     root node containing the given data into the tree.
     @pre  None.
     @post  The data in the root of the binary tree is as given.
     @param newData  The data for the root. */
    virtual void setRootData(const ItemType& newData) = 0;

    /** Adds the given data to this binary tree.
     @param newData  The data to add to the binary tree.
     @post  The binary tree contains the new data.
     @return  True if the addition is successful, or false if not. */
    virtual bool add(const ItemType& newData) = 0;

    /** Removes the specified data from this binary tree.
     @param target  The data to remove from the binary tree.
     @return  True if the removal is successful, or false if not. */
    virtual bool remove(const ItemType& target) = 0;

    /** Removes all data from this binary tree. */
    virtual void clear() = 0;

    /** Tests whether the specified data occurs in this binary tree.
     @post  The binary tree is unchanged.
     @param target  The data to find.
     @return  True if data matching the target occurs in the tree, or false if not. */
    virtual bool contains(const ItemType& target) const = 0;

    /** Traverses this binary tree in preorder (inorder, postorder) and
        calls the function visit once for each node.
     @param visit  A client-defined function that performs an operation on
        either each visited node or its data. */
    virtual void preorderTraverse(void visit(ItemType&)) const = 0;
    virtual void inorderTraverse(void visit(ItemType&)) const = 0;
    virtual void postorderTraverse(void visit(ItemType&)) const = 0;

    /** Destroys this tree and frees its assigned memory. */
    virtual ~BinaryTreeInterface() = default;
}; // end BinaryTreeInterface

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
    {
        if (subTreePtr == nullptr)
            return 0;
        else
            return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }  // end getHeightHelper

    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
        if (subTreePtr == nullptr)
            return 0;
        else
            return 1 + getHeightHelper(subTreePtr->getLeftChildPtr()) + getHeightHelper(subTreePtr->getRightChildPtr());
    }

    // Recursively adds a new node to the tree in a left/right fashion to keep tree balanced.
    auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
    {
        if (subTreePtr == nullptr)
            return newNodePtr;
        else
        {
            auto leftPtr = subTreePtr->getLeftChildPtr();
            auto rightPtr = subTreePtr->getRightChildPtr();

            if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
            {
                rightPtr = balancedAdd(rightPtr, newNodePtr);
                subTreePtr->setRightChildPtr(rightPtr);
            }
            else
            {
                leftPtr = balancedAdd(leftPtr, newNodePtr);
                subTreePtr->setLeftChildPtr(leftPtr);
            }  // end if

            return subTreePtr;
        }  // end if
    }  // end balancedAdd

    // Here is one way of going about it: https://www.geeksforgeeks.org/deletion-binary-tree/
    //
    // Another would be to swap the values of the node to a leaf, then delete the leaf. Which child you decide to
    // swap to would affect the shape of the resulting tree. Best to remove from the subtree with the greater height
    // for a more balanced result.
    //
    // Removes the target value from the tree.
    virtual std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                              const ItemType target, bool & isSuccessful) {
        // TODO
        return nullptr;
    }

    // Recursively searches for target value. Searches depth first, left to right.
    // Returns the node containing the first occurrence of target value.
    std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const {
        if(treePtr == nullptr || treePtr->getItem() == target) {
            return treePtr;
        }

        auto foundLeft = findNode(treePtr->getLeftChildPtr(), target);
        if(foundLeft != nullptr) {
            return foundLeft;
        }

        return findNode(treePtr->getLeftChildPtr(), target);
    }

    // Copies the tree rooted at treePtr and returns a pointer to the root of the copy.
    std::shared_ptr<BinaryNode<ItemType>> copyTree(
            const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
    {
        std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

        // Copy tree nodes during a preorder traversal
        if (oldTreeRootPtr != nullptr)
        {
            // Copy node
            newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(),
                    nullptr, nullptr);
            newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
            newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
        }  // end if
        // Else tree is empty (newTreePtr is nullptr)

        return newTreePtr;
    }  // end copyTree

    // Recursive traversal helper methods:
    void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
        if (treePtr != nullptr)
        {
            ItemType theItem = treePtr->getItem();
            visit(theItem);
            inorder(visit, treePtr->getLeftChildPtr());
            inorder(visit, treePtr->getRightChildPtr());
        }
    }

    void inorder(void visit(ItemType&),
            std::shared_ptr<BinaryNode<ItemType>> treePtr) const
    {
        if (treePtr != nullptr)
        {
            inorder(visit, treePtr->getLeftChildPtr());
            ItemType theItem = treePtr->getItem();
            visit(theItem);
            inorder(visit, treePtr->getRightChildPtr());
        }
    }

    void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
        if (treePtr != nullptr)
        {
            inorder(visit, treePtr->getLeftChildPtr());
            inorder(visit, treePtr->getRightChildPtr());
            ItemType theItem = treePtr->getItem();
            visit(theItem);
        }
    }

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinaryNodeTree() : rootPtr(nullptr)
    {
    }  // end default constructor

    explicit BinaryNodeTree(const ItemType& rootItem) : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
    {
    } // end constructor

    BinaryNodeTree(const ItemType& rootItem,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
            : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                             copyTree(leftTreePtr->rootPtr),
                                                             copyTree(rightTreePtr->rootPtr)))
    {
    } // end constructor

    BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
    {
        rootPtr = copyTree(treePtr.rootPtr);
    }  // end copy constructor

    virtual ~BinaryNodeTree() = default;

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
    [[nodiscard]] bool isEmpty() const {
        return rootPtr == nullptr;
    }
    [[nodiscard]] int getHeight() const {
        return getHeightHelper(rootPtr);
    }
    [[nodiscard]] int getNumberOfNodes() const {
        return getNumberOfNodesHelper(rootPtr);
    }

    ItemType getRootData() const {
        if(isEmpty()) {
            throw std::exception();
        }
        return rootPtr->getItem();
    }

    void setRootData(const ItemType& newData) {
        if (isEmpty()) {
            rootPtr = std::make_shared<BinaryNode<ItemType>>(newData);
        } else {
            rootPtr->setItem(newData);
        }
    }

    bool add(const ItemType& newData) {
        auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
        rootPtr = balancedAdd(rootPtr, newNodePtr);

        return true;
    }  // end add

    bool remove(const ItemType& data) {
        bool removed;
        rootPtr = removeValue(rootPtr, data, removed);
        return removed;
    }

    void clear() {
        rootPtr = nullptr;
    }

    bool contains(const ItemType& anEntry) const {
        return findNode(rootPtr, anEntry) != nullptr;
    }

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const {
        preorder(visit, rootPtr);
    }
    void inorderTraverse(void visit(ItemType&)) const {
        inorder(visit, rootPtr);
    }
    void postorderTraverse(void visit(ItemType&)) const {
        postorder(visit, rootPtr);
    }

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinaryNodeTree& operator=(const BinaryNodeTree& other) {
        if(this == &other) {
            return *this;
        }

        rootPtr = copyTree(other.rootPtr);

        return *this;
    }
}; // end BinaryNodeTree

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    //    Protected Utility Methods Section:
    //    Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Places a given new node at its proper position in this binary
    // search tree.
    auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr) {
        if(subTreePtr == nullptr) {
            return newNodePtr;
        }
        else if(subTreePtr->getItem() > newNodePtr->getItem()) {
            auto tmpPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
            subTreePtr->setLeftChildPtr(tmpPtr);
        } else {
            auto tmpPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
            subTreePtr->setRightChildPtr(tmpPtr);
        }
        return subTreePtr;
    }

    // Note we are overriding this from the base class.
    // Removes the given target value from the tree while maintaining a binary search tree.
    std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                              const ItemType target, bool & isSuccessful) override {
        if(subTreePtr == nullptr) {
            isSuccessful = false;
        }
        else if(subTreePtr->getItem() == target) {
            subTreePtr = removeNode(subTreePtr);
            isSuccessful = true;
        }
        else if(subTreePtr->getItem() > target) {
            auto tmpPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
            subTreePtr->setLeftChildPtr(tmpPtr);
        }
        else {
            auto tmpPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
            subTreePtr->setRightChildPtr((tmpPtr));
        }

        return subTreePtr;
    }

    // REF: https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
    std::shared_ptr<BinaryNode<ItemType>> findInOrderSuccessor(std::shared_ptr<BinaryNode<ItemType>> node) {
        node = node->getRightChildPtr();
        while(node != nullptr && node->getLeftChildPtr() != nullptr) {
            node = node->getLeftChildPtr();
        }
        return node;
    }

    // Additional Reference: https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
    //
    // Hint: In order to delete a leaf node, we return nullptr. Because we are using smart pointers it will lose
    //       all it's references and clean itself up.
    //
    // Removes a given node from a tree while maintaining a binary search tree.
    std::shared_ptr<BinaryNode<ItemType>> removeNode(std::shared_ptr<BinaryNode<ItemType>> node) {
        // TODO
        if(node->getLeftChildPtr() == nullptr) {
            auto rightNode = node->getRightChildPtr();
            delete node;
            return rightNode;
        }
        if(node->getRightChildPtr() == nullptr) {
            auto leftNode = node->getLeftChildPtr();
            delete node;
            return leftNode;
        }

        auto currentNode = node->getRightChildPtr();
        while(currentNode != nullptr && currentNode->getLeftChildPtr() != nullptr) {
            currentNode = current->getLeftChildPtr();
        }
        node->setRightChildPtr(removeNode(node->getRightChildPtr()));
        return node;
    }

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree() : BinaryNodeTree<ItemType>() {}
    explicit BinarySearchTree(const ItemType& rootItem) : BinaryNodeTree<ItemType>(rootItem) {};
    BinarySearchTree(const BinarySearchTree<ItemType>& tree) : BinarySearchTree<ItemType>(tree) {}
    virtual ~BinarySearchTree() = default;

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    void setRootData(const ItemType& newData) override {
        throw std::logic_error("Cannot set root item on a BST.");
    }

    bool add(const ItemType& newData) override {
        auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
        rootPtr = placeNode(rootPtr, newNodePtr);
        return true;
    }

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinarySearchTree<ItemType>&
    operator=(const BinarySearchTree<ItemType>& other) {
        if(this == &other) {
            return *this;
        }

        rootPtr = copyTree(other.rootPtr);

        return *this;
    }
}; // end BinarySearchTree

int main() {
    // Place and run your tests here.
    BinarySearchTree bst = BinarySearchTree<int>(1);
    for(int i = 1; i <= 5; i++) {
        bst.add(i);
    }
    return 0;
}
