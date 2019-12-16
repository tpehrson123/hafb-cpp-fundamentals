#include <iostream>
using namespace std;

int main()
{


    // Calculate BMI: weight(kg)/[height(m)]^2
    // Floating point variables: float, double
    float weight = 0, height = 0, bmi = 0;

    cout << "Enter weight in kg: " << endl;
    cin >> weight;

    float pounds = weight * 2.2046;

    cout << "Enter height in meters: " << endl;
    cin >> height;

    float height_ft = height * 0.3048;

    bmi = weight/(height * height);
    cout << "Your BMI is " << bmi << endl;

    return 0;

}