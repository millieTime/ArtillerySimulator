/***********************************************************************
 * Header File:
 *    Test Drag : Test the class drag
 * Author:
 *    Emilio Regino
 * Summary:
 *    All the unit tests for drag
 ************************************************************************/

#pragma once

#include "drag.h"
#include "key1key2.h"
#include <cassert>
#include <iostream>
using namespace std;

class TestDrag
{
public:
   void run()
   {
      cout << "Drag: ";
      test_getDragZero();
      test_getDragInTable();
      test_getDragInterpolate();
      test_searchTable();
      test_interpolate();
      cout << "Passed" << endl;
   }
private:
   //
   // Gravity Look Up
   //
   
   // Test the getDrag method for the 0 index
   void test_getDragZero()
   {
      // Setup
      Drag drag;
      
      // Exercise
      double value = drag.getDrag(0.300);
      
      // Verify
      assert(value == 0.1629);
   }  // Teardown
   
   // Test the getDrag method for another value in the table
   void test_getDragInTable()
   {
      // Setup
      Drag drag;
      
      // Exercise
      double value = drag.getDrag(0.890);
      
      // Verify
      assert(value == 0.2597);
   }  // Teardown
   
   // Test the getDrag method for a value not in the table
   void test_getDragInterpolate()
   {
      // Setup
      Drag drag;
      
      // Exercise
      double value = drag.getDrag(0.940);
      
      // Verify
      assert(drag.closeEnough(value, 0.31484));
   }  // Teardown
   
   // Test the search table method with the drag table
   void test_searchTable()
   {
      // Setup
      Drag drag;
      
      // Exercise
      key1key2 value = drag.searchTable(0.940, drag.table);
      
      // Verify
      assert(value.key1 == 0.920);
      assert(value.key2 == 0.960);
   }  // Teardown
   
   // Test the interpolate method with the drag table
   void test_interpolate()
   {
      // Setup
      Drag drag;
      
      // Exercise
      double value = drag.interpolate(0.920,  0.3010, 0.960, 0.3287, 0.940);
      
      // Verify
      assert(drag.closeEnough(value, 0.31484));
   }  // Teardown
   
};
