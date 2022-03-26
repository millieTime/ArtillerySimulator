/***********************************************************************
 * Header File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Preston Millward
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/


#pragma once

#include <iostream>
#include <cassert>
#include "acceleration.h"

using namespace std;

class TestAcceleration
{
public:

   // Runs all the test cases
   void run()
   {
      testTwoComponentConstructor();
      testMagAngleConstructor();
   }

   // Determines if the left floating point number is close enough to the right one.
   bool decimalCloseEnough(double lDecimal, double rDecimal, double minDiff = 0.0005) const
   {
      return abs(lDecimal - rDecimal) < minDiff;
   }

   void testTwoComponentConstructor()
   {
      // setup
      // exercise
      Acceleration acc = Acceleration(5.0, 7.0);
      // verify
      assert(acc.horizontalComponent == 5.0);
      assert(acc.verticalComponent == 7.0);
   }  // teardown

   void testMagAngleConstructor()
   {
      // setup
      // exercise
      Acceleration acc = Acceleration(2.0, AngleMock(45));
      // verify
      assert(decimalCloseEnough(acc.horizontalComponent, 0.7071067811865475244));
      assert(decimalCloseEnough(acc.verticalComponent, 0.7071067811865475244));
   }  // teardown

   void testAddAcceleration()
   {
      // setup
      Acceleration accA = Acceleration();
      accA.horizontalComponent = 2.0;
      accA.verticalComponent = 3.0;
      Acceleration accB = Acceleration();
      accB.horizontalComponent = -0.5;
      accB.verticalComponent = -5.0;
      // exercise
      accA.addAcceleration(accB);
      // verify
      assert(accA.horizontalComponent == 1.5);
      assert(accA.verticalComponent == -2.0);
   }  // teardown


};