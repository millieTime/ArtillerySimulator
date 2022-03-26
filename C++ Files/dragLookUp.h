/***********************************************************************
 * Header File:
 *    Drag Look Up : Determines the drag at a given ratio of mach speed
 *    in the artillery simulation.
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the Drag Look Up class, just enough so the program compiles.
 *  *    Inherits from the Look Up class.
 ************************************************************************/

#pragma once
#include "lookUp.h"

class DragLookUp : public LookUp
{
public:
   // Test class is a friend
   friend class TestDragLookUp;
   DragLookUp()
   {
      table[0] = tableItem(0.300,    0.1629);
      table[1] = tableItem(0.500,    0.1659);
      table[2] = tableItem(0.700,    0.2031);
      table[3] = tableItem(0.890,    0.2597);
      table[4] = tableItem(0.920,    0.3010);
      table[5] = tableItem(0.960,    0.3287);
      table[6] = tableItem(0.980,    0.4002);
      table[7] = tableItem(1.000,    0.4258);
      table[8] = tableItem(1.020,    0.4335);
      table[9] = tableItem(1.060,   0.4483);
      table[10] = tableItem(1.240,   0.4064);
      table[11] = tableItem(1.530,   0.3663);
      table[12] = tableItem(1.990,   0.2897);
      table[13] = tableItem(2.870,   0.2297);
      table[14] = tableItem(2.890,   0.2306);
      table[15] = tableItem(5.000,   0.2656);
   };
   
   virtual double getDrag(double mach) const;
private:
   tableItem table [16];         // The table array
   
   tableItem searchTable(double keyNotFound) const;
   // convenience idea, return a collection of two table items. Don't make the client deconstruct.
   
   double interpolate(double x1, double y1, double x2, double y2, double toFind) const;
   
   bool closeEnough(double computedValue, double hardcodeValue) const;
};
