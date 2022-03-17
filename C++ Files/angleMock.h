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
private:
};
