#include <iostream>
#include "distance.h"

// Main Function
int main()
{
  Distance d1(34, 9.5);
  std::cout << "d1:  ";
  d1.ShowDist();

  Distance d2(10, 8.5);
  std::cout << "d2:   ";
  d2.ShowDist();

  Distance d3;

  // This is what we want to do (overload the + for distance objects)
  d3 = d1 + d2;
  std::cout << "d3:  ";
  d3.ShowDist();

  Distance d4;
  d4 = d1 + d2 + d3;
  std::cout << "d4:  ";
  d4.ShowDist();

  // Now make the << work on distance objects
  std::cout << d4 << std::endl;

  // Now make - operator work
  Distance d5;
  d5 = d4 - d3;
  std::cout << "d5:  ";
  d5.ShowDist();

  // Create a update_distance function
  d5.update_distance(33, 2.3);
  std::cout << "d5:  ";
  d5.ShowDist();

  return 0;
}