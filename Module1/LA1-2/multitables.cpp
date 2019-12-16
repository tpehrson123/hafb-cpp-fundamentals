#include <iostream>
#include <cmath>  // for sqrt() function
#include <iomanip>  // for formatted output

using namespace std;

const int kMax = 10;

int main()
{
    int number;
    cout << "Enter a value to print multiplication tables: " << endl;
    cin >> number;

    for (int num1 = 1; num1 <= number; ++num1)
    {

        for (int num2 = 1; num2 <= kMax; ++num2)
        {
            cout << setw(3) << num1*num2 << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}