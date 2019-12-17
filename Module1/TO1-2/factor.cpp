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