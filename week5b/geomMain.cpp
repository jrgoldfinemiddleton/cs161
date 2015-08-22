/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/21/15
** Description: geomMain.cpp
**********************************************************/

#include "LineSegment.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Point p1(4, 7);
  Point p2(7, 3);
  LineSegment ls1(p1, p2);
  double length = ls1.length();
  double slope = ls1.slope();

  cout << "Point1: (" << p1.getXCoord() << ", "
       << p1.getYCoord() << ")" << endl;
  cout << "Point2: (" << p2.getXCoord() << ", "
       << p2.getYCoord() << ")" << endl;
  cout << "Length of Segment: " << length << endl;
  cout << "Slope of Segment: " << slope << endl;

  return 0;
}
