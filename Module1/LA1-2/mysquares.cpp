

#include <iostream>
#include <cmath>  // for sqrt() function
#include <iomanip>  // for formatted output

using namespace std;

const int kMaxCount = 5;

int main()
{

    cout << "NUMBER    SQUARE ROOT" << endl;
    cout << "------    -----------" << endl;

    cout << setiosflags(ios::showpoint);

    for (int count = 1; count < kMaxCount; ++count)
    {
        cout << setw(4) << count << setw(15) << sqrt(count) << endl;
    }
    
    cout << "Done" << endl;

    return 0;
}
