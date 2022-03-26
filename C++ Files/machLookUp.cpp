
#include "tableItem.h"
#include "machLookUp.h"
#include <iostream>
using namespace std;

// A method to get the gravity from a given altitude
double MachLookUp :: getMach(double altitude) const
{
   // Iterate through the table
   for (int i=0; i < 14; i++)
   {
      tableItem item = table[i];
      // Check for the matching key
      if (item.key == altitude)
         return item.value;
   }
   
   // If not found then search the table for the value just before
   // and the value just after where it would be in the table
   tableItem key1Key2 = searchTable(altitude);
   double x1 = key1Key2.key;
   double y1 = 0.0;
   double x2 = key1Key2.value;
   double y2 = 0.0;
   
   for (int i=0; i < 14; i++)
   {
      tableItem item = table[i];
      // Check for the matching key
      if (item.key == x1)
         y1 = table[i].value;
      else if (item.key == x2)
         y2 = table[i].value;
   }
   
   double value = interpolate(x1, y1, x2, y2, altitude);
   
   return value;
}

// A method to search the table for a key not found
tableItem MachLookUp :: searchTable(double keyNotFound) const
{
   // assign the high and low values
   double high = table[0].key;
   double low = table[0].key;
   
   // Loop through the array
   int i = 0;
   bool searching = true;
   while (i < 14 && searching)
   {
      // If current key is less than not contained key
      if (table[i].key < keyNotFound)
      {
         // check if is greater than the current low
         if (table[i].key > low)
         {
            // If so assign the new low
            low = table[i].key;
         }
      }
      else
      {
         // Our previous iterator was the highest value below the one we want.
         // The current iterator is the lowest value above the one we want.
         // That means we're done searching.
         high = table[i].key;
         searching = false;
      }
      i++;
   }
   return tableItem(low, high);
}


// A method to interpolate
// we should clarify which value is which is it value 1x and y and or value x 1 and 2
double MachLookUp :: interpolate(double x0,  double y0, double x1, double y1, double toFind) const
{
   if (y1 == y0)
   {
      // They gave us one point twice, or a constant function.
      return y1;
   }
   else
   {
      return (y1 - y0) * (toFind - x0) / (x1 - x0) + y0;
   }
}

bool MachLookUp :: closeEnough(double computedValue, double hardcodeValue) const
{
   string stringC = to_string(computedValue);
   string stringH = to_string(hardcodeValue);
   for (int i = 0; i < 6; i++)
   {
      if (stringC[i] != stringH[i])
         return false;
   }
   return true;
}
