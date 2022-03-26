/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testProjectile.h"
#include "testHowitzer.h"
#include "testGround.h"
#include "testAngle.h"
#include "testVector2D.h"
#include "testGravityLookUp.h"
#include "testAirDensityLookUp.h"
#include "testDragLookUp.h"
#include "testMachLookUp.h"
#include "testAcceleration.h"
#include "testVelocity.h"
#include <iostream>
using namespace std;

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   cout << "Testing. . ." << endl;
   TestPosition().run();
   TestAcceleration().run();
   TestProjectile().run();
//   TestGround().run();
   TestAngle().run();
   TestVector().run();
   TestGravityLookUp().run();
   TestAirDensityLookUp().run();
   TestDragLookUp().run();
   TestMachLookUp().run();
   TestVelocity().run();
   TestHowitzer().run();
   cout << "All tests passed" << endl;
}
