/****************************************************************************************
 * Header File:
 *    Test Gravity Look Up: The test suite for the gravity look up class.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Unit tests to exercise the gravity look up class.
 ****************************************************************************************/

#include "gravityLookUp.h"
#include <iostream>
using namespace std;

class TestGravityLookUp
{
public:
   void run()
   {
      cout << "Gravity Look Up: ";
      test_getGravityZero();
      test_getGravityInTable();
      test_getGravityInterpolate();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Gravity Look Up
   //
   
   //
   void test_getGravityZero()
   {
      // Setup
      GravityLookUp grav;
      
      // Exercise
      double value = grav.getGravity(0.0);
      
      // Verify
      assert(value == 9.807);
   }  // Teardown
   
   //
   void test_getGravityInTable()
   {
      // Setup
      GravityLookUp grav;
      
      // Exercise
      double value = grav.getGravity(5000.0);
      
      // Verify
      assert(value == 9.791);
   }  // Teardown
   
   //
   void test_getGravityInterpolate()
   {
      // Setup
      GravityLookUp grav;
      
      // Exercise
      double value = grav.getGravity(3050.0);
      
      // Verify
      assert(grav.closeEnough(value, 9.79685));
   }  // Teardown
   
   void test_searchTable()
   {
      // Setup
      GravityLookUp grav;
      
      // Exercise
      tableItem value = grav.searchTable(3050.0);
      
      // Verify
      assert(value.key == 3000.0);
      assert(value.value == 4000.0);
   }  // Teardown
   
   void test_interpolate()
   {
      // Setup
      GravityLookUp grav;
      
      // Exercise
      double value = grav.interpolate(3000.0, 9.797, 4000.0, 9.794, 3050.0);
      
      // Verify
      assert(grav.closeEnough(value, 9.79685));
   }  // Teardown
   
};
