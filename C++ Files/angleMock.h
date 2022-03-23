/***********************************************************************
 * Header File:
 *    Angle Mock : A mock of the Angle class
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once
#include <cassert>
#include "angle.h"

class TestProjectile;                        // why is projectile here?

class AngleMock : public Angle
{
public:
   // Make the test class a friend to grant access for verifying the tests
   friend class TestAngle;
   
   // Constructors
   AngleMock() {}
   AngleMock(double initDegrees) {angle = initDegrees;}
   
   // Methods
//   virtual double getDegrees() {return angle;} // does this need to be virtual?? isn't it the same as what is actually in angle?
private:
};
