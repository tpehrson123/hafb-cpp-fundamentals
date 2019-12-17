#include <iostream>
using namespace std;
#include "my_functions.h"
#include <array> // array container

/**
 * @brief Calculate the sum of two numbers
 * 
 * @param num1 
 * @param num2 
 * @return int  Sum of num1 and num2
 */
int Sum(int num1, int num2) // pass both parameters by value (make your own copy)
{
  return num1 + num2;
}

/**
 * @brief Increments the value of step by 1
 * 
 * @param step 
 */
void UpdateStep(int &step) // take the address of the parameter
{
  cout << "Current step: " << step << endl;
  step++;
  cout << "New step: " << step << endl;
}

int Max2(int num1, int num2)
{
  if (num2 > num1)
  {
    return num2;
  }
  else
  {
    return num1;
  }
}

int Max3(int num1, int num2, int num3)
{
  if (num1 >= num2 && num1 >= num3)
    return num1;

  if (num2 >= num1 && num2 >= num3)
    return num2;

  if (num3 >= num1 && num3 >= num2)
    return num3;
}

int Max10(const std::array<int, 10>& nums)
{
  int max = nums[0];
  for (auto num : nums)
  {
    if (max <= num)
    {
      max = num;
    }
  }
  return max;
}

void ClearElements(std::array<int, 10>& nums)
{
  for (int index = 0; index < nums.size(); ++index)
  {
    nums[index] = -99;
  }
}