/***********************************************************************
 * Header File:
 *    Gravity Look Up : Determines the gravity at a given altitude
 *    in the artillery simulation.
 * Author:
 *    Preston Millward & Emilio Regino
 * Summary:
 *    The Gravity Look Up class
 *    Inherits from the Look Up class.
 ************************************************************************/

#pragma once
#include "lookUp.h"
#include "tableItem.h"


class GravityLookUp : public LookUp
{
public:
   // Make friend for testing
   friend class TestGravityLookUp;
   
   GravityLookUp() {
      table[0] = tableItem(0.0,       9.807);
      table[1] = tableItem(1000.0,    9.804);
      table[2] = tableItem(2000.0,    9.801);
      table[3] = tableItem(3000.0,    9.797);
      table[4] = tableItem(4000.0,    9.794);
      table[5] = tableItem(5000.0,    9.791);
      table[6] = tableItem(6000.0,    9.788);
      table[7] = tableItem(7000.0,    9.785);
      table[8] = tableItem(8000.0,    9.782);
      table[9] = tableItem(9000.0,    9.779);
      table[10] = tableItem(10000.0,  9.776);
      table[11] = tableItem(15000.0,  9.761);
      table[12] = tableItem(20000.0,  9.745);
      table[13] = tableItem(25000.0,  9.730);
   };
   
   // Getters
   virtual double getGravity(double altitude) const;
private:
   tableItem table [14];         // The table array
   
   tableItem searchTable(double keyNotFound) const;
   // convenience idea, return a collection of two table items. Don't make the client deconstruct.
   
   double interpolate(double x1, double y1, double x2, double y2, double toFind) const;
   
   bool closeEnough(double computedValue, double hardcodeValue) const;
};
