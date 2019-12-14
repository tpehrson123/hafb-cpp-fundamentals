#include <iostream>
using namespace std;
#include "factor.h"

// Main Function
int main()
{
  unsigned int reps = FactorMod7();
  cout << "The FactorMod7() function found: " << reps << endl;

  return 0;
}