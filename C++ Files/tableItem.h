/*************************************************************
 * Header File:
 *    A struct to represent a table item.
 * Author:
 *    Emilio Regino
 * Summary:
 *    Used to hold the key and corresponding value in
 *    the gravity. drag, mach, air density tables.
 *    Represented as key and value
 **************************************************************/

#pragma once

/*************************************************************
 * TABLE ITEM
 * The table item struct
 **************************************************************/
struct tableItem
{
   tableItem(){};
   tableItem(double a, double b)
   {
      key = a;
      value = b;
   }
   
   double key;
   double value;
};
