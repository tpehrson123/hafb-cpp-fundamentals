#include <iostream>
#include "age.h"
using namespace std;

// Main function
int main()
{

	int age = 15;
	cout << "Current age: " << age << endl;
	//ByValueAgeIn5Years(age);
	ByReferenceAgeIn5Years(age);
	cout << "In 5 years, your age is: " << CurrentAge(age) << endl;
	if (age >= 18)
	{
		cout << "Congratulations, you can vote! " << endl;
	}

	// // ByValueAgeIn5Years(age);
	// ByReferenceAgeIn5Years(age);
	// cout << "In 5 years, your age is: " << CurrentAge(age) << endl;
	// if (age >= 18)
	// {
	//     cout << "Congratulations, you can vote! " << endl;
	// }
}