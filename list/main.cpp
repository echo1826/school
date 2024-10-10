#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"

int main() {
    ArrayList<int> list;
    for(int i = 1; i <=5; i++) {
        list.insert(i, i);
    }
    for(int i = 1; i <=5; i++) {
        
       std::cout << list.getEntry(i) << "\n";
    }

    try {
        std::cout << list.getEntry(6);
    } catch (std::logic_error const& except) {
        std::cout << "Failed to get position\n";
    }

    list.replace(3, 4);
    std::cout << list.getEntry(3) << "\n";

    list.remove(3);
    std::cout << list.getEntry(3) << "\n";

    list.clear();
    std::cout << list.getLength() << "\n";

    LinkedList<int> list2;
    for(int i = 1; i <=5; i++) {
        list2.insert(i, i);
    }
    for(int i = 1; i <=5; i++) {
        
       std::cout << list2.getEntry(i) << "\n";
    }

    try {
        std::cout << list2.getEntry(6);
    } catch (std::logic_error const& except) {
        std::cout << "Failed to get position\n";
    }

    list2.replace(3, 5);
    std::cout << list2.getEntry(3) << "\n";

    list2.remove(3);
    std::cout << list2.getEntry(3) << "\n";

    list2.clear();
    std::cout << list2.getLength() << "\n";
}

