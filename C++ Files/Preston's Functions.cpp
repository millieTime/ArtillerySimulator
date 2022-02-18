#define _USE_MATH_DEFINES
#include <cmath>

/******************************************************
 * COMPUTE DRAG
 * Computes the drag force in Newtons acting
 * on an object using d = 1/2 * c * p * v^2 * a
 ******************************************************/
double computeDrag(double dragCoeff, double density, double velocity, double area)
{
   return 0.5 * dragCoeff * density * velocity * velocity * area;
}

/******************************************************
* CIRCLE AREA FROM RADIUS
* Computes the area of a circle given the circle's
* radius using a = PI * r * r
*******************************************************/
double circleAreaFromRadius(double radius)
{
   return M_PI * radius * radius;
}

/******************************************************
* CIRCLE AREA FROM DIAMETER
* Computes the area of a circle given the circle's
* diameter using a = PI * (d/2) * (d/2)
*******************************************************/
double circleAreaFromDiameter(double diameter)
{
   double radius = diameter / 2.0;
   return circleAreaFromRadius(radius);
}

/******************************************************
* COMPUTE ACCELERATION
* Computes the acceleration of an object given its mass
* and the force acting on it using a = f / m
*******************************************************/
double computeAcceleration(double mass, double force)
{
   return force / mass;
}

/******************************************************
* DEGREES FROM RADIANS
* Converts radians to degrees using d = 360 * r / (2 * PI)
*******************************************************/
double degreesFromRadians(double radians)
{
   return 360.0 * radians / (2 * M_PI);
}

/******************************************************
* RADIANS FROM DEGREES
* Converts degrees to radians using r = d * 2 * PI / 360
*******************************************************/
double radiansFromDegrees(double degrees)
{
   return degrees * 2 * M_PI / 360.0;
}

/******************************************************
* HYPOTENUSE FROM COMPONENTS
* Computes the magnitude of the hypotenuse from the
* given orthogonal components using c = sqrt(a^2 + b^2)
*******************************************************/
double hypotenuseFromComponents(double a, double b)
{
   return sqrt(a * a + b * b);
}

/******************************************************
* INTERPOLATE
* Performs linear interpolation given two points (x0, y0)
* and (x1, y1) and a known x-value using
*  (y1-y0)/(x1-x0) = (yU-y0)/(xU-x0)
* where xU is the known x-value.
*******************************************************/
double interpolate(double x0, double y0, double x1, double y1, double current_x)
{
   if (y1 == y0)
   {
      // They gave us one point twice, or a constant function.
      return y1;
   }
   else
   {
      return (y1 - y0) * (current_x - x0) / (x1 - x0) + y0;
   }
}