#include <iostream>
#include "fibo.h"
using namespace std;

// Main Function
int main()
{
  int number = 10;
  cout << "Computing the " << number << " Fibonacci number: " 
    << GetTenthFibonacci(number) << endl;
  return 0;
}