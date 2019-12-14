#include <iostream>
#include <string>
#include "carton.h"
#include "min.h"

using namespace std;

int main() {
  // use integers
  int count1 = 25;
  int count2 = 382;
  int min_count;

  min_count = MyMin(count1, count2);

  cout << "The minimum count is " << min_count << endl;

  // use doubles
  double volume1 = 172.35;
  double volume2 = 68.23;
  double min_volume;

  min_volume = MyMin(volume1, volume2);

  cout << "The minimum volume is " << min_volume << endl;

  // use Cartons
  Carton present1(14, 11.8, 20);
  Carton present2(7, 13, 14.2);
  Carton min_present;

  min_present = MyMin(present1, present2);

  cout << "The minimum present is ";
  min_present.WriteData(cout);

  return 0;
}