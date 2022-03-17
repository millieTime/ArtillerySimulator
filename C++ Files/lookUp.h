/***********************************************************************
 * Header File:
 *    Look Up : Contains a table of keys and values, with the ability to
 *    search for a value given a key and interpolate if the key is not present.
 * Author:
 *    Preston Millward
 * Summary:
 *    Stub of the Look Up class, just enough so the program compiles.
 ************************************************************************/
#pragma once

#include <tuple>

class LookUp
{
public:
   LookUp() {};

protected:
   std::tuple<double, double> * table;
   double get_value(double input) {};
   double interpolate(double x1, double x2, double y1, double y2, double toFind) {};
};