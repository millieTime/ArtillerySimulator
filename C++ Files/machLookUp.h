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
   MachLookUp() {};
   double getMach(double altitude) const {};
private:

};