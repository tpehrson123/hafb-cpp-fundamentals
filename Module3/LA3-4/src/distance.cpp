// countpp3.cpp
// increment counter variable with ++ operator
// uses unnamed temporary object
#include <iostream>
using namespace std;
#include "distance.h"

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
    os << distance.feet_ << "\'-" << distance.inches_ << '\"'; 
    return os;
}
      
bool Distance::operator < (Distance d2) const  // compare distances
{
   float ft1 = feet_ + inches_/12;
   float ft2 = d2.feet_ + d2.inches_/12;

   // if(ft1 < ft2)
   // {
   //    return true;
   // }
   // else
   // {
   //    return false;
   // }
   return (ft1 < ft2) ? true : false;
}

bool Distance::operator == (Distance d2) const  // compare distances
{
   float ft1 = feet_ + inches_/12;
   float ft2 = d2.feet_ + d2.inches_/12;

   return (ft1 == ft2) ? true : false;
}

/**
 * @brief Friend function takes two parameters instead of one
 * 
 * @param d1 
 * @param d2 
 * @return Distance 
 */
Distance operator - ( Distance d1, Distance d2)
{
   int ft = d1.feet_ - d2.feet_;
   float in = 0;
   
   if(d1.inches_ < d2.inches_)
   {
      in = 12.0;  // add one foot 
      ft--; // substract one foot
   }
   in = (d1.inches_  + in ) - d2.inches_;

   return Distance(ft, in);
}

// Initialize static member
int Distance::total_points = 0; 

void Distance::showtotal() 
{
   cout << "Total points: " << total_points << endl;
}

Distance Distance::operator = (Distance& d2)
{
   cout<<"Assignment operator invoked"<<endl;
   feet_ = d2.feet_; // not done automatically
   inches_ = d2.inches_;
   return Distance(feet_, inches_);

}