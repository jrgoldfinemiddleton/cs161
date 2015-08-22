#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> findMode(int [], int);

int main() {
  const int MAX_NUM_VALS = 25;
  int values[MAX_NUM_VALS];
  int numVals = 0;
  int totalElements = 0;

  cout << "How many integers would you like to enter?" << endl;
  cin >> totalElements;

  if (totalElements < 1) { totalElements = 1; }
  else if (totalElements > 25) { totalElements = 25; }

  cout << "Please enter the integers: " << endl;
  for (int i = 0; i < totalElements; i++) {
    cin >> values[i];
  }

  vector<int> modes = findMode(values, totalElements);
  cout << "The modes:" << endl;
  for (int i = 0; i < modes.size(); i++) {
    cout << modes[i] << "  ";
  }

  cout << endl;

  return 0;
}

