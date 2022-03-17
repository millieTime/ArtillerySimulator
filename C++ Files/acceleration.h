/***********************************************************************
 * Header File:
 *    Acceleration : Represents a 2-dimensional acceleration in the artillery simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the acceleration class, just enough so the program compiles.
 *    This inherits from the Vector2D class.
 ************************************************************************/

#pragma once

#include "vector2D.h"

class Acceleration : public Vector2D
{
public:
   Acceleration() {};
   Acceleration(double ddx, double ddy) { horizontalComponent = ddx; verticalComponent = ddy; };
   Acceleration(double magnitude, Angle angle) {};

   virtual double getDDX() { return horizontalComponent; };
   virtual double getDDY() { return verticalComponent; };
   virtual void addAcceleration(Acceleration otherAccel) {};
protected:
};