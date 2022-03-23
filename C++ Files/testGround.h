//
//  testGround.h
//  Lab08
//
//  Created by Emilio on 3/5/22.
//

#pragma once
#include "ground.h"
#include "position.h"
#include <cassert>    // for ASSERT

/************************************************************************************
 * GROUND TEST
 *
 * A class to test a ground class
 ************************************************************************************/
//class TestGround
//{
//public:
//   void run()
//   {
//      // Run the tests
//      groundTestReset();
//      groundTestHitGroundTrue();
//      groundTestHitGroundFalse();
//      groundTestHitTargetTrue();
//      groundTestHitTargetFalse();
//      groundTestGetElevationMeters();
//      groundTestGetTarget();
//   }
//   
//private:
//   
//   //
//   // Ground
//   //
//   
//   
//   // Verify that reset creates a ground
//   // to fit the screen
//   void groundTestReset()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      
//      // exercise
//      g.reset(ptHowitzer);
//      
//      // verify
//      int lastXPoint = (int) ptUpperRight.getPixelsX();
//      double elevation = g.ground[lastXPoint];
//      assert(elevation != NULL);
//      
//      // teardown
//   }
//   
//   // Verify that we are alerted when we hit the
//   // ground
//   void groundTestHitGroundTrue()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      g.reset(ptHowitzer);
//      
//      // exercise
//      int x = (int) ptUpperRight.getPixelsX();
//      double newElevation = g.ground[x];
//      Position somePosition;
//      somePosition.setPixelsX(x);
//      somePosition.setPixelsY(newElevation);
//      bool value = g.hitGround(somePosition);
//      
//      // verify
//      assert(value == true);
//      
//      // teardown
//   }
//   
//   // Verify that we are not falsely alerted
//   // when we have not hit the ground
//   void groundTestHitGroundFalse()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      g.reset(ptHowitzer);
//      
//      // exercise
//      int x = (int) ptUpperRight.getPixelsX();
//      double newElevation = g.ground[x];
//      Position somePosition;
//      somePosition.setPixelsX(x);
//      somePosition.setPixelsY(newElevation + 20.0);
//      bool value = g.hitGround(somePosition);
//      
//      // verify
//      assert(value == false);
//      
//      // teardown
//   }
//   
//   // Verify that we are alerted when we hit the
//   // target
//   void groundTestHitTargetTrue()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      g.reset(ptHowitzer);
//      
//      // exercise
//      bool value = g.hitGround(g.posTarget);
//      
//      // verify
//      assert(value == true);
//      
//      // teardown
//   }
//   
//   // Verify that we are not falsely alerted
//   // when we do not hit the target
//   void groundTestHitTargetFalse()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      g.reset(ptHowitzer);
//      
//      // exercise
//      Position notTarget = g.posTarget;
//      notTarget.addMetersY(20.0);
//      bool value = g.hitGround(notTarget);
//      
//      // verify
//      assert(value == false);
//      
//      // teardown
//   }
//   
//   // Verify get elevation returns the correct value
//   void groundTestGetElevationMeters()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      g.reset(ptHowitzer);
//      
//      // exercise
//      double pixels = g.ground[(int)ptUpperRight.getPixelsX()];
//      Position pos = ptUpperRight;
//      pos.setPixelsY(pixels);
//      double meters = pos.getMetersY();
//      double value = g.getElevationMeters(ptUpperRight);
//      
//      // verify
//      assert(value == meters);
//      
//      // teardown
//   }
//   
//   // Verify that get target returns the target position
//   void groundTestGetTarget()
//   {
//      // setup
//      Position ptUpperRight;
//      ptUpperRight.setPixelsX(700.0);
//      ptUpperRight.setPixelsY(500.0);
//      Ground g = Ground(ptUpperRight);
//      
//      Position ptHowitzer;
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      g.reset(ptHowitzer);
//      
//      // exercise
//      Position target = g.getTarget();
//      Position pos(120.0, 360.0);
//      g.posTarget = pos;
//      
//      // verify
//      assert(target.getPixelsX() == 3.0);
//      assert(target.getPixelsY() == 9.0);
//      assert(target.getMetersX() == 120.0);
//      assert(target.getMetersY() == 360.0);
//      
//      
//      // teardown
//   }
//};
