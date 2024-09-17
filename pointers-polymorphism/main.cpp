#include <iostream>
#include "MagicBox.h"
#include "PlainBox.h"
#include "ToyBox.h"

class GoodMemoryWithArray {
    private:
        std::string* strPointer; // string pointer
    public:
        GoodMemoryWithArray() : strPointer(new std::string("foo")) { // constructor that intializes the string pointer to "foo"
            std::cout << "Constructed";
        } 
        ~GoodMemoryWithArray() { // destructor that unallocates the pointer memory from free memory
            std::cout << "Destructed";
            delete strPointer; 
            strPointer = nullptr; // after deallocating memory from pointer, set pointer to the nullptr reference so we know it's not usable anymore
        }

        void setString(std::string value) {
            strPointer->assign(value); // the -> syntax is how a pointer variable calls methods available to itself (think dot notation for regular object variables)
            // assign is a built in string method to assign a value to the string variable
        }

        std::string& getString() const {
            return *strPointer; // the * de-references the pointer and only returns the value of the pointer and not the memory address like it normally holds
        }

};

void test() {
    GoodMemoryWithArray array;
    array.setString(std::string("bar"));
}

void placeInBox(PlainBox<std::string>* box, std::string item) {
    box->setItem(item);
}

void testBoxes() {
    std::string specialItem = "Riches beyond compare!";
    std::string hammerItem = "Hammer";

    PlainBox<std::string>* plainBoxPointer = new PlainBox<std::string>();
    placeInBox(plainBoxPointer, hammerItem);
    placeInBox(plainBoxPointer, specialItem);

    MagicBox<std::string>* magicBoxPointer = new MagicBox<std::string>();
    placeInBox(magicBoxPointer, hammerItem);
    placeInBox(magicBoxPointer, specialItem);

}

int main() {
    test();
}