#include <iostream>
using namespace std;
#include "factor.h"

/**
 * @brief Calculate the number of instances divisible
 * by 3 in the range 1 through 30
 * 
 */
void FactorMod3()
{
    unsigned int count = 0;
    for (unsigned int x = 1; x <= 30; ++x)
    {
        int result;
        if (x % 3 == 0)
        {
            count++;
        }
    }

    cout << "Result is: " << count << endl;
    return; // optional return on void functions
}

/**
 * @brief Calculate the number of instances divisible by
 * input parameter in the range 1 through 30
 * 
 * @param mod_number:  the divisible number
 */
void FactorModX(int mod_number)
{
    unsigned int count = 0;
    for (unsigned int x = 1; x <= 30; ++x)
    {
        int result;
        if (x % mod_number == 0)
        {
            count++;
        }
    }

    cout << "Result is: " << count << endl;
}

/**
 * @brief Calculate the number of instances divisible by
 * input parameter in the range 1 through max_range
 * 
 * @param mod_number the divisible number
 * @param max_range the max range
 */
void FactorModXRange(int mod_number, int max_range)
{
    unsigned int count = 0;
    for (unsigned int x = 1; x <= max_range; ++x)
    {
        int result;
        if (x % mod_number == 0)
        {
            count++;
        }
    }

    cout << "Result is: " << count << endl;
}