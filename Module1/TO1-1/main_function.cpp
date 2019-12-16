#include <iostream>
using namespace std;

// Function Prototype
void FactorMod3();

int main()
{

    FactorMod3(); // call function

    return 0;
}

// Function Definition
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