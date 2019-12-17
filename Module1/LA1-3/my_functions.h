/*
** EPITECH PROJECT, 2019
** hafb-cpp-fundamentals
** File description:
** my_functions
*/

#ifndef MY_FUNCTIONS_H_
#define MY_FUNCTIONS_H_

#include <array>    // array container

// prototype
int Sum(int num1, int num2);

void UpdateStep(int& step);

int Max2(int num1, int num2);
int Max3(int num1, int num2, int num3);
int Max10(const std::array<int, 10>& nums);
void ClearElements(std::array<int, 10>& nums);

#endif /* !MY_FUNCTIONS_H_ */
