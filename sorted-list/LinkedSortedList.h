#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_

#include <memory>

#include "Node.h"
#include "SortedListInterface.h"

template <class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType> {
 private:
  std::shared_ptr<Node<ItemType>> headPointer;
  int itemCount;
  auto getNodeBefore(const ItemType& entry) const;
  auto getNodeAt(int position) const;
  auto copyChain(const std::shared_ptr<Node<ItemType>>& head);

 public:
  LinkedSortedList();
  LinkedSortedList(const LinkedSortedList<ItemType>& list);
  virtual ~LinkedSortedList();
  bool insertSorted(const ItemType& newEntry);
  bool removeSorted(const ItemType& entry);
  int getPosition(const ItemType& entry) const;
  bool isEmpty() const;
  int getLength() const;
  bool remove(int position);
  void clear();
  ItemType getEntry(int position) const;
};

#include "LinkedSortedList.cpp"
#endif