#include <iostream>
using namespace std;
#include "factor.h"

int main()
{
    FactorMod3(); // call function

    FactorModX(5); // call function

    FactorModXRange(5, 100); // call function

    auto count2 = GetFactorModXRange(5, 500); // call function  
    cout << "GetFactorModXRange: " << count2 << endl;

    return 0;
}
