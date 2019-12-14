#include <iostream>

// Main Function
int main()
{
  // Lambda syntax
  // [captured variables] (arguments){ body }
  auto sum_numbers = [](int a, int b) { return a + b;};
  std::cout << sum_numbers(10, 20) << std::endl;
  
  int addend = 1;
  auto sum_numbers2 = [addend](int b) { return addend + b;};
  addend = 2; // does not affect the lambda call, (caputere by value)
  std::cout << sum_numbers2(10) << std::endl;
  
  int multiplier = 2;
  auto multiply_numbers = [&multiplier](int b){ return multiplier * b;};
  multiplier = 4;  // will affect the value in the lambda
  std::cout << multiply_numbers(3) << std::endl;


  

  return 0;
}