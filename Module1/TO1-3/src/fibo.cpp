#include "fibo.h"
#include <iostream>
using namespace std;
// Constants
const int kValue = 1;
const int kAlreadyComputed = 2;

/**
 * @brief Calculates and returns the nth Fibo number
 * in the series
 * 
 * @return nth fibonacci number 
 */
int GetTenthFibonacci(int nth)
{
	if(nth <= kValue)
	{
		return nth;
	}
    // Local variables.
    // They don't have to be defined at the top of the function!
	int n_1 = 0, n_2 = 1, current;
    // We can access the global variables from inside the function
	for(auto i = kAlreadyComputed; i <= nth; ++i) 
    {
		current = n_1 + n_2;
		n_1 = n_2;
		n_2 = current;
	}
	return n_2;
}