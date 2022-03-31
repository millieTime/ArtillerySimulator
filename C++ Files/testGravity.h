/****************************************************************************************
 * Header File:
 *    Test Gravity Look Up: The test suite for the gravity look up class.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Unit tests to exercise the gravity look up class.
 ****************************************************************************************/

#pragma once
#include "gravity.h"
#include "key1Key2.h"
#include <iostream>
using namespace std;

class TestGravity
{
public:
   void run()
   {
      cout << "Gravity: ";
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
   
   // Test the getGravity method for the 0 index
   void test_getGravityZero()
   {
      // Setup
      Gravity grav;
      
      // Exercise
      double value = grav.getGravity(0.0);
      
      // Verify
      assert(value == 9.807);
   }  // Teardown
   
   // Test the getGravity method for another value in the table
   void test_getGravityInTable()
   {
      // Setup
      Gravity grav;
      
      // Exercise
      double value = grav.getGravity(5000.0);
      
      // Verify
      assert(value == 9.791);
   }  // Teardown
   
   // Test the getGravity method for a value not in the table
   void test_getGravityInterpolate()
   {
      // Setup
      Gravity grav;
      
      // Exercise
      double value = grav.getGravity(3050.0);
      
      // Verify
      assert(grav.closeEnough(value, 9.79685));
   }  // Teardown
   
   // Test the search table method with the gravity table
   void test_searchTable()
   {
      // Setup
      Gravity grav;
      
      // Exercise
      key1key2 value = grav.searchTable(3050.0, grav.table);
      
      // Verify
      assert(value.key1 == 3000.0);
      assert(value.key2 == 4000.0);
   }  // Teardown
   
   // Test the interpolate method with the gravity table
   void test_interpolate()
   {
      // Setup
      Gravity grav;
      
      // Exercise
      double value = grav.interpolate(3000.0, 9.797, 4000.0, 9.794, 3050.0);
      
      // Verify
      assert(grav.closeEnough(value, 9.79685));
   }  // Teardown
   
};
