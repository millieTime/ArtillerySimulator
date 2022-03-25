/***********************************************************************
 * Header File:
 *    Angle Mock : A mock of the Angle class
 * Author:
 *    Preston Millward
 * Summary:
 *    Limits access to functions, and performs in a very limited way.
 ************************************************************************/

#pragma once
#include<cassert>
#include "angle.h"

class TestProjectile;

class AngleMock : public Angle
{
public:
   AngleMock() {}
   AngleMock(double initDegrees)
   {
      angle = initDegrees;
   }
   virtual double getDegrees() { return angle; }
   virtual double getRadians()
   {
      long double const PI = 3.14159265358979323846;
      if (angle == 45)
         return PI / 4.0;

      assert(false);
      return 0.0;
   }
private:
};
