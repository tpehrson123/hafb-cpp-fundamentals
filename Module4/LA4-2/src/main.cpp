#include <iostream>
#include <string>
#include "carton.h"
#include "max.h"

using namespace std;

int main() {
  // use the MyMax function with integers
  int count1 = 25;
  int count2 = 73;
  int max_count;

  max_count = MyMax(count1, count2);

  cout << "The maximum count is " << max_count << endl;

  // use the MyMax function with doubles
  double volume1 = 134.62;
  double volume2 = 112.87;
  double max_volume;

  max_volume = MyMax(volume1, volume2);

  cout << "The maximum volume is " << max_volume << endl;

  // use the MyMax function with Cartons
  Carton present1(14, 11.8, 20);
  Carton present2(7.8, 12.3, 18);
  Carton max_present;

  max_present = MyMax(present1, present2);

  cout << "The maximum present is ";
  max_present.WriteCarton(cout);

  return 0;
}