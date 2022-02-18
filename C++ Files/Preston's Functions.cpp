#define _USE_MATH_DEFINES
#include <cmath>

// Using d = 1/2 * c * p * v^2 * a
double computeDrag(double dragCoeff, double density, double velocity, double area)
{
   return 0.5 * dragCoeff * density * velocity * velocity * area;
}

// Using a = PI * r * r
double circleAreaFromRadius(double radius)
{
   return M_PI * radius * radius;
}

// Using a = PI * r * r
double circleAreaFromDiameter(double diameter)
{
   double radius = diameter / 2.0;
   return circleAreaFromRadius(radius);
}

// Using a = f / m
double computeAcceleration(double mass, double force)
{
   return force / mass;
}

// Using d = 360 * r / (2 * PI)
double degreesFromRadians(double radians)
{
   return 360.0 * radians / (2 * M_PI);
}

// Using r = d * 2 * PI / 360
double radiansFromDegrees(double degrees)
{
   return degrees * 2 * M_PI / 360.0;
}

// Using c = sqrt(a^2 + b^2)
double hypotenuseFromComponents(double a, double b)
{
   return sqrt(a * a + b * b);
}

// Using (y1-y0)/(x1-x0) = (yU-y0)/(xU-x0) where xU is the value to search for
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