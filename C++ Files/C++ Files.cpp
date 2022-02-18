// C++ Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Preston's Functions.cpp"

using namespace std;

// Define some constants of the shell.
const double INITIAL_VELOCITY = 827.0;   // m/s
const double SHELL_MASS       = 46.7;    // kg
const double SHELL_DIAMETER   = 0.15489; // m
const double ELAPSED_TIME     = 0.5;     // s
enum motionIndexes { TIME, X, Y, DX, DY };


void computeNewMotion(double(&previousValues)[5], double(&currentValues)[5])
{
   // Calculate previous acceleration from previous position, velocity, and constants
   // Calculate current velocity from previous acceleration and velocity.
   // Calculate current position from previous acceleration, velocity, and position.
   // Calculate current time from previous time.
   double accelerationX = 0.0;
   double accelerationY = 0.0;
   double dragAcceleration = computeAcceleration(SHELL_MASS, computeDrag(getDragCoeff(), getDensity(), hypotenuseFromComponents(), circleAreaFromDiameter());
   accelerationX = getDX(dragAcceleration, angleFromComponents());
   accelerationY = getDY(dragAcceleration, angleFromComponents()) - getGravity();

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
   double initialDX = getDX(INITIAL_VELOCITY, angleRadians);
   double initialDY = getDY(INITIAL_VELOCITY, angleRadians);

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

