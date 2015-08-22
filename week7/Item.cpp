/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 08/04/15
** Description: This file contains the Item class function
**              implementation.
**********************************************************/

#include "Item.hpp"


/*********************************************************************
 ** Description: Constructs an Item object with an empty name, a price
 **              of 0.0, and a quantity of 0.
 *********************************************************************/

Item::Item() {

  setName("");
  setPrice(0.0);
  setQuantity(0);

}


/*********************************************************************
 ** Description: Constructs an Item object from three parameters: a
 **              name, a price, and a quantity.
 *********************************************************************/

Item::Item(string nm, double pr, int qnt) {
  setName(nm);
  setPrice(pr);
  setQuantity(qnt);
}


/*********************************************************************
 ** Description: Returns this Item's name.
 *********************************************************************/

string Item::getName() {
  return name;
}


/*********************************************************************
 ** Description: Returns this Item's price.
 *********************************************************************/

double Item::getPrice() {
  return price;
}


/*********************************************************************
 ** Description: Returns this Item's quantity.
 *********************************************************************/

int Item::getQuantity() {
  return quantity;
}


/*********************************************************************
 ** Description: Sets this Item's name from a given string.
 *********************************************************************/

void Item::setName(string nm) {
  name = nm;
}


/*********************************************************************
 ** Description: Sets this Item's price from a given price.
 *********************************************************************/

void Item::setPrice(double pr) {
  price = pr;
}


/*********************************************************************
 ** Description: Sets this Item's quantity from a given quantity.
 *********************************************************************/

void Item::setQuantity(int qnt) {
  quantity = qnt;
}
