#include <array>
#include <iostream>
#include "carton.h"
#include "max_array.h"

using namespace std;

int main() {
  // use integers
  array<int, kMaxSize> counts = {45, 63, 17, 22, 71, 54, 87, 23,
                                 51, 3,  19, 13, 5,  7,  99};
  int count_size = 15;
  int max_count;

  max_count = MaxInArray(counts, count_size);

  cout << "The maximum count is " << max_count << endl;

  // use doubles
  array<double, kMaxSize> volumes = {71.3,   129.5,  139.7, 382.2,  91.93,
                                     66.724, 88.382, 42.89, 276.54, 301.47,
                                     218.56, 274.87, 382.2};
  int volume_size = 12;
  double max_volume;

  max_volume = MaxInArray(volumes, volume_size);

  cout << "The maximum volume is " << max_volume << endl;

  // use Cartons
  array<Carton, kMaxSize> presents = {Carton(7, 24, 13),    Carton(6, 8, 14),
                                      Carton(16, 12.8, 13), Carton(15, 8, 12),
                                      Carton(9, 13, 21),    Carton(12, 14, 22)};
  int present_size = 6;
  Carton max_present;

  max_present = MaxInArray(presents, present_size);

  cout << "The maximum present is ";
  max_present.WriteCarton(cout);

  return 0;
}