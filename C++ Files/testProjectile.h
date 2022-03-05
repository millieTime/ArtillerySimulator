/***********************************************************************
 * Header File:
 *    Test Projectile : Test the Projectile class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Projectile
 ************************************************************************/


#pragma once

#include <iostream>
#include <cassert>
#include <iterator> //For checking length of an array
#include "projectile.h"

using namespace std;

class TestProjectile
{
public:
   void run()
   {
      test_Projectile_Default_Constructor();
      test_Projectile_Point_Constructor_Origin();
      test_Projectile_Point_Constructor_Normal();
      test_Projectile_Fire_Zero();
      test_Projectile_Fire_Normal();
      test_Projectile_Fire_Wrong_Status();
      test_Projectile_Land_On_Target_Normal();
      test_Projectile_Land_Off_Target_Normal();
      test_Projectile_Land_Wrong_Status();




   }

   void verifyEmptyShadows(Projectile shell) const
   {
      assert(sizeof(shell.shadows) / sizeof(shell.shadows[0]) == 6);
      assert(shell.shadows[0].getMetersX() == 0.0);
      assert(shell.shadows[0].getMetersY() == 0.0);
      assert(shell.shadows[1].getMetersX() == 0.0);
      assert(shell.shadows[1].getMetersY() == 0.0);
      assert(shell.shadows[2].getMetersX() == 0.0);
      assert(shell.shadows[2].getMetersY() == 0.0);
      assert(shell.shadows[3].getMetersX() == 0.0);
      assert(shell.shadows[3].getMetersY() == 0.0);
      assert(shell.shadows[4].getMetersX() == 0.0);
      assert(shell.shadows[4].getMetersY() == 0.0);
      assert(shell.shadows[5].getMetersX() == 0.0);
      assert(shell.shadows[5].getMetersY() == 0.0);
   }

   Projectile defaultSetup() const
   {
      Projectile shell;
      shell.position = Position(1, 2);
      shell.velocity = Velocity(3, 4);
      shell.age = 5;
      shell.status = Projectile::LOADED;
      Position newShadows[] = {
         Position(0, 0),
         Position(0, 0),
         Position(0, 0),
         Position(0, 0),
         Position(0, 0),
         Position(0, 0)
      };
      shell.shadows = newShadows;
      return shell;
   }

   void test_Projectile_Default_Constructor() const
   {
      // setup
      // exercise
      Projectile shell;
      // verify
      assert(shell.position.getMetersX() == 0.0);
      assert(shell.position.getMetersY() == 0.0);
      assert(shell.velocity.getDX() == 0.0);
      assert(shell.velocity.getDY() == 0.0);
      assert(shell.age == 0);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Point_Constructor_Origin() const
   {
      // setup
      // exercise
      Projectile shell = Projectile(Position(0, 0));
      // verify
      assert(shell.position.getMetersX() == 0.0);
      assert(shell.position.getMetersY() == 0.0);
      assert(shell.velocity.getDX() == 0.0);
      assert(shell.velocity.getDY() == 0.0);
      assert(shell.age == 0);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Point_Constructor_Normal() const
   {
      // setup
      // exercise
      Projectile shell = Projectile(Position(15.4, -17));
      // verify
      assert(shell.position.getMetersX() == 15.4);
      assert(shell.position.getMetersY() == -17);
      assert(shell.velocity.getDX() == 0.0);
      assert(shell.velocity.getDY() == 0.0);
      assert(shell.age == 0);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Fire_Zero() const
   {
      // setup
      Projectile shell = defaultSetup();
      // exercise
      shell.fire(Velocity(0, 0));
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.getDX() == 0);
      assert(shell.velocity.getDY() == 0);
      assert(shell.age == 0);
      assert(shell.status == Projectile::FLYING);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Fire_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      // exercise
      shell.fire(Velocity(-12, 1.1));
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.getDX() == -12);
      assert(shell.velocity.getDY() == 1.1);
      assert(shell.age == 0);
      assert(shell.status == Projectile::FLYING);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Fire_Wrong_Status() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::ON_TARGET;
      // exercise
      shell.fire(Velocity(-12, 1.1));
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.getDX() == 3);
      assert(shell.velocity.getDY() == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::ON_TARGET);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Land_On_Target_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      shell.land(true);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.getDX() == 0);
      assert(shell.velocity.getDY() == 0);
      assert(shell.age == 5);
      assert(shell.status == Projectile::ON_TARGET);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Land_Off_Target_Normal() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::FLYING;
      // exercise
      shell.land(false);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.getDX() == 0);
      assert(shell.velocity.getDY() == 0);
      assert(shell.age == 5);
      assert(shell.status == Projectile::OFF_TARGET);
      verifyEmptyShadows(shell);
   }  // teardown

   void test_Projectile_Land_Wrong_Status() const
   {
      // setup
      Projectile shell = defaultSetup();
      shell.status = Projectile::LOADED;
      // exercise
      shell.land(true);
      // verify
      assert(shell.position.getMetersX() == 1);
      assert(shell.position.getMetersY() == 2);
      assert(shell.velocity.getDX() == 3);
      assert(shell.velocity.getDY() == 4);
      assert(shell.age == 5);
      assert(shell.status == Projectile::LOADED);
      verifyEmptyShadows(shell);
   }  // teardown

};