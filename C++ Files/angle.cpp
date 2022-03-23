/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 *    where 0 degrees is up.
 * Author:
 *    Emilio Regino
 * Summary:
 *    
 ************************************************************************/
#include "angle.h"                // for the angle class definition
#define _USE_MATH_DEFINES
#include <cmath>

Angle ang; // why is this not reconized??

/*************************************************
 * SET ANGLE
 * A method to set a new angle
 **************************************************/
void Angle :: setAngle(float newAngle)
{
   if (verifyNewAngle)
      angle = newAngle;
   else
      convertAngle
}

/*************************************************
 * VERIFY ANGLE OR MAYBE CONVERT????                                                                        <- THIS COMMENT NEED IMPROVEMENT
 * Verify that when 0 degrees is up the a new
 * angle given is less than 90 degrees (pi/2)
 * and greater than -90 degrees (-pi/2)
 **************************************************/
bool Angle :: verifyNewAngle(float newAngle)
{
   // While new angle is greater than 90 degrees (pi / 2)
   while (newAngle >= M_PI / 2)
      // subtract 360 degrees (2pi) to make it valid
      newAngle = newAngle - 2 * M_PI;

   // While new angle is less than than -90 degrees (-pi / 2)
   while (newAngle <= -M_PI / 2)
      // add 360 degrees (2pi) to make it valid
      newAngle = newAngle + 2 * M_PI;
}
