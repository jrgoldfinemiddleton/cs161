/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 08/04/15
** Description: This file contains the ShoppingCart class
**              function implementation.
**********************************************************/
#include "Item.hpp"
#include "ShoppingCart.hpp"
#include <iostream>         // needed to print out

using std::cout;
using std::endl;


/*********************************************************************
 ** Description: Constructs an empty ShoppingCart containing pointers
 **              to no Item.
 *********************************************************************/

ShoppingCart::ShoppingCart() {
  Item** ptr;   // pointer to pointer to Item

  // point all elements of array to NULL
  for (ptr = itemList; ptr < itemList + SIZE; ptr++) {
    *ptr = NULL;
  }

  // indicate ShoppingCart contains no Items
  arrayEnd = 0;
}


/*********************************************************************
 ** Description: Adds a pointer-to-Item to this ShoppingCart.  It does
 **              nothing if this list is full (contains 100 Item
 **              pointers).
 *********************************************************************/

void ShoppingCart::addItem(Item *item) {
  // if list is not full, add item and move to the next open position
  if (arrayEnd < SIZE) {
    itemList[arrayEnd++] = item;
  }
}


/*********************************************************************
 ** Description: Calculates and returns the total price of the items
 **              in this ShoppingCart.
 *********************************************************************/

double ShoppingCart::totalPrice() {
  Item** item;        // pointer to current pointer to Item
  double total = 0.0; // accumulator

  // deference twice to get each Item and add its price to the
  // running total
  for (item = itemList; item < itemList + arrayEnd; item++) {
    Item currentItem = **item;
    total += currentItem.getPrice() * currentItem.getQuantity();
  }
  return total;
}
