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
#include "testGround.h"
#include "testAcceleration.h"
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
   TestProjectile().run();
   //TestGround().run();
   TestAcceleration().run();
   cout << "All tests passed" << endl;
}
