// countpp3.cpp
// increment counter variable with ++ operator
// uses unnamed temporary object
#include <iostream>
using namespace std;
#include "distance.h"

 void Distance::set_distance()              //get length from user
{
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
}

void Distance::showdist() const       //display distance
{ 
   cout << feet << "\'-" << inches << '\"'; 
}


Distance Distance::operator + (Distance d2) const  //return sum
{
   int f = feet + d2.feet;        //add the feet
   float i = inches + d2.inches;  //add the inches
   if(i >= 12.0)                  //if total exceeds 12.0,
   {                           //then decrease inches
      i -= 12.0;                  //by 12.0 and
      f++;                        //increase feet by 1
   }                           //return a temporary Distance
   return Distance(f,i);          //initialized to sum
}

std::ostream &operator<<(std::ostream &os, const Distance &distance)
{
    os << "feet_: " << distance.feet << " inches_: " << distance.inches;
    return os;
}