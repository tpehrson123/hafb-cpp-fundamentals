#include <iostream>
using namespace std;

int global_variable = 1000;

int main()
{
    int global_variable = 2000;
    // :: scope operator
    cout << "Global " << ::global_variable << endl;
    cout << "Local " << global_variable << endl;
    return 0;
}

