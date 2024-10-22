#include <iostream>

#include "MagicBox.h"
#include "PlainBox.h"
#include "ToyBox.h"
// std smart pointers comes from the memory standard library
#include <memory>

void magicFunction();
void sharedPointersExample();
void uniquePointersExample();
void weakPointersExample();
void methods();

int main() {
  // raw pointers are the traditional c++ pointers which point to an address in
  // memory of where the value is stored
  int* rawPointer = nullptr;
  // downsides to these traditional pointers is when we look to deallocate the
  // memory, we have to have our program keep track of all aliases referencing
  // this same pointer and deallocate all of those references which takes a hit
  // in performance this would have to be a manual operation, calling delete on
  // all the pointers we no longer need in the application unlike other
  // programming languages
  delete rawPointer;

  // smart pointers (or managed pointers) act just like a raw pointer but when
  // we declare a smart pointer it has some automatic memory deallocation when
  // the compilier detects that the object is no longer needed (typically when
  // it goes out of scope or set to nullptr) 3 types of smart pointers,
  // shared_ptr (which provides shared ownership of an object, several instances
  // of this class can reference the same object), unique_ptr (provides unique
  // ownership of the object, no other smart pointer can reference the same
  // object), weak_ptr (provides a non-owning reference to the object that is
  // already managed by a shared pointer, this means that although it holds a
  // reference to the object, it does not hold priveleges to deallocate the
  // object memeory )

  magicFunction();

  return 0;
}

void magicFunction() {
  auto myMagicPtr = std::make_shared<MagicBox<std::string>>();
  std::cout << myMagicPtr->getItem() << "\n";
}

void sharedPointersExample() {
  // shared_ptr
  std::shared_ptr<MagicBox<std::string>> boxPtr(
      new MagicBox<
          std::string>());  // this method does 2 allocation operations, once
                            // for the object instantiation and another for the
                            // allocation of the memory object for the
                            // shared_ptr functionality to keep track of the
                            // amount of references to the object
  std::shared_ptr<MagicBox<std::string>> betterBoxPtr = std::make_shared<
      MagicBox<std::string>>();  // using the standard make_shared well create
                                 // both the object instance and the manager
                                 // object at the same time
  // for readability since the code above obscures the intent of code you can
  // use the auto to let the compilier determine the typing of the variable
  auto evenBetterBoxPtr = std::make_shared<MagicBox<std::string>>();

  // we can also create a shared_ptr without referencing an object quite yet
  std::shared_ptr<PlainBox<std::string>> myPlainPtr;
}

void uniquePointersExample() {
  // cannot assign a unique pointer to another pointer, i.e. if we were to copy
  // the unique pointer to another unique pointer using a copy constructor would
  // error out instead we have to transfer the ownership of the pointer using
  // std::move
  std::unique_ptr<MagicBox<std::string>> magicPtr(new MagicBox<std::string>());
  auto toyPtr = std::make_unique<ToyBox<std::string>>();  // c++ 14 and later
  std::unique_ptr<MagicBox<std::string>> fancyPtr;  // empty unique pointer

  // transferring ownership
  fancyPtr = std::move(magicPtr);
}

void weakPointersExample() {
  auto sharedPtr = std::make_shared<MagicBox<std::string>>();
  auto sharedPtr2 = sharedPtr;
  auto sharedPtr3 = sharedPtr;
  std::weak_ptr<MagicBox<std::string>> weakPtr = sharedPtr;
  auto weakPtr2 = weakPtr;
  // weak pointers can only observe the object and not use the object
  // weak pointers are not allowed to use * or -> meaning weakPtr->getItem()
  // will error out it can however see if the object still exists using the lock
  // method and if it does exist it will return a shared pointer to the object
  std::shared_ptr<MagicBox<std::string>> sharedPtr1 = weakPtr.lock();
  sharedPtr1->setItem("Rabbit");

  // when the object has been deallocated the lock method of the weak pointer
  // will return nullptr
}

void methods() {
  // reset method
  // mySmartPtr.reset(myOtherPtr); // equivalent to mySmartPtr = myOtherPtr
  // if we were to pass no arugment to reset then it will be set to nullptr

  // get method returns the reference to the object in a raw pointer
  auto myMagicPtr = std::make_shared<MagicBox<std::string>>();
  MagicBox<std::string>* rawPtr = myMagicPtr.get();
  // get should only be used when a library or legacy code does not work with
  // smart pointers

  // shared pointers methods
  // unique returns true if the shared pointer is the only owner of the managed
  // object use_count returns the number of references to the managed object
  auto magicPtr = std::make_shared<MagicBox<std::string>>();
  std::cout << magicPtr.unique() << "\n";     // displays true
  std::cout << magicPtr.use_count() << "\n";  // displays 1

  auto otherPtr = magicPtr;
  std::cout << magicPtr.unique() << "\n";     // displays false
  std::cout << magicPtr.use_count() << "\n";  // displays 2

  // unique pointer methods
  // can utilize unique pointers to manage dynamic arrays
  // MagicBox<std::string>* magicArray[] = new MagicBox<std::string>[MAX_SIZE]; can be rewritten as
  // std::unique_ptr<MagicBox<std::string>[]> magicArray = std::make_unique<MagicBox<std::string>>[MAX_SIZE];

}
