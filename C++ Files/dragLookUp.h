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
   DragLookUp() {};
   virtual double getDrag(double mach) const { return 0.0; };
private:

};