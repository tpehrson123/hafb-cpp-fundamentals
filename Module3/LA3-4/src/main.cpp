#include <iostream>
#include "distance.h"
using namespace std;

// Main Function
int main() 
{
   Distance dist1(7, 5);       //define, initialize dist2
   Distance dist2(2, 9);       //define, initialize dist2
   cout << "dist1 = " << dist1 << endl;
   cout << "dist2 = " << dist2 << endl;
   Distance::showtotal();
   Distance dist3 = dist1 - dist2;
   cout << "dist3 = " << dist3 << endl;
   Distance::showtotal();

   dist3 = dist1;  // invokes the overload operator
   cout << "dist3 = " << dist3 << endl;
  //  Distance dist4 = dist1; // does not invoke the assignment operator
   Distance dist4(dist1); // does not invoke the assignment operator
   cout << "dist4 = " << dist4 << endl;


  return 0;
}