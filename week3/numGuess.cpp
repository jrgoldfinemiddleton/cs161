/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/08/15
** Description: This program asks the user for an integer
**              value.  It plays a simple guess-and-check
**              game with the user until she is correct.
**********************************************************/

#include <iostream>   // needed for cin, cout, endl

using std::cin;
using std::cout;
using std::endl;

int main() {

  int guessCount,   // number of guesses
      secretNumber, // the number to guess
      currentGuess; // the most recent guess
  bool correct;     // true if user guessed correctly

  // prompt first user for integer and store it
  cout << "Enter the number for the player to guess." << endl;
  cin >> secretNumber;

  correct = false;
  guessCount = 0;

  cout << "Enter your guess." << endl;

  // until the user guesses correctly, give the user feedback
  // on her guesses
  do {
    // read the (next) guess and increment the guess count
    cin >> currentGuess;
    guessCount++;

    // correct guess, loop won't repeat again
    if (currentGuess == secretNumber) {
      correct = true;
    }
    // guess is less than the secret number
    // prompt for a new guess
    else if (currentGuess < secretNumber) {
      cout << "Too low - try again." << endl;
    }
    // guess is greater than the secret number
    // prompt for a new guess
    else {
      cout << "Too high - try again." << endl;
    }
  } while (!correct);

  // let the user know she was correct and how long it took
  cout << "You guessed it in " << guessCount
       << (guessCount == 1 ? " try." : " tries.") << endl;

  return 0;
}
