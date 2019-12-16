
#include <iostream>
using namespace std;

int main()
{
    char code;
    cout << "Enter the specification code: ";
    cin >> code;

    // if (code == 'S')
    // {
    //     cout << "The item is space exploration grade." << endl;
    // }

    // Use a switch statement
    switch (code)
    {
    case 'S':
    case 's':
        cout << "The item is space exploration grade." << endl;
        break;
    case 'M':
        cout << "The item is military grade." << endl;
        break;
    case 'C':
        cout << "The item is commercial grade." << endl;
        break;
    default:
        cout << "The item is not supported." << endl;
        break;  
    }

    return 0;
}