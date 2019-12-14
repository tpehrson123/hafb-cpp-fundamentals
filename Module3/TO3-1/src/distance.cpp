// countpp3.cpp
// increment counter variable with ++ operator
// uses unnamed temporary object
#include <iostream>
#include <cmath> 
using namespace std;
#include "distance.h"

int Distance::feet() const
{
   return feet_;
}

float Distance::inches() const
{
   return inches_;
}
void Distance::set_distance()              //get length from user
{
         cout << "\nEnter feet: ";  cin >> feet_;
         cout << "Enter inches: ";  cin >> inches_;
}

void Distance::showdist() const       //display distance
{ 
   cout << feet_ << "\'-" << inches_ << '\"'; 
}


Distance Distance::operator + (Distance d2) const  //return sum
{
   int f = feet_ + d2.feet_;        //add the feet
   float i = inches_ + d2.inches_;  //add the inches
   if(i >= 12.0)                  //if total exceeds 12.0,
   {                           //then decrease inches
      i -= 12.0;                  //by 12.0 and
      f++;                        //increase feet by 1
   }                           //return a temporary Distance
   return Distance(f,i);          //initialized to sum
}

std::ostream &operator<<(std::ostream &os, const Distance &distance)
{
    os << "feet_: " << distance.feet_ << " inches_: " << distance.inches_;
    return os;
}


void Distance::update_distance(int ft, float in)
{
   feet_ = ft;
   inches_ = in;
}          

Distance Distance::operator - (Distance d2) const //return sum
{
   int ft = feet_ - d2.feet_;        //add the feet
   float in = 0;
   if(inches_ < d2.inches_)  //add the inches
   {                           //then decrease inches
      ft -= 1;                        //increase feet by 1
      in = (inches_ + 12) - d2.inches_;  //add the inches
   }                           //return a temporary Distance
   return Distance(ft, in);          //initialized to sum
}