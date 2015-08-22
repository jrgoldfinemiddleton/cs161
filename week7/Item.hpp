/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 08/04/15
** Description: This header file is for the Item class.
**              
**              An Item has a name, a price, and a
**              quantity.
**********************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>   // needed for storing a name
using std::string;

class Item {
  private:
    string name;    // item name
    double price;   // price per unit ($)
    int quantity;   // number of item

  public:
    Item();                     // default constructor
    Item(string, double, int);  // name, price, quantity

    // accessor methods
    string getName();
    double getPrice();
    int getQuantity();

    // mutator methods
    void setName(string);
    void setPrice(double);
    void setQuantity(int);
}; // end class declaration
#endif
