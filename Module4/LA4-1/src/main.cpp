#include <iostream>
#include <string>
#include "carton.h"
#include "swap.h"

using namespace std;

int main() {
  // use the MySwap function with integers
  int int1 = 95;
  int int2 = 78;

  cout << "Before, \nInteger 1: " << int1 << endl
       << "Integer 2: " << int2 << endl;
  MySwap(int1, int2);

  cout << "After, \nInteger 1: " << int1 << endl
       << "Integer 2: " << int2 << endl;

  // use the MySwap function with doubles
  double double1 = 43.8;
  double double2 = 97.32;

  cout << "Before, \nDouble 1: " << double1 << endl
       << "Double 2: " << double2 << endl;
  MySwap(double1, double2);
  cout << "Before, \nDouble 1: " << double1 << endl
       << "Double 2: " << double2 << endl;

  // use the MySwap function with Cartons
  Carton present1(14, 13, 7.8);
  Carton present2(9.4, 11.2, 18);

  cout << "Before, \npresent 1: ";
  present1.WriteCarton(cout);
  cout << endl << "After, \npresent 2: ";
  present2.WriteCarton(cout);
  cout << endl;

  MySwap(present1, present2);

  cout << "Before, \npresent 1: ";
  present1.WriteCarton(cout);
  cout << endl << "After, \npresent 2: ";
  present2.WriteCarton(cout);
  cout << endl;

  return 0;
}