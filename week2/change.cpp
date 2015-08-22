/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 06/30/15
** Description: The program determines the most efficient
** way to make change using American coins.
**********************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

  int changeNeeded;
  int quarters, dimes, nickels, pennies;
  
  // determine how many cents of change will be needed
  cout << "Please enter an amount in cents less than a dollar.";
  cout << endl;
  cin >> changeNeeded;

  // start with coins of greater value and work down to
  // coins of lesser value
  
  // store the remainder each time for next calculation
  quarters = changeNeeded / 25;
  changeNeeded = changeNeeded % 25;

  dimes = changeNeeded / 10;
  changeNeeded = changeNeeded % 10;

  nickels = changeNeeded / 5;
  changeNeeded = changeNeeded % 5;

  pennies = changeNeeded;

  // output the results to the display
  cout << "Your change will be:";
  cout << endl << "Q: " << quarters;
  cout << endl << "D: " << dimes;
  cout << endl << "N: " << nickels;
  cout << endl << "P: " << pennies << endl;

  return 0;
}
