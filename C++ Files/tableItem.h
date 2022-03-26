#pragma once

class tableItem
{
public:
   tableItem() {};
   tableItem(double a, double b)
   {
      key = a;
      value = b;
   }
   double key;
   double value;
};