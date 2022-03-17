/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the angle class, just enough so the program compiles.
 ************************************************************************/

#pragma once

 /***********************************************************
  * ANGLE
  * A single angle, in degrees.
  ***********************************************************/
class Angle
{
public:
   Angle() {};
   virtual double getDegrees(){ return angle; }
protected:
   double angle;
};