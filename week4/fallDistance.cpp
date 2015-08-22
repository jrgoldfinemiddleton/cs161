/**********************************************************
** Author: Jason Goldfine-Middleton
** Date: 07/13/15
** Description: This function determines how far an object
**              has fallen given the length of time it has
**              been falling for.
**********************************************************/
double fallDistance(double fallTime) {

  const double G = 9.8;  // gravitational acceleration constant approx.
  double distance;       // distance the object has fallen

  // use the formula d = (1/2)gt^2
  distance = 0.5 * G * fallTime * fallTime;

  return distance;
}
