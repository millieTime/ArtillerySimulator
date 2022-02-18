// C++ Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>              /* for atan() */
#include <map>                /* for map */
#include "airDensity.cpp"     /* for air density table look up */
#include "drag.cpp"           /* for drag coefficient table look up */
#include "mach.cpp"           /* for mach table look up */
#include "gravity.cpp"        /* for gravity table look up */

using std::map;               /* for just map in std */
using std::tuple;             /* for just tuple in std */


/*******************************************************************
 *  CALCULATE VERTICAL COMPONENT
 *  A function to calculate the vertical component of the bullet.
 *
 *  dy = s cos(a)
 *  Where:
 *    dy = vertical component of speed (m/s)
 *    s = overall speed (m/s)
 *    a = directon of travel where 0 is pointing up (radians)
 * *******************************************************************/
double calcVertComp(double speed, double angle)
{
   // QUESTIONS:
   // WHAT IS A AND WHERE DOES IT COME FROM
   // WE JUST NEED TO FACTOR GRAVITY HERE RIGHT
   return speed * cos(angle);
}

/*******************************************************************
 *  CALCULATE HORIZONTAL COMPONENT
 *  A function to calculate the horizontal component of the bullet.
 *
 *  dx = s sin(a)
 *  Where:
 *    s = overall speed (m/s)
 *    a = directon of travel where 0 is pointing up (radians)
 * *******************************************************************/

double calcHorComp(double speed, double angle)
{
   // QUESTIONS:
   // WHAT IS A AND WHERE DOES IT COME FROM
   // WE JUST NEED TO FACTOR DRAG HERE RIGHT?
   
   return speed * sin(angle);
}

/********************************************************************
 * CALCULATE ANGLE
 *  A function to calculate an angle. The
 *  angle is  expected in degrees and returned in radians.
 *
 *  a = atan(dx, dy)
 *  Where:
 *    a = directon of travel where 0 is pointing up (radians)
 *    dx = horizontal component of speed (m/s)
 *    dy = vertical component of speed (m/s)
 *********************************************************************/
double calcAngle(double dx, double dy)
{
   return atan2(dx, dy);
}

/********************************************************************
 *  SEARCH TABLE
 *  A function that will take in a key not contained in the table
 *  as a parameter and will return the keys just before and
 *  just after the not found key's theoretical place.
 *
 *  In other words, of all the keys that are lower than the key
 *  not contained in the table, we want to return the greatest
 *  which must be the key just under the not contained key.
 *
 *  And of all the keys that are greater than the key not
 *  contained in the table, we want to return the least
 *  which must be the key just above the not contained key
 *********************************************************************/
tuple<double, double> searchTable(double nckey, map<double, double> table)
{
   // assign the map iterator to the begining of the table
   map<double, double>::iterator it = table.begin();
   
   // assign high and low values to the first and last keys in the map
   double high = table.begin()->first;
   double low = table.end()->first;
   
   // Loop through the map
   while (it != table.end())
   {
      // If the current key is less than the not contained key
      if (it->first < nckey)
      {
         // and it is greater than the current low
         if (it->first > low)
         {
            // It becomes the new low
            low = it->first;
         }
      }
      else // the current key must be greater than the not contained key
      {
         // if it is less than the current high
         if (it->first < high)
         {
            // it becomes the new high
            high = it->first;
         }
      }
   }
   
   tuple<double, double> keys (low, high);
   
   return keys;
}


/*********************************************************************
 *  LOOK UP AIR DENSITY
 *  A function to look up the density of the air at a given
 *  altitude.
 *  Altitude is expected in meters.
 *
 *  The look up tables are imported from airDensity.h
 *********************************************************************/
double luAirDensity(double altitude)
{
   if (airDensityValues.find(altitude) == airDensityValues.end())
   {
      // Find the value just under the missing key and the value just over
      tuple <double, double> keys = searchTable(altitude, airDensityValues);
      
      // Use those keys to get the two points around the missing point
      double x0 = get<0>(keys);
      double y0 = airDensityValues[x0];
      double x1 = get<1>(keys);
      double y1 = airDensityValues[x1];
      double x = altitude;
      
      // Interpolate for y
      return interpolate(x0, y0, x1, y1, x);
   }
   else
   {
      return airDensityValues[altitude];
   }
}


/*********************************************************************
 *  LOOK UP MACH
 *  A function to look up the mach speed at a given altitude.
 *  Altitude is expected in meters.
 *
 *  The look up tables are imported from mach.h
 *********************************************************************/
double luMach(double altitude)
{
   if (machValues.find(altitude) == machValues.end())
   {
      // Find the value just under the missing key and the value just over
      tuple <double, double> keys = searchTable(altitude, machValues);
      
      // Use those keys to get the two points around the missing point
      double x0 = get<0>(keys);
      double y0 = machValues[x0];
      double x1 = get<1>(keys);
      double y1 = machValues[x1];
      double x = altitude;
      
      // Interpolate for y
      return interpolate(x0, y0, x1, y1, x);
   }
   else
   {
      return machValues[altitude];
   }
}


/*********************************************************************
 *  LOOK UP GRAVITY
 *  A function to look up gravity at  a given altitude.
 *  Altitude is expected in meters.
 *
 *  The look up tables are imported from gravity.h
 *********************************************************************/
double luGravity(double altitude)
{
   if (gravityValues.find(altitude) == gravityValues.end())
   {
      // Find the value just under the missing key and the value just over
      tuple <double, double> keys = searchTable(altitude, gravityValues);
      
      // Use those keys to get the two points around the missing point
      double x0 = get<0>(keys);
      double y0 = gravityValues[x0];
      double x1 = get<1>(keys);
      double y1 = gravityValues[x1];
      double x = altitude;
      
      // Interpolate for y
      return interpolate(x0, y0, x1, y1, x);
   }
   else
   {
      return gravityValues[altitude];
   }
}


/*********************************************************************
 * LOOK UP DRAG COEFFICIENT
 * A function to look up drag coefficient at a given mach
 *
 * The look up tables are imported from drag.h
 *********************************************************************/
double luDragCoeff(double mach)
{
   if (dragValues.find(mach) == dragValues.end())
   {
      // Find the value just under the missing key and the value just over
      tuple <double, double> keys = searchTable(mach, dragValues);
      
      // Use those keys to get the two points around the missing point
      double x0 = get<0>(keys);
      double y0 = dragValues[x0];
      double x1 = get<1>(keys);
      double y1 = dragValues[x1];
      double x = mach;
      
      // Interpolate for y
      return interpolate(x0, y0, x1, y1, x);
   }
   else
   {
      return dragValues[mach];
   }
}


int main()
{
   luAirDensity(1000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
