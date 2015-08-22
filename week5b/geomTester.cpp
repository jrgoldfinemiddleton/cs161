/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/27/15
** Description: This program is meant to test the functions
**              of the Point and LineSegment classes.
**********************************************************/

#include "Point.hpp"
#include "LineSegment.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  
  Point p0;  // attempt to create a Point at (0,0)
  Point p1(-1.5, 2); // attempt to create a Point at (-1.5,2)
  Point p2; // create a new Point at (0,0)

  // try to use the Point setter methods
  p2.setXCoord(5);
  p2.setYCoord(-8.5);

  // test the Point getter methods
  if (p0.getXCoord() == 0 && p0.getYCoord() == 0) {
    cout << "OK: p0 is located at (0,0)" << endl;
  } else {
    cout << "ERR: p0 is not located at (0,0)" << endl;
  }
  
  if (p1.getXCoord() == -1.5 && p1.getYCoord() == 2) {
    cout << "OK: p1 is located at (-1.5,2)" << endl;
  } else {
    cout << "ERR: p1 is not located at (-1.5,2)" << endl;
  }

  // errors in either the Point getter or setter methods
  // will show up here
  if (p2.getXCoord() == 5 && p2.getYCoord() == -8.5) {
    cout << "OK: p2 is located at (5,-8.5)" << endl;
  } else {
    cout << "ERR: p0 is not located at (5,-8.5)" << endl;
  }

  // test the Point distanceTo() method
  // range is recommended rather than == for determining
  // equality of double values
  double dist = p0.distanceTo(p1);
  if (2.499 < dist && dist < 2.501) {
    cout << "OK: p0 is 2.5 units away from p1" << endl;
  } else {
    cout << "ERR: p0 is not 2.5 units away from p1" << endl;
  }

  // test the LineSegment constructor
  LineSegment ls0(p0, p2);

  // make sure the first endpoint is p0
  if (ls0.getEnd1().getXCoord() == p0.getXCoord() &&
      ls0.getEnd1().getYCoord() == p0.getYCoord()) {
    cout << "OK: p0 is the first endpoint of ls0" << endl;
  } else {
    cout << "ERR: p0 is not the first endpoint of ls0" << endl;
  }

  // make sure the second endpoint is p2
  if (ls0.getEnd2().getXCoord() == p2.getXCoord() &&
      ls0.getEnd2().getYCoord() == p2.getYCoord()) {
    cout << "OK: p2 is the second endpoint of ls0" << endl;
  } else {
    cout << "ERR: p2 is not the second endpoint of ls0" << endl;
  }

  // test the LineSegment constructor again
  LineSegment ls1(Point(1, 2), Point(4, -2));
  
  double length = ls1.length();
  double slope = ls1.slope();

  // test the LineSegment length() method
  if (4.99 < length && length < 5.01) {
    cout << "OK: ls1's length is 5 units" << endl;
  } else {
    cout << "ERR: ls1's length is not 5 units" << endl;
  }

  // test the LineSegment slope() method
  if (-1.34 < slope && slope < -1.32) {
    cout << "OK: ls1's slope is -4/3" << endl;
  } else {
    cout << "ERR: ls1's slope is not -4/3" << endl;
  }
  
  return 0;
}
