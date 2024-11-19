#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;
    // to call the overloaded operator you may to it 2 ways
    if(list1.operator==(list2)) {
        std::cout << "They are equal\n";
    }
    if(list1 == list2) {
        std::cout << "they are equal\n";
    }
    list1.insert(1, 1);
    list1.insert(2, 2);
    // overloaded the << operator in order for it to display the LinkedList correctly
    std::cout << list1;
    return 0;
}