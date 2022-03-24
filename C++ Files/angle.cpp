/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 *    where 0 degrees is up.
 * Author:
 *    Emilio Regino
 * Summary:
 *    A single angle stored in degrees
 ************************************************************************/

#include "angle.h"     // for the angle class definition

/*************************************************
 * SET DEGREES
 * A method to set a new angle in degrees
 **************************************************/
void Angle :: setDegrees(double newAngleDegrees)
{
   // Make sure the angle is valid
   if (verifyNewAngle(newAngleDegrees))
      angle = newAngleDegrees;
   else
      angle = convertToValid(newAngleDegrees);
}

/*************************************************
 * CONVERT TO VALID
 * A method to convert an invalid angle to a
 * valid angle.
 **************************************************/
double Angle :: convertToValid(double newAngle)
{
   // While new angle is greater than 90 degrees (pi / 2)
   while (newAngle > 90.0)
      // subtract 360 degrees (2pi) to make it valid
      newAngle = newAngle - 360.0;

   // While new angle is less than than -90 degrees (-pi / 2)
   while (newAngle < -90.0)
      // add 360 degrees (2pi) to make it valid
      newAngle = newAngle + 360.0;
   
   // return in degrees
   return newAngle;
};
