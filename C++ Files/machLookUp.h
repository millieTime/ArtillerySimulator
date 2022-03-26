/***********************************************************************
 * Header File:
 *    Mach Look Up: Determines the speed of sound at a given altitude
*     in the artillery simulation.
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the Mach Look Up class, just enough so the program compiles.
 *    Inherits from the Look Up class.
 ************************************************************************/


#pragma once
#include "lookUp.h"

class MachLookUp : public LookUp
{
public:
   // Make the test class a friend
   friend class TestMachLookUp;
   
   MachLookUp()
   {
      table[0] = tableItem(0.0,      340.0);
      table[1] = tableItem(1000.0,   336.0);
      table[2] = tableItem(2000.0,   332.0);
      table[3] = tableItem(3000.0,   328.0);
      table[4] = tableItem(4000.0,   324.0);
      table[5] = tableItem(5000.0,   320.0);
      table[6] = tableItem(6000.0,   316.0);
      table[7] = tableItem(7000.0,   312.0);
      table[8] = tableItem(8000.0,   308.0);
      table[9] = tableItem(9000.0,   303.0);
      table[10] = tableItem(10000.0,  299.0);
      table[11] = tableItem(15000.0,  295.0);
      table[12] = tableItem(20000.0,  295.0);
      table[13] = tableItem(25000.0,  295.0);
      table[14] = tableItem(30000.0,  305.0);
      table[15] = tableItem(40000.0,  324.0);
   };
   
   double getMach(double altitude) const;
   
private:
   tableItem table [16];         // The table array
   
   tableItem searchTable(double keyNotFound) const;
   // convenience idea, return a collection of two table items. Don't make the client deconstruct.
   
   double interpolate(double x1, double y1, double x2, double y2, double toFind) const;
   
   bool closeEnough(double computedValue, double hardcodeValue) const;
};
