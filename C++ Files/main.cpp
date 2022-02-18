// C++ Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>              /* for atan() */
#include <map>                /* for map */
#include "airDensity.cpp"     /* for air density table look up */
#include "drag.cpp"           /* for drag coefficient table look up */
#include "mach.cpp"           /* for mach table look up */
#include "gravity.cpp"        /* for gravity table look up */
#include "Preston's Functions.cpp" /* For Preston's functions */

using std::map;               /* for just map in std */
using std::tuple;             /* for just tuple in std */
using std::cout;              /* for screen output */
using std::cin;               /* for user input */

// Define some constants of the shell.
const double INITIAL_VELOCITY = 827.0;   // m/s
const double SHELL_MASS       = 46.7;    // kg
const double SHELL_DIAMETER   = 0.15489; // m
const double ELAPSED_TIME     = 0.5;     // s
enum motionIndexes { TIME, X, Y, DX, DY };

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

void computeNewMotion(double(&previousValues)[5], double(&currentValues)[5])
{
   // Calculate previous acceleration from previous position, velocity, and constants
   // Calculate current velocity from previous acceleration and velocity.
   // Calculate current position from previous acceleration, velocity, and position.
   // Calculate current time from previous time.
   double accelerationX = 0.0;
   double accelerationY = 0.0;
   double altitude = previousValues[Y];
   double velocityX = previousValues[DX];
   double velocityY = previousValues[DY];
   double computedDrag = computeDrag(luDragCoeff(luMach(altitude)), luAirDensity(altitude),
                                     hypotenuseFromComponents(velocityX, velocityY),
                                     circleAreaFromDiameter(SHELL_DIAMETER));
   double dragAcceleration = computeAcceleration(SHELL_MASS, computedDrag);
   
   accelerationX = calcHorComp(dragAcceleration, calcAngle(velocityX, velocityY));
   accelerationY = calcVertComp(dragAcceleration, calcAngle(velocityX, velocityY) - luGravity(altitude));

   currentValues[DX] = previousValues[DX] + accelerationX * ELAPSED_TIME;
   currentValues[DY] = previousValues[DY] + accelerationY * ELAPSED_TIME;

   currentValues[X] = previousValues[X] + previousValues[DX] * ELAPSED_TIME + 0.5 * accelerationX * ELAPSED_TIME * ELAPSED_TIME;
   currentValues[Y] = previousValues[Y] + previousValues[DY] * ELAPSED_TIME + 0.5 * accelerationY * ELAPSED_TIME * ELAPSED_TIME;

   currentValues[TIME] = previousValues[TIME] + ELAPSED_TIME;
}

int main()
{
   // Get user input.
   cout << "What is the angle of the howitzer where 0 is up ? ";
   double angleDegrees = 0;
   cin >> angleDegrees;
   double angleRadians = radiansFromDegrees(angleDegrees);

   // Initialize the two arrays of shell motion information.
   // time, x, y, dx, dy, 
   double initialDX = calcHorComp(INITIAL_VELOCITY, angleRadians);
   double initialDY = calcVertComp(INITIAL_VELOCITY, angleRadians);

   double values1[5] = { 0, 0, 0, initialDX, initialDY};
   double values2[5] = { 0, 0, 0, initialDX, initialDY};
   bool use1 = true;

   // Let's get crackin!
   // Keep mathing until one altitude is less than or equal to zero.
   while (values1[Y] > 0 and values2[Y] > 0)
   {
      if (use1)
      {
         computeNewMotion(values1, values2);
      }
      else
      {
         computeNewMotion(values2, values1);
      }
      // Switch to using the other values next time.
      use1 = !use1;
   }

   // Okay, at this point one of the value arrays is for a positive altitude
   // and the other is for a negative or zero altitude.
   // values1 will be the negative or zero one if use1, otherwise it's values2
   if (use1)
   {
      if (values1[Y] == 0)
      {
         return values1[TIME];
      }
      else
      {
         return interpolate(values2[Y], values2[TIME], values1[Y], values1[TIME], 0.0);
      }
   }
   else
   {
      if (values2[Y] == 0)
      {
         return values2[TIME];
      }
      else
      {
         return interpolate(values1[Y], values1[TIME], values2[Y], values2[TIME], 0.0);
      }
   }

}
