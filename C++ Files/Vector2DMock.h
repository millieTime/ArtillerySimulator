//
//  Vector2DMock.h
//  ArtillerySimulator
//
//  Created by Emilio on 3/22/22.
//

#include "vector2D.h"

class Vector2DMock : public Vector2D
{
public:
   // Make the test class a friend for verification of privates
   friend class TestVector;
   
   Vector2DMock()
   {
      horizontalComponent = 0.0;
      verticalComponent = 0.0;
   };
   
   Vector2DMock(double hor, double vert)
   {
      horizontalComponent = hor;
      verticalComponent = vert;
   };
};
