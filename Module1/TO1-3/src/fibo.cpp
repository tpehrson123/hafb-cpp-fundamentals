#include "fibo.h"
#include <iostream>
using namespace std;
// Constants
const int kPosition = 10;
const int kAlreadyComputed = 3;

/**
 * @brief Calculates and returns the 10th Fibo number
 * in the series
 * 
 * @return 10th fibonacci number 
 */
unsigned int GetTenthFibonacci()
{
    // Local variables.
    // They don't have to be defined at the top of the function!
	unsigned int n_1 = 1;
	unsigned int n_2 = 0;
	unsigned int current = n_1 + n_2;
    // We can access the global variables from inside the function
	for(auto i = 0; i <= kPosition; ++i) 
    {
		current = n_1 + n_2;
		n_2 = n_1;
		n_1 = current;
	}
	return current;
}