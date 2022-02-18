/*****************************************************
 * GRAVITY
 * A file to store the gravity look up values.
 ******************************************************/

//
//  gravity.cpp
//  ArtillerySimulatorPrototype
//
//  Created by Emilio on 2/18/22.
//

#include <iostream>
#include <map>            // for map
using std::map;

map <double, double> gravityValues
{
   {0,      9.807},
   {1000,   9.804},
   {2000,   9.801},
   {3000,   9.797},
   {4000,   9.794},
   {5000,   9.791},
   {6000,   9.788},
   {7000,   9.785},
   {8000,   9.782},
   {9000,   9.779},
   {10000,  9.776},
   {15000,  9.761},
   {20000,  9.745},
   {25000,  9.730}
};
