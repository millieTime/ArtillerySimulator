/***********************************************************************
 * Header File:
 *    Velocity : Keeps track of a velocity in 2-dimensional space
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the Velocity class, just enough so the program compiles.
 *    Inherits from the Vector2D class.
 ************************************************************************/

#pragma once

#include "vector2D.h"

class Velocity : public Vector2D
{
public:
   Velocity() {};
   Velocity(double x, double y) { horizontalComponent = x; verticalComponent = y; };

   virtual void addAcceleration(Acceleration accel, double time) {};

   virtual double getDX() const { return horizontalComponent; };
   virtual double getDY() const { return verticalComponent; };
   virtual double getSpeed() const { return getMagnitude(); }
protected:
};