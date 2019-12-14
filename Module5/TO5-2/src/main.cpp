#include <iostream>
#include "roman_lib.h"

// Main Function
int main()
{
  numbers::Roman r1;
  for (int i = 1; i <= 100; ++i)
  {
    std::cout << i << "\t" << r1.to_roman(i) << std::endl;
  }

  // int number = 0;
  // std::cout << "number:";
  // std::cin >> number;
  // std::cout << numbers::to_roman(number) << std::endl;
  return 0;
}