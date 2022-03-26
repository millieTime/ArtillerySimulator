/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 *    where 0 degrees is up.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Keeps track of an angle, and provides an easy interface to convert to
 *    and from degrees and radians
 ************************************************************************/

#include "angle.h"     // for the angle class definition

/*************************************************
 * SET DEGREES
 * A method to set a new angle in degrees
 **************************************************/
void Angle::setDegrees(double newAngle)
{
   // verify the new angle is valid
   // angle must be between -pi and +pi radians
   while (newAngle >= 180)
      newAngle = newAngle - 180;
   while (newAngle <= -180)
      newAngle = newAngle + 180;

   // Now assign the new angle
   angle = newAngle;
}

/*************************************************
 * CONVERT TO VALID
 * A method to convert an invalid angle to a
 * valid angle.
 **************************************************/
double Angle :: convertToValid(double newAngle)
{
   // While new angle is greater than 90 degrees (pi / 2)
   while (newAngle > 180.0)
      // subtract 360 degrees (2pi) to make it valid
      newAngle = newAngle - 360.0;

   // While new angle is less than than -90 degrees (-pi / 2)
   while (newAngle < -180.0)
      // add 360 degrees (2pi) to make it valid
      newAngle = newAngle + 360.0;
   
   // return in degrees
   return newAngle;
};
