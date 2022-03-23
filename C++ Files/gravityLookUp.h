/***********************************************************************
 * Header File:
 *    Gravity Look Up : Determines the gravity at a given altitude
 *    in the artillery simulation.
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the Gravity Look Up class, just enough so the program compiles.
 *    Inherits from the Look Up class.
 ************************************************************************/

#pragma once

#include "lookUp.h"

class GravityLookUp : public LookUp
{
public:
   GravityLookUp() {};
   double getGravity(double altitude) const { assert(false); return 0.0;};
private:

};
