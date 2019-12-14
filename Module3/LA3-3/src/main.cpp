#include <iostream>
#include "distance.h"
using namespace std;

// Main Function
int main() 
{
   Distance dist1, dist3, dist4;   //define distances
   dist1.set_distance();                //get dist1 from user

   Distance dist2(11, 6.25);       //define, initialize dist2

   dist3 = dist1 + dist2;          //single '+' operator

   dist4 = dist1 + dist2 + dist3;  //multiple '+' operators
                                   //display all lengths
  //  cout << "dist1 = ";  dist1.showdist(); cout << endl;
  //  cout << "dist2 = ";  dist2.showdist(); cout << endl;
  //  cout << "dist3 = ";  dist3.showdist(); cout << endl;
  //  cout << "dist4 = ";  dist4.showdist(); cout << endl;
  cout << dist1 << endl;
  cout << dist2 << endl;
  cout << dist3 << endl;
  cout << dist4 << endl;
  return 0;
}