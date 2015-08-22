/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 6/24/15
** Description: Program that asks for and prints the user's
**   favorite animal.
**********************************************************/

#include <iostream>
#include <string>

// a simple example program
int main() {

  std::string faveAnimal;
  std::cout << "Please enter your favorite animal." << std::endl;
  std::cin >> faveAnimal;
  std::cout << "Your favorite animal is the " << faveAnimal;
  std::cout << "." << std::endl;

  return 0;
}
