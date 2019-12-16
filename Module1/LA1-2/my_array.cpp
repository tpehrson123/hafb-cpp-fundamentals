#include <iostream>
#include <cmath>   // for sqrt() function
#include <iomanip> // for formatted output

using namespace std;

const int kMaxMum = 5;
int main()
{

    float average = 0;
    int sum = 0;

    // C-Style arrays
    // Array notation: type name [elements];
    int grades[kMaxMum] = {10, 20, 30, 10, 50}; // an array of 5 integers

//    int grades[] = {10, 20, 30, 10, 50}; // an array of 5 integers - compiler decides size

    cout << "Enter your exam grades" << endl;

    for (int num = 0; num < kMaxMum; ++num)
    {
        // cout << "Enter " << num + 1 << " grade: " << endl;
        // cin >> grades[num];

        average += grades[num];
        sum += grades[num];
    }

    average = average / kMaxMum;

    cout << "Average grade: " << average << endl;

    average = static_cast<float>(sum) / kMaxMum;

    cout << "Average grade: " << average << endl;

    const int kmaxRow = 3;
    const int kmaxColumn = 5;

    // 2D Arrays: type name[row][column]
    int bi_array[kmaxRow][kmaxColumn] = {
        {2, 4, 6, 11, 67},
        {4, 5, 22, 33, 99},
        {89, 33,22, 11,0}
    };


    for (int row = 0; row < kmaxRow; row++)
    {
        for (int column = 0; column < kmaxColumn; column++)
        {
            cout << "Array element at [" << row << "]"
             << "[" << column << "]" << " = " << bi_array[row][column] << endl;
        }

    }
    

    return 0;
}