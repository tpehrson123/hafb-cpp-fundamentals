
#include <iostream>
#include <array>    // array container
using namespace std;

int main()
{

    // To create arrays with library:
    // array <type, numOfElements> name
    array<double, 5> grades {22.1, 6.9, 11.2, 99, 44.3};

    cout << "Size of array: " << grades.size() << endl;
    cout << "Array empty? " << grades.empty() << endl;

    for (int index = 0; index < grades.size(); index++)
    {

        cout << grades[index] << endl;
    }

    // For each loop
    cout << "For each: " << endl;
    for(auto grade : grades){
        cout << grade << endl;
    }
    
    return 0;
}