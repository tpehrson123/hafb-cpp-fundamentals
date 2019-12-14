// countpp3.cpp
// increment counter variable with ++ operator
// uses unnamed temporary object
#include <iostream>
using namespace std;
#include "counter.h"
////////////////////////////////////////////////////////////////
int Counter::get_count()            //return count
{ 
   return count; 
}
 
 
Counter Counter::operator ++ ()     //increment count
{
   return Counter(++count);	//  an unnamed temporary object
}                       //  initialized to this count

Counter Counter::operator ++ (int)     //increment count
{
   return Counter(count++);	//  an unnamed temporary object
}                       //  initialized to this count