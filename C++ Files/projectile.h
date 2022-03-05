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
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "airDensityLookUp.h"
#include "gravityLookUp.h"
#include "dragLookUp.h"
#include "machLookUp.h"
#include "uiDraw.h"  // for ogstream
#include <queue>    // for vectors
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
   void fire(Velocity initialVelocity);
   void land(bool onTarget);
   Position getPosition() const;
   Position getLastPosition() const;
   double getSpeed() const;
   Velocity getVelocity() const;
   Angle getAngle() const;
   double getArea() const;
   float getAge() const;
   bool isLoaded() const;
   bool isFlying() const;
   bool isLanded() const;
   bool isOnTarget() const;
   void draw(ogstream& gout) const;


private:
   void shiftShadows();
   const double WEIGHT = 1.0;
   const double AREA = 1.0;
   const char NUM_SHADOWS = 6;
   const GravityLookUp gravity;
   const AirDensityLookUp airDensity;
   const MachLookUp mach;
   const DragLookUp drag;
   float age = 0;
   Velocity velocity;
   Position position;
   const enum ProjectileStatus{ LOADED, FLYING, ON_TARGET, OFF_TARGET };
   ProjectileStatus status;
   std::queue<Position> shadows;
};