/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/08/15
** Description: This program determines the least and the
**              the greatest integer value out of
**              several given by the user.
**********************************************************/

#include <iostream>   // needed to use cin, cout, endl

using std::cin;
using std::cout;
using std::endl;

int main() {

  int curValue,   // stores most recently entered integer
      minValue,   // least input value thus far
      maxValue,   // greatest input value thus far
      numValues;  // number of integers user to enter

  // ask the user how many integers he will enter
  cout << "How many integers would you like to enter?" << endl;
  cin >> numValues;

  //  as long as the user wants to enter at least one value...
  if (numValues > 0) {
    
    // prompt user for the integers
    cout << "Please enter " << numValues
         << (numValues > 1 ? " integers." : " integer.") << endl;

    // use a loop to capture all the integers
    for (int i = 0; i < numValues; i++) {
      cin >> curValue;
      // for the first integer, assign its value to min and max
      if (i == 0) {
        minValue = maxValue = curValue;
      }
      // min and max already initialized, so compare them with
      // the most recently entered integer
      // update each if necessary
      else {
        if (curValue < minValue) {
          minValue = curValue;
        } else if (curValue > maxValue) {
          maxValue = curValue;
        }
      }
    }

    // print the min and max
    cout << "min: " << minValue << endl
         << "max: " << maxValue << endl;
  }

  return 0;
}
