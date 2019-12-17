#include <iostream>
using namespace std;
#include "my_functions.h"

// prototype
int Sum(int num1, int num2);

// Main Function
int main()
{
  int number1 = 5, number2 = 10;
  // cout << "The sum of " << number1 << " and " << number2
  //     << " is " << Sum(number1, number2) << endl;

  // cout << "Number before UpdateStep() " << number1 << endl;
  // UpdateStep(number1);
  // UpdateStep(number1);
  // UpdateStep(number1);

  // cout << "Number after UpdateStep() " << number1 << endl;

  cout << "Max number is: " << Max2(number1, number2) << endl;

  cout << "Max of three numbers is: " << Max3(number1, number2, 2) << endl;

  array<int, 10> grades{22, 6, 11, 99, 44, 22, 33, 44, 55, 66};

  cout << "Max of number in array grades " <<  "is: " << Max10(grades) << endl;

  ClearElements(grades);

  for (auto grade : grades)
  {
    cout << grade << endl;
  }
  return 0;
}
