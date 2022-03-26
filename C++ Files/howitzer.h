/***********************************************************************
 * Header File:
 *    Howitzer : Represents the Howitzer in the artillery simulation.
 * Author:
 *    Preston Millward
 * Summary:
 *    The howitzer is stationary on the ground. The angle of its barrell
 *    can be changed, and when the user fires a shot, it will produce a 
 *    projectile with the correct velocity and the same angle that the
 *    howitzer was aimed at. 
 ************************************************************************/

#pragma once

#include "projectileMock.h"
#include "angleMock.h"
#include "uiDraw.h"  // for ogstream

class TestHowitzer;

class Howitzer
{
public:
   friend class TestHowitzer;
   
   Howitzer() { Howitzer(Position(0, 0)); };
   Howitzer(Position startPosition) { position = startPosition; angle = AngleMock(0); };
   Projectile fire();
   void draw(ogstream & gout) const { draw(gout, -1); }
   void draw(ogstream & gout, double age) const { gout.drawHowitzer(position, angle.getRadians(), age); };
   Angle getAngle() const { return angle; };
   void setPosition(Position newPosition) { position = newPosition; };
   void raise();
   void lower();
   void clockwise();
   void counterClockwise();

private:
   Angle angle;
   Position position;
   double const MUZZLE_VELOCITY = 827.0;    // m/s
   double const SMALL_ANGLE_CHANGE = 0.003; // radians
   double const LARGE_ANGLE_CHANGE = 0.05;  // radians
};