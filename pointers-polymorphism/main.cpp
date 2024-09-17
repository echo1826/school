#include <iostream>
#include "MagicBox.h"
#include "PlainBox.h"
#include "ToyBox.h"

class GoodMemoryWithString {
    private:
        std::string* strPointer; // string pointer
    public:
        GoodMemoryWithString() : strPointer(new std::string("foo")) { // constructor that intializes the string pointer to "foo"
            std::cout << "Constructed" << std::endl;
        } 
        ~GoodMemoryWithString() { // destructor that unallocates the pointer memory from free memory
            std::cout << "Destructed" << std::endl;
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

void memoryLeak() {
    MagicBox<std::string>* magicBoxPointer = new MagicBox<std::string>();
    MagicBox<std::string>* otherMagicBoxPointer = new MagicBox<std::string>();
    otherMagicBoxPointer = magicBoxPointer; // results in a memory leak as otherMagicBoxPointer was instantiated with a seperate instant of magic box and no longer has access to it on the heap (free memory)
}

void test() {
    GoodMemoryWithString array;
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
    std::cout << plainBoxPointer->getItem() << std::endl;

    MagicBox<std::string>* magicBoxPointer = new MagicBox<std::string>();
    placeInBox(magicBoxPointer, hammerItem);
    placeInBox(magicBoxPointer, specialItem);
    std::cout << magicBoxPointer->getItem() << std::endl;

    // deallocate memory from free memory to prevent memory leaks
    delete magicBoxPointer;
    // preventing dangling pointers by assigning the deallocated pointers to the nullptr address rather than the previous address that was deallocated
    magicBoxPointer = nullptr;

    delete plainBoxPointer;
    plainBoxPointer = nullptr;
}

void dynamicArrays() {
    // this is a static array
    const int MAX_SIZE = 50;
    double myArray[MAX_SIZE];

    // we can create dynamically sized arrays by using pointers
    int arraySize = 50;
    double* arr = new double[arraySize];
    // copy existing pointer
    double* oldArray = arr;
    // re-initialize old array pointer to the new size
    arr = new double[2 * arraySize];
    // copy the contents from the old pointer to the new array
    for (int i = 0; i < arraySize; i++) {
        arr[i] = oldArray[i];
    }
    // deallocate the oldArray (temp) ponter
    delete[] oldArray;

    // how to deallocate memory of an array pointer
    delete[] arr;
}

int main() {
    test();
    testBoxes();
    dynamicArrays();
}