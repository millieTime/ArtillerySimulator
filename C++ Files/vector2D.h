/***********************************************************************
 * Header File:
 *    Vector 2D : keeps track of the horizontal and vertical components
 *    of a vector in 2-dimensional space, as well as including some simple
 *    calculations about the vector.
 * Author:
 *
 * Summary:
 *
 ************************************************************************/

#pragma once

#include <cmath>     // For sin() & cos()
#include "angle.h"   // For the angle class


class Vector2D
{
public:
   // Constructors
   Vector2D() : horizontalComponent(0.0), verticalComponent(0.0) {};
   Vector2D(double hor, double vert) : horizontalComponent(hor), verticalComponent(vert)
   {
      // set mag and angle
      setMagnitude(verticalComponent / cos(angle.getRadian()));
      setAngle(atan2(horizontalComponent, verticalComponent));
      
   };
   Vector2D(double magnitudeValue, Angle angleObject) : magnitude(magnitudeValue), angle(angleObject)
   {
      setHorizontal(magnitude * sin(angle.getRadian()));
      setVertical(magnitude * cos(angle.getRadian()));
   };
   
//   virtual Angle getAngle() { return Angle(); }     // Why do we need the get angle method?
   
   // Getters
   double getHorComponent() const { return horizontalComponent; };
   double getVertComponent() const { return verticalComponent; };
   
   // Setters
   void setHorizontal(double horizontal) { horizontalComponent = horizontal; };
   void setVertical(double vertical) { verticalComponent = vertical; };
   
protected:
   double horizontalComponent;
   double verticalComponent;
   double magnitude;
   Angle angle;
   
   // A method to get the magnitude (speed) of the vector
   double getMagnitude() const { return magnitude; };      
   Angle getAngle() const { return angle; }
   
   // A method to set the magnitude
   void setMagnitude(double newMagnitude)             // Implement verification
   {
      // do some verification then set
      magnitude = newMagnitude;
   }
   
   // A method to set the Angle
   void setAngle(Angle newAngle)                   // Implement verification & possibly angle copy constructor
   {
      // do some verification then set
      angle = newAngle;
   }
};
