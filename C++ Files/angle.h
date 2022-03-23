/***********************************************************************
 * Header File:
 *    Angle : Represents an angle in the artillery simulation
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    A single angle stored in degrees
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>


class Angle
{
public:
   // Constructors
   Angle() : angle(0.0f) {};
   Angle(float angle) { setAngle(angle); }
   
   // Getters
   virtual double getRadian() const { return convertToRadian(angle); };
   virtual double getDegrees() const { return angle; };  // remind me again why these need to be virtual?
   
   // Setters
   void setAngle(float newAngle)
   {
      // Make sure the angle is valid
      if (verifyNewAngle(newAngle))
         angle = newAngle;
      else
         angle = convertToValid(newAngle);
   };
   
   // Updaters
   void adjustAngle(float amount) { setAngle(angle + amount); };

protected:
   double angle;   // The angle in degrees
   
   // A method to convert radian to degrees
   double convertToDegrees(double radians) const { return radians * 180 / M_PI; };
   
   // A method to convert degrees to radian
   double convertToRadian(double degrees) const { return degrees * M_PI / 180; }
   
   // verify an angle is valid
   bool verifyNewAngle(float newAngle) { return (newAngle <= 90.0 && newAngle >= -90.0); };
   
   // convert a non valid angle to valid
   double convertToValid(float newAngle)
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
};
