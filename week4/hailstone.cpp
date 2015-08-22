/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/13/15
** Description: This function determines how many
**              iterations are needed to reach a value of
**              1 given that if the input is even, it is
**              divided by 2, and if the input is odd, it
**              multiplies it by 3 and increments it by 1.
**********************************************************/
int hailstone(int startVal) {

  int count = 0;  // iterations so far

  // loop until the number = 1
  while (startVal != 1) {
    // if even, divide it by 2
    if (startVal % 2 == 0) {
      startVal /= 2;
    } else { 
      // if odd, multiply it by 3 and add 1
      startVal = startVal * 3 + 1;
    }
    // increment the counter
    count++;
  }

  return count;
}
