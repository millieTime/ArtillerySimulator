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
double computeAcceeration(double mass, double force)
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

// Using s = sqrt(dx^2 + dy^2)
double speedFromComponents(double dx, double dy)
{
   return sqrt(dx * dx + dy * dy);
}