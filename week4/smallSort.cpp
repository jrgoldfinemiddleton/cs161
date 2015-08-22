/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/13/15
** Description: This function sorts three given integers
**              from least to greatest using reference
**              variables.
**********************************************************/

void smallSort(int &first, int &second, int &third) {
  int temp;

  // switch the first two numbers if they are out of order
  if (first > second) { 
    temp = second;
    second = first;
    first = temp;
  }

  // compare the resulting second number with the third number,
  // switch if necessary
  if (second > third) {
    temp = third;
    third = second;
    second = temp;

    // now compare the first and resulting second number,
    // switch if necessary
    // all 3 pair comparisons have been done, so we're done
    if (first > second) {
      temp = second;
      second = first;
      first = temp;
    }
  }
}
