//
//  airDensityLookUpMock.h
//  Lab10
//
//  Created by Emilio on 3/12/22.
//

#pragma once
#include "airDensityLookUp.h"

class AirDensityLookUpMock : AirDensityLookUp
{
public:
   AirDensityLookUpMock() {};
   virtual double getDensity(double altitude) const 
   {
      // airMock  returns 1.225 if it gets a 0 or 2.
      if (altitude == 0.0 || altitude == 2.0)
         return 1.225;
      // airMock returns 0.7364 if altitude is 5000
      else if (altitude == 5000)
         return 0.7364;
      else
         assert(false);
   };
};
