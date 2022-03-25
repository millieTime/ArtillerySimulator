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
   // Constructors
   AngleMock() {}
   AngleMock(double initDegrees) {angle = initDegrees;}
   
   // Methods
   virtual double getDegrees() { return angle; }
   virtual double getRadians()
   {
      if (angle == 45)
         return PI / 4.0;

      assert(false);
      return 0.0;
   }
private:
};
