/***********************************************************************
 * Source File:
 *    Test Vecto2Dr: A class to test the Vector2D class
 * Author:
 *    Emilio Regino
 * Summary:
 *    Contains the unit tests for the vector2D class
 ************************************************************************/

#include "Vector2DMock.h"

class TestVector
{
public:
   // A method to run the tests
   void run()
   {
      test_getHorComponent();
      test_getVertComponent();
      test_getMagnitude();                      // tests need to be implemented
      test_getAngle();                          // tests need to be implemented
      test_setHorizontalComponent();
      test_setVerticalComponent();
      test_setMagnitude();                        // tests needs to be implemented
      test_setAngle();                            // test needs to be implemented
   }
   
private:
   //
   // Vector
   //
   
   // Test the get horizontal component method
   void test_getHorComponent()
   {
      // Setup
      Vector2DMock vector (10.0, 0.0);
      double vert = vector.getVertComponent();
      
      // Exercise
      double value = vector.getHorComponent();
      
      // Verify
      assert(value == 10.0);
      assert(vert == 0.0);
   }  // Teardown
   
   // Test the get vertical component method
   void test_getVertComponent()
   {
      // Setup
      Vector2DMock vector (0.0, 10.0);
      double hor = vector.getHorComponent();
      
      // Exercise
      double value = vector.getVertComponent();
      
      // Verify
      assert(hor == 0.0);
      assert(value == 10.0);
   }  // Teardown
   
   // Test the get magnitude component method
   void test_getMagnitude()
   {
      // Setup
      Vector2DMock vector;
      
      // Exercise
      double value = vector.getMagnitude();
      
      // Verify
      assert(value == 0.0);
   }  // Teardown
   
   // Test the get angle component method
   void test_getAngle()
   {
      // Setup
      Vector2DMock vector;
      
      // Exercise
      Angle value = vector.getAngle();
      
      // Verify
      assert(value.getDegrees() == 0.0);
   }  // Teardown
   
   // Test the set horizontal component method
   void test_setHorizontalComponent()
   {
      // Setup
      Vector2DMock vector;
      
      // Exercise
      vector.setHorizontal(10.0);
      
      // Verify
      assert(vector.horizontalComponent == 10.0);
      assert(vector.verticalComponent == 0.0);
   }  // Teardowns
   
   // Test the set vertical component method
   void test_setVerticalComponent()
   {
      // Setup
      Vector2DMock vector;
      
      // Exercise
      vector.setVertical(10.0);
      
      // Verify
      assert(vector.horizontalComponent == 0.0);
      assert(vector.verticalComponent == 10.0);
   }  // Teardowns
   
   // Test the set magnitude method
   void test_setMagnitude()
   {
      // Setup
      Vector2DMock vector;
      
      // Exercise
      vector.setMagnitude(10.0);
      
      // Verify
      assert(vector.magnitude == 10.0);
   }  // Teardown
   
   // Test the set angle method
   void test_setAngle()
   {
      // Setup
      Vector2DMock vector;
      Angle newAngle(90.0);
      
      // Exercise
      vector.setAngle(newAngle);
      
      // Verify
      assert(vector.angle.getDegrees() == 90.0);
   }  // Teardown
};
