#include <iostream>
#include "MagicBox.h"
#include "PlainBox.h"
// std smart pointers comes from the memory standard library
#include <memory>

void magicFunction() {
    auto myMagicPtr = std::make_shared<MagicBox<std::string>>();
    std::cout << myMagicPtr->getItem() << "\n";
}

int main() {
    // raw pointers are the traditional c++ pointers which point to an address in memory of where the value is stored
    int* rawPointer = nullptr; 
    // downsides to these traditional pointers is when we look to deallocate the memory, we have to have our program keep track of all aliases referencing this same pointer and deallocate all of those references which takes a hit in performance
    // this would have to be a manual operation, calling delete on all the pointers we no longer need in the application unlike other programming languages
    delete rawPointer;

    // smart pointers (or managed pointers) act just like a raw pointer but when we declare a smart pointer it has some automatic memory deallocation when the compilier detects that the object is no longer needed (typically when it goes out of scope or set to nullptr)
    // 3 types of smart pointers, shared_ptr (which provides shared ownership of an object, several instances of this class can reference the same object), unique_ptr (provides unique ownership of the object, no other smart pointer can reference the same object), weak_ptr (provides a non-owning reference to the object that is already managed by a shared pointer, this means that although it holds a reference to the object, it does not hold priveleges to deallocate the object memeory )

    // shared_ptr
    std::shared_ptr<MagicBox<std::string>> boxPtr(new MagicBox<std::string>()); // this method does 2 allocation operations, once for the object instantiation and another for the allocation of the memory object for the shared_ptr functionality to keep track of the amount of references to the object
    std::shared_ptr<MagicBox<std::string>> betterBoxPtr = std::make_shared<MagicBox<std::string>>(); // using the standard make_shared well create both the object instance and the manager object at the same time
    // for readability since the code above obscures the intent of code you can use the auto to let the compilier determine the typing of the variable
    auto evenBetterBoxPtr = std::make_shared<MagicBox<std::string>>();

    // we can also create a shared_ptr without referencing an object quite yet
    std::shared_ptr<PlainBox<std::string>> myPlainPtr;

    magicFunction();

    return 0;
}