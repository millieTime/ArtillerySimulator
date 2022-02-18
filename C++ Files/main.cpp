// C++ Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>              /* for atan() */
#include "airDensity.h"       /* for air density table look up */

using namespace std;


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
double calcVertComp(double speed, double a)
{
   // QUESTIONS:
   // WHAT IS A AND WHERE DOES IT COME FROM
   // WE JUST NEED TO FACTOR GRAVITY HERE RIGHT
   return speed * cos(a);
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

double calcHorComp(double speed, double a)
{
   // QUESTIONS:
   // WHAT IS A AND WHERE DOES IT COME FROM
   // WE JUST NEED TO FACTOR DRAG HERE RIGHT?
   
   return speed * sin(a);
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
      // not found so first get the previous point and the next point.
      
      // do string interpolation here
      return 0.0;
   }
   else
   {
      cout << airDensityValues[altitude];
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
double luMach()
{
   // look up mach here
   return 0.0;
}


/*********************************************************************
 *  LOOK UP GRAVITY
 *  A function to look up gravity at  a given altitude.
 *  Altitude is expected in meters.
 *
 *  The look up tables are imported from gravity.h
 *********************************************************************/
double luGravity()
{
   // look up gravity here
   return 0.0;
}


/*********************************************************************
 * LOOK UP DRAG COEFFICIENT
 * A function to look up drag coefficient at a given mach
 *
 * The look up tables are imported from drag.h
 *********************************************************************/
double luDragCoeff()
{
   // look up drag coefficient here
   return 0.0;
}


int main()
{
   cout << "Hello World!";
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
