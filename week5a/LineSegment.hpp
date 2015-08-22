/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/21/15
** Description: LineSegment.hpp is the LineSegment class
**              specification file.
**
**              A LineSegment is defined by two Point
**              objects and has a slope and a length.
**********************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "Point.hpp"  // link to Point class header file

class LineSegment {
  private:
    Point end1,
          end2;
  public:
    LineSegment(Point,Point);
    Point getEnd1();
    Point getEnd2();
    double length();
    void setEnd1(Point);
    void setEnd2(Point);
    double slope();
};

#endif
