/***********************************************************************
 * Header File:
 *    Test Air Density : Test the class air density
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for air density
 ************************************************************************/

#pragma once

#include "airDensity.h"       
#include "key1key2.h"
#include <cassert>
#include <iostream>
using namespace std;

class TestAirDensity
{
public:
   void run()
   {
      cout << "Air Density: ";
      test_getDensityZero();
      test_getDensityInTable();
      test_getDensityInterpolate();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Air Density Look Up
   //
   
   // Test the getDensity method for the 0 index
   void test_getDensityZero()
   {
      // Setup
      AirDensity air;
      
      // Exercise
      double value = air.getDensity(0.0);
      
      // Verify
      assert(value == 1.2250000);
   }  // Teardown
   
   // Test the getDenstiy method for another value in the table
   void test_getDensityInTable()
   {
      // Setup
      AirDensity air;
      
      // Exercise
      double value = air.getDensity(5000.0);
      
      // Verify
      assert(value == 0.7364000);
   }  // Teardown
   
   // Test the get density method for a value not in the table
   void test_getDensityInterpolate()
   {
      // Setup
      AirDensity air;
      
      // Exercise
      double value = air.getDensity(3050.0);
      
      // Verify

      assert(air.closeEnough(value, 0.90480));
   }  // Teardown
   
   // Test the search table method with the air density table
   void test_searchTable()
   {
      // Setup
      AirDensity air;
      
      // Exercise
      key1key2 value = air.searchTable(3050.0, air.table);
      
      // Verify
      assert(value.key1 == 3000.0);
      assert(value.key2 == 4000.0);
   }  // Teardown
   
   // Test the interpolate method with the air density table
   void test_interpolate()
   {
      // Setup
      AirDensity air;
      
      // Exercise
      double value = air.interpolate(3000.0, 0.9093000, 4000.0, 0.8194000, 3050.0);
      
      // Verify
      assert(air.closeEnough(value, 0.90480));
   }  // Teardown
   
};
