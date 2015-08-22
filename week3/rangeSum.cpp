/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/08/15
** Description: This program takes two integers and sums
**              the range of integers from the least to
**              the greatest (inclusive).
**********************************************************/

#include <iostream>   // needed to use cin, cout, endl

using std::cin;
using std::cout;
using std::endl;

int main() {
  int integer1,   // the first given integer
      integer2,   // the second given integer
      sum = 0;    // running total of integers in range

  // get two integers from the user and store their values
  cout << "Please enter two integers." << endl;
  cin >> integer1 >> integer2;

  // ensure that the first integer is no greater than the
  // second
  if (integer1 > integer2) {
    int temp = integer1;
    integer1 = integer2;
    integer2 = temp;
  }

  // iterate over every integer in the range, adding
  // each to the total
  for (int n = integer1; n <= integer2; n++) {
    sum += n;
  }

  // print out the sum
  cout << "The sum of the values in that range is:" << endl << sum << endl;

  return 0;
}
