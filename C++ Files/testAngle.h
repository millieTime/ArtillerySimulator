/***********************************************************************
 * Source File:
 *    Test Angle: A class to test the Angle class
 * Author:
 *    Emilio Regino
 * Summary:
 *    Contains the unit tests for the angle class
 ************************************************************************/

#include "angleMock.h"
#include "angle.h"
#include <cassert>


class TestAngle
{
public:
   
   // The default constructor
   TestAngle(){};
   
   // A method to run all the unit tests
   void run()
   {
      test_getDegrees();
      test_getRadian();
      test_setAngle();
      test_adjustAngle();
      test_getRadian_positive();
      test_getRadian_negative();
      test_verifyNewAngle_IsValid();
      test_verifyNewAngle_IsInvalid();
      test_convertToValid_max();
      test_convertToValid_min();
      test_convertToDegrees();
      test_convertToRadian();
      
   }
   
private:
   // Test the get degrees method
   void test_getDegrees()
   {
      // Setup
      AngleMock angle(90.0);
      
      // Exercise
      double value = angle.getDegrees();
      
      // Verify
      assert(value == 90.0);
   }  // Teardown...
   
   // Test the get radian method
   void test_getRadian()
   {
      // Setup
      AngleMock angle(180.0);
      
      // Exercise
      double value = angle.getRadian();
      
      // Verify
      assert(value == M_PI);
   }  // Teardown
   
   // Test the set angle method
   void test_setAngle()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      angle.setAngle(90.0);
      
      // Verify
      assert(angle.angle == 90.0);
   }  // Teardown
   
   // Test the adjust angle method
   void test_adjustAngle()
   {
      // Setup
      AngleMock angle (90.0);
      
      // Exercise
      angle.adjustAngle(90.0);
      
      // Verify
      assert(angle.angle == 180.0);
   }  // Teardown
   
   // Test the get radians method with a positive angle
   void test_getRadian_positive()
   {
      // Setup
      AngleMock angle(90.0);
      
      // Exercise
      double value = angle.getRadian();
      
      
      // Verify
      assert(value == (M_PI / 2));
   }  // Teardown...
   
   // Test the get radians method with a negative angle
   void test_getRadian_negative()
   {
      // Setup
      AngleMock angle(-90.0);
      
      // Exercise
      double value = angle.getRadian();
      
      // Verify
      assert(value == -(M_PI / 2));
   }  // Teardown...
   
   // Test that a valid new angle is valid
   void test_verifyNewAngle_IsValid()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      bool value = angle.verifyNewAngle(50.0);
      
      // Verify
      assert(value == true);
   }  // Teardown
   
   // Test that a invalid new angle is invalid
   void test_verifyNewAngle_IsInvalid()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      bool value = angle.verifyNewAngle(91.0);
      
      // Verify
      assert(value == false);
   }  // Teardown
   
   /* Test that an angle above the max angle
    * is converted to a valid angle.
    * This angle should be passed in 360 degrees
    * greater than the valid angle to test.
    * Example: 90 + 360 = 450
    * Pass in 450
    * Verify that the new angle is then 90
    */
   void test_convertToValid_max()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      double value = angle.convertToValid(450.0);
      
      // Verify
      assert(value == 90.0);
   }  // Teardown
   
   /* Test that an angle below the min angle
    * is converted to a valid angle.
    * This angle should be passed in 360 degrees
    * less than the valid angle to test.
    * Example: -90 - 360 = -450
    * Pass in -450
    * Verify that the new angle is then -90
    */
   void test_convertToValid_min()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      double value = angle.convertToValid(-450.0);
      
      // Verify
      assert(value == -90.0);
   }  // Teardown
   
   // Test the convert to degrees method
   void test_convertToDegrees()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      double value = angle.convertToDegrees(M_PI);
      
      // Verify
      assert(value == 180.0);
   }  // Teardown
   
   // Test the convert to radian method
   void test_convertToRadian()
   {
      // Setup
      AngleMock angle;
      
      // Exercise
      double value = angle.convertToRadian(180.0);
      
      // Verify
      assert(value == M_PI);
   }  // Teardown
};
