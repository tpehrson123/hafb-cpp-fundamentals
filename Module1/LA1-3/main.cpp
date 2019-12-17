#include <iostream>
using namespace std;
#include "my_functions.h"

// prototype
int Sum(int num1, int num2);

// Main Function
int main()
{
  int number1 = 5, number2 = 10;
  cout << "The sum of " << number1 << " and " << number2 
      << " is " << Sum(number1, number2) << endl;


  return 0;
}

