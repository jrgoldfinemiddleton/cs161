/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/28/15
** Description: The file contains a function for
**              determining the mode(s) of an int
**              array, which returns the result as a
**              vector sorted in ascending order.
**********************************************************/

#include <algorithm>    // needed for the std::sort() function
#include <vector>       // needed to use the std::vector type

using std::vector;
using std::sort;


/*********************************************************************
** Description: Determines which values from an unsorted list of
**              integers are its modes and returns them in a vector.
**              They are sorted in ascending order.  Complexity is
**              roughly O(nlogn) time, where n is the number of items
**              contained in the list.
*********************************************************************/

vector<int> findMode(int nums[], int size) {
  int maxFreq = 1;    // store highest found frequency
  vector<int> modes;  // store all modes

  // loop through all the integers
  for (int i = 0; i < size; i++) {

    int curFreq = 1;  // accumulator for occurrences of value
                      // at index i, starting from index i + 1

    // starting at the index after i, loop through the integers
    // in the list, seeking any matches with the value at index i

    // note: starting after index i will prevent duplicate values
    // from being pushed to modes
    for (int j = i + 1; j < size; j++) {

      // if a match is found, increment the accumulator
      if (nums[i] == nums[j]) {
        curFreq++;
      }
    }

    // if the accumulator for index i matches the maximum frequency
    // seen thus far, push the value stored at index i to modes
    if (curFreq == maxFreq) {
      modes.push_back(nums[i]);
    }

    // if the accumulator for index i is greater than the maximum
    // frequency seen, update maxFreq, clear all values stored in
    // modes (since there are other values that occur more
    // frequently), and push the value stored at index i to modes
    if (curFreq > maxFreq) {
      maxFreq = curFreq;
      modes.clear();
      modes.push_back(nums[i]);
    }
  }

  // sort all the modes
  sort(modes.begin(), modes.end());

  return modes;
}
