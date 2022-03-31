/***********************************************************************
 * Header File:
 *    Test Mach : Test the class mach
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for mach
 ************************************************************************/

#pragma once

#include "mach.h"
#include "key1Key2.h"
#include <iostream>
using namespace std;

class TestMach
{
public:
   void run()
   {
      cout << "Mach: ";
      test_getMachZero();
      test_getMachInTable();
      test_getMachInterpolate();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Gravity Look Up
   //
   
   // Test the getMach method for the 0 index
   void test_getMachZero()
   {
      // Setup
      Mach mach;
      
      // Exercise
      double value = mach.getMach(0.0);
      
      // Verify
      assert(value == 340.0);
   }  // Teardown
   
   // Test the getMach method for another value in the table
   void test_getMachInTable()
   {
      // Setup
      Mach mach;
      
      // Exercise
      double value = mach.getMach(5000.0);
      
      // Verify
      assert(value == 320.0);
   }  // Teardown
   
   // Test the getMach method for a value not in the table
   void test_getMachInterpolate()
   {
      // Setup
      Mach mach;
      
      // Exercise
      double value = mach.getMach(3050.0);
      
      // Verify
      assert(mach.closeEnough(value, 327.8));
   }  // Teardown
   
   // Test the search table method with the mach table
   void test_searchTable()
   {
      // Setup
      Mach mach;
      
      // Exercise
      key1key2 value = mach.searchTable(3050.0, mach.table);
      
      // Verify
      assert(value.key1 == 3000.0);
      assert(value.key2 == 4000.0);
   }  // Teardown
   
   // Test the interpolate method with the mach table
   void test_interpolate()
   {
      // Setup
      Mach mach;
      
      // Exercise
      double value = mach.interpolate(3000.0, 328.0, 4000.0, 324.0, 3050.0);
      
      // Verify
      assert(mach.closeEnough(value, 327.8));
   }  // Teardown
   
};

