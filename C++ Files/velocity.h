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

#include "vector2DMock.h"
#include "acceleration.h"

class TestVelocity;
class TestProjectile;

class Velocity : public Vector2D
{
public:
   friend class TestVelocity;
   friend class TestProjectile;

   Velocity() {};
   Velocity(double x, double y) : Vector2D(x, y) { };
   Velocity(Angle angle, double mag) : Vector2D(angle, mag) {};

   virtual void applyAcceleration(Acceleration accel, double time);

   virtual double getDX() const { return horizontalComponent; };
   virtual double getDY() const { return verticalComponent; };
   virtual double getSpeed() const { return getMagnitude(); };
protected:
};