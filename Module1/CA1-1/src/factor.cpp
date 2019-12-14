/**
 * @file factor.cpp
 * @author waldo (waldo@weber.com)
 * @brief Implementation file for the factor library
 * @version 0.1
 * @date 2019-07-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
using namespace std;
#include "factor.h"
// TODO: Clear all this code before assigning to students 

/**
 * @brief This function prints and returns the number of times
 * a number is divisible by 7 between 1 and 100.
 * 
 * @return number of times number is divisible by 7 
 */
int FactorMod7()
{
    unsigned int num = 0;
    unsigned i = 1;
    while (i <= 100)
    {
        if (i % 7 == 0)
        {
            cout << i << endl;
            num++;
        }
        i++;
    }
    return num;
}