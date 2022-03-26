#include "machLookUp.h"
#include <iostream>
using namespace std;

class TestMachLookUp
{
public:
   void run()
   {
      cout << "Mach Look Up: ";
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
   
   //
   void test_getMachZero()
   {
      // Setup
      MachLookUp mach;
      
      // Exercise
      double value = mach.getMach(0.0);
      
      // Verify
      assert(value == 340.0);
   }  // Teardown
   
   //
   void test_getMachInTable()
   {
      // Setup
      MachLookUp mach;
      
      // Exercise
      double value = mach.getMach(5000.0);
      
      // Verify
      assert(value == 320.0);
   }  // Teardown
   
   //
   void test_getMachInterpolate()
   {
      // Setup
      MachLookUp mach;
      
      // Exercise
      double value = mach.getMach(3050.0);
      
      // Verify
      assert(mach.closeEnough(value, 327.8));
   }  // Teardown
   
   void test_searchTable()
   {
      // Setup
      MachLookUp mach;
      
      // Exercise
      tableItem value = mach.searchTable(3050.0);
      
      // Verify
      assert(value.key == 3000.0);
      assert(value.value == 4000.0);
   }  // Teardown
   
   void test_interpolate()
   {
      // Setup
      MachLookUp mach;
      
      // Exercise
      double value = mach.interpolate(3000.0, 328.0, 4000.0, 324.0, 3050.0);
      
      // Verify
      assert(mach.closeEnough(value, 327.8));
   }  // Teardown
   
};

