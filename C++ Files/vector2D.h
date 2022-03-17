/***********************************************************************
 * Header File:
 *    Vector 2D : keeps track of the horizontal and vertical components
 *    of a vector in 2-dimensional space, as well as including some simple
 *    calculations about the vector.
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the Vector2D class, just enough so the program compiles.
 ************************************************************************/

#pragma once

#include "angle.h"

class Vector2D
{
public:
   Vector2D() : horizontalComponent(0.0), verticalComponent(0.0) {};
   Vector2D(double x, double y) : horizontalComponent(x), verticalComponent(y) {};
   Vector2D(double magnitude, Angle angle) {};
   virtual Angle getAngle() { return Angle(); }
protected:
   double horizontalComponent;
   double verticalComponent;
   double getMagnitude() const { return 0.0; };
};