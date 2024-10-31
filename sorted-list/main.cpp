#include "LinkedSortedList.h"
#include <iostream>

int main() {
    LinkedSortedList<int> list;
    list.insertSorted(1);
    std::cout << list.getEntry(1) << "\n";
    return 0;
}