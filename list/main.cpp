#include <iostream>
#include "ArrayList.h"

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
}

