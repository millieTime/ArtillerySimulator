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

#include "vector2DMock.h"

class TestAcceleration;

class Acceleration : public Vector2DMock
{
public:
   friend class TestAcceleration;

   // Default constructor
   Acceleration() : Vector2DMock() { };
   // Constructs an Acceleration from a horizontal and vertical component
   Acceleration(double ddx, double ddy) : Vector2DMock(ddx, ddy) { };
   // Constructs an Acceleration from an angle and magnitude
   Acceleration(double magnitude, Angle angle) : Vector2DMock(magnitude, angle) { }

   // Getters
   virtual double getDDX() const { return horizontalComponent; };
   virtual double getDDY() const { return verticalComponent; };

   // Adds the components of otherAccel to the components of this Acceleration
   virtual void addAcceleration(Acceleration otherAccel)
   {
      horizontalComponent += otherAccel.getDDX();
      verticalComponent += otherAccel.getDDY();
   };
};