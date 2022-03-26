/***********************************************************************
 * Header File:
 *    Air Density Look Up: Determines the air density at a given altitude
*     in the artillery simulation.
 * Author:
 *    Preston Millward 
 * Summary:
 *    Stub of the Air Density Look Up class, just enough so the program compiles.
 *    Inherits from the Look Up class.
 ************************************************************************/

#pragma once

#include "lookUp.h"
#include "tableItem.h"

class AirDensityLookUp : public LookUp
{
public:
   AirDensityLookUp() {
      table[1] = tableItem(0.0,       1.2250000);
      table[2] = tableItem(1000.0,    1.1120000);
      table[3] = tableItem(2000.0,    1.0070000);
      table[4] = tableItem(3000.0,    0.9093000);
      table[5] = tableItem(4000.0,    0.8194000);
      table[6] = tableItem(5000.0,    0.7364000);
      table[7] = tableItem(6000.0,    0.6601000);
      table[8] = tableItem(7000.0,    0.5900000);
      table[9] = tableItem(8000.0,    0.5258000);
      table[10] = tableItem(9000.0,   0.4671000);
      table[11] = tableItem(10000.0,  0.4135000);
      table[12] = tableItem(15000.0,  0.1948000);
      table[13] = tableItem(20000.0,  0.0889100);
      table[14] = tableItem(25000.0,  0.0400800);
      table[15] = tableItem(30000.0,  0.0184100);
      table[16] = tableItem(40000.0,  0.0039960);
      table[17] = tableItem(50000.0,  0.0010270);
      table[18] = tableItem(60000.0,  0.0003097);
      table[19] = tableItem(70000.0,  0.0000828);
      table[20] = tableItem(80000.0,  0.0000185);
   };

   // Getters
   virtual double getDensity(double altitude) const;
private:
   tableItem table [21];         // The table array
   
   tableItem searchTable(double keyNotFound) const;
   // convenience idea, return a collection of two table items. Don't make the client deconstruct.
   
   double interpolate(double x1, double y1, double x2, double y2, double toFind) const;
   
   bool closeEnough(double computedValue, double hardcodeValue) const;
};
