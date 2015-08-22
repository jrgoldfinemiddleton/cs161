/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 06/30/15
** Description: This program converts Celcius temperatures
**  to Fahrenheit temperatures.
**********************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

  double tempCels, tempFahr;

  // get the temperature in Celsius from the user
  cout << "Please enter a Celsius temperature." << endl;
  cin >> tempCels;

  // calculate the temperature in Fahrenheit
  // note we must be careful not to do integer division
  tempFahr = (9.0 / 5.0) * tempCels + 32;

  // output the calculated temperature in Fahrenheit
  cout << "The equivalent Fahrenheit temperature is:" << endl;
  cout << tempFahr << endl;

  return 0;
}
