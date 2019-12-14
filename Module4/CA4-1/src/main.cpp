#include <array>
#include <iostream>
#include <string>
#include "carton.h"
#include "how_many.h"

using namespace std;

int main() {
  // use integers
  array<int, kMaxSize> counts = {9, 12, 59, 53, 45, 56, 59, 43, 92, 77,
                                 8, 59, 14, 41, 73, 59, 22, 33, 59, 83};
  int count_size = 20;
  int how_many;

  how_many = HowMany(59, counts, count_size);

  cout << "59 is found " << how_many << " times in the array." << endl;

  // use strings
  array<string, kMaxSize> colors = {
      "gray",    "pink", "brown",  "gray",     "green",  "gray",
      "magenta", "gray", "yellow", "gray",     "purple", "gray",
      "gray",    "blue", "orange", "lavender", "black",  "gray"};
  int color_size = 18;
  string color = "gray";

  how_many = HowMany(color, colors, color_size);

  cout << "gray is found " << how_many << " times in the array." << endl;

  // use Cartons
  array<Carton, kMaxSize> presents = {
      Carton(8.1, 7, 15.8),    Carton(7.32, 8, 14.62), Carton(9, 14, 13.8),
      Carton(7.32, 8, 14.62),  Carton(7, 8.3, 12.82),  Carton(7.32, 8, 14.62),
      Carton(15.2, 6.9, 12.7), Carton(7.32, 8, 14.62), Carton(5.9, 6.3, 9.2),
      Carton(8.2, 7.92, 6.58), Carton(7.32, 8, 14.62), Carton(7.32, 8, 14.62)};
  int present_size = 12;
  Carton min_present;
  Carton carton(7.32, 8, 14.62);

  how_many = HowMany(carton, presents, present_size);

  cout << "Carton 7.32 x 8 x 14.62 is found " << how_many
       << " times in the array." << endl;

  return 0;
}