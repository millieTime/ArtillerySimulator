/***********************************************************************
 * Header File:
 *    Projectile : The representation of a projectile
 * Author:
 *    Preston Millward
 * Summary:
 *    Everything we need to know about the projectile's position, status,
 *    and motion.
 ************************************************************************/
#pragma once
#include "position.h"
#include "velocityMock.h"
#include "accelerationMock.h"
#include "angle.h"
#include "airDensityLookUpMock.h"
#include "gravityLookUpMock.h"
#include "dragLookUpMock.h"
#include "machLookUpMock.h"
#include "uiDraw.h"  // for ogstream
#include <vector>    // for vectors
#define _USE_MATH_DEFINES // for M_PI to work on xcode (comment out on windows)
#include <cmath>           // for M_PI to work on xcode (comment out on windows)
class TestProjectile;

 /*********************************************
  * Projectile
  * Everything we need to know about the
  * projectile's position, status, and motion.
  *********************************************/
class Projectile
{
public:
   friend class TestProjectile;
   Projectile();
   Projectile(Position point);
   void move(double time);
   void fire(VelocityMock initialVelocity);
   void land(bool onTarget);
   Position getPosition() const { return position; };
   Position getLastPosition() const { return shadows.at(1); };
   double getSpeed() const { return velocity.getSpeed(); };
   VelocityMock getVelocity() const { return velocity; };
   Angle getAngle() const { return Angle(); };
   float getAge() const { return age; };
   bool isLoaded() const { return status == LOADED; };
   bool isFlying() const { return status == FLYING; };
   bool isLanded() const { return (status == ON_TARGET || status == OFF_TARGET); };
   bool isOnTarget() const { return status == ON_TARGET; };
   void draw(ogstream& gout) const {};

private:
   void shiftShadows();
   double getArea() const;
   const double MASS = 46.7;        // kilograms
   const double DIAMETER = 0.15489; // meters
   const char NUM_SHADOWS = 6;
   const GravityLookUpMock gravityTable;
   const AirDensityLookUpMock airDensityTable;
   const MachLookUpMock machTable;
   const DragLookUpMock dragTable;
   float age = 0;
   VelocityMock velocity;
   Position position;
   const enum ProjectileStatus{ LOADED, FLYING, ON_TARGET, OFF_TARGET };
   ProjectileStatus status;
   std::vector<Position> shadows;
};
