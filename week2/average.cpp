/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 6/30/15
** Description: This program asks the user for 5 numbers,
**  computes their mean, and displays the result.
**********************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

  double num1, num2, num3, num4, num5;

  cout << "Please enter five numbers." << endl;

  // read each number
  cin >> num1;
  cin >> num2;
  cin >> num3;
  cin >> num4;
  cin >> num5;

  // calculate the mean
  double average;
  average = (num1 + num2 + num3 + num4 + num5) / 5;

  // print out the mean
  cout << "The average of those numbers is:" << endl << average << endl;

  return 0;
}
