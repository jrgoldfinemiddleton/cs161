/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/21/15
** Description: Point.cpp is the Point class function
**               implementation file.
**********************************************************/

#include "Point.hpp"  // link to header file
#include <cmath>      // needed to use std::sqrt()


/*********************************************************************
** Description: This is the default constructor.  It initializes the
**              xCoord and yCoord class member variables to 0.
*********************************************************************/ 
Point::Point() {
  setXCoord(0.0);
  setYCoord(0.0);
}


/*********************************************************************
** Description: This constructor initializes the xCoord and yCoord
**              class member variables to the values given by the
**              x and y parameters, respectively.
*********************************************************************/ 
Point::Point(double x, double y) {
  setXCoord(x);
  setYCoord(y);
}


/*********************************************************************
** Description: This function determines and returns the distance
**              between this Point and another Point, passed in by
**              constant reference.
*********************************************************************/ 
double Point::distanceTo(const Point &otherPoint) {
  double xDist = otherPoint.xCoord - xCoord,
         yDist = otherPoint.yCoord - yCoord;
 
  // use the distance formula
  return std::sqrt(xDist * xDist + yDist * yDist);
}


double Point::getXCoord() {
  return xCoord;
}


double Point::getYCoord() {
  return yCoord;
}


void Point::setXCoord(double x) {
  xCoord = x;
}


void Point::setYCoord(double y) {
  yCoord = y;
}
