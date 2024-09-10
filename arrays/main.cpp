#include <iostream>
#include <string>
#include <vector>
#include "ArrayBag.h"

void displayBag(ArrayBag<std::string>& bag) {
    std::cout << "The bag contains " << bag.getCurrentSize() << " items:" << std::endl;
    std::vector<std::string> bagItems = bag.toVector();

    int numEntries = (int)bagItems.size();
    for (int i = 0; i < numEntries; i++) {
        std::cout << bagItems[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

void bagTest(ArrayBag<std::string>& bag) {
    std::cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << std::endl;
    displayBag(bag);

    std::string items[] = { "one", "two", "three", "four", "five", "one" };
    std::cout << "Add 6 items to the bag: " << std::endl;

    for (int i = 0; i < 6; i++) {
        bag.add(items[i]);
    }
    displayBag(bag);

    std::cout << "Checking for instances of one in the bag: " << bag.getFrequencyOf("one") << std::endl;

    std::cout << "Searching for three (should return 1 (true)): " << bag.contains("three") << std::endl;

    std::cout << "Removing an instance of one in the bag: " << bag.remove("one") << std::endl;
    displayBag(bag);

    std::cout << "Clearing the bag now..." << std::endl;
    bag.clear();
    displayBag(bag);
}

int main() {
    ArrayBag<std::string> bag;
    std::cout << "Testing the Array-Based bag:" << std::endl;
    bagTest(bag);
    return 0;
}