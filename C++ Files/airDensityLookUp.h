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

class AirDensityLookUp : public LookUp
{
public:
   AirDensityLookUp() {};
   virtual double getDensity(double altitude) const { return 0.0; };
private:

};