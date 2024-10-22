#ifndef PLAIN_BOX_
#define PLAIN_BOX_
#include "BoxInterface.h"

template<class ItemType> // Indicates this is a template definition

// Declaration for the class PlainBox
class PlainBox : public BoxInterface<ItemType>
{
private:
	// Data field
	ItemType item;

public:
	// Default constructor
	PlainBox();

	// Parameterized constructor
	PlainBox(const ItemType& theItem);

	// Mutator method that can change the value of the data field
	virtual void setItem(const ItemType& theItem); // virtual methods can be overridden for other derived classes to redefine its implementation

	// Accessor method to get the value of the data field
	virtual ItemType getItem() const;
}; // end PlainBox

#include "PlainBox.cpp" // Include the implementation file
#endif
