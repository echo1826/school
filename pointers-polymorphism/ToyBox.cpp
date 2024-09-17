#include "ToyBox.h"

template<class ItemType>
ToyBox<ItemType>::ToyBox() : boxColor(BLACK)
{
}  // end default constructor

template<class ItemType>
ToyBox<ItemType>::ToyBox(const Color& theColor) : boxColor(theColor)
{
}  // end constructor

template<class ItemType>
ToyBox<ItemType>::ToyBox(const ItemType& theItem, const Color& theColor)
    : PlainBox<ItemType>(theItem), boxColor(theColor)

{
}  // end constructor

template<class ItemType>
Color ToyBox<ItemType>::getColor() const
{
    return boxColor;
}  // end getColor
