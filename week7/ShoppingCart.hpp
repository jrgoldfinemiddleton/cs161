/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 08/04/15
** Description: This header file is for the ShoppingCart
**              class.
**
**              A ShoppingCart stores a list of items and
**              allows items to be added.  It can also
**              determine the total price of the items on
**              the list.
**********************************************************/

#ifndef SHOPPING_CART_HPP
#define SHOPPING_CART_HPP

#define SIZE 100          // maximum size of list
#include "Item.hpp"       // needed for list items

class ShoppingCart {
  private:
    Item* itemList[SIZE]; // pointer-to-Item array
    int arrayEnd;         // next open index of itemList

  public:
    ShoppingCart();       // default constructor
    void addItem(Item *); // add an item to list
    double totalPrice();  // calculate total price of list items
};
#endif
