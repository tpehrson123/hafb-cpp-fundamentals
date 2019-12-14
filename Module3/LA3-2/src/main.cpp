#include <iostream>
#include "counter.h"
using namespace std;

// Main Function
int main() 
{
  Counter c1, c2;                       //c1=0, c2=0

   cout << "\nc1=" << c1.get_count();    //display
   cout << "\nc2=" << c2.get_count();

   ++c1;                                 //c1=1
   c2 = ++c1;                            //c1=2, c2=2 (prefix)

   cout << "\nc1=" << c1.get_count();    //display
   cout << "\nc2=" << c2.get_count();

   c2 = c1++;                            //c1=3, c2=2 (postfix)

   cout << "\nc1=" << c1.get_count();    //display again
   cout << "\nc2=" << c2.get_count() << endl;

}