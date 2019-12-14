#include <array>
#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

/**
 * @brief This program uses arrays and functions to read from a payroll data
 * file and produces the payroll information needed.
 *
 * @return int
 */
int main() {
  // define arrays to hold data
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay_rate;
  array<string, kMaxSize> names;

  // read data from file
  string filename = "../payroll_data.txt";
  int size = 0;
  string message;

  message = ReadDataFromFile(filename, hours, pay_type, pay_rate, names, size);

  cout << "Message " << message << endl;

  // print out message, size, and data in arrays
  cout << "Size: " << size << endl;

  for (int i = 0; i < size; i++) {
    cout << hours[i] << " " << pay_type[i] << " " << pay_rate[i] << " "
         << names[i] << endl;
  }

  // Add two sets of payroll information
  message = AddPayrollData(hours, pay_type, pay_rate, names, 45, 'h', 17.85,
                           "Jones, Kim", size);

  // print out read message, size, and data in arrays
  cout << "After AddPayrollData:\n"
       << "Message " << message << endl;
  cout << "Size: " << size << endl;

  for (int i = 0; i < size; i++) {
    cout << hours[i] << " " << pay_type[i] << " " << pay_rate[i] << " "
         << names[i] << endl;
  }
  // print out gross pay tests
  cout << "ComputeGross(45, 's', 2135.5): " << ComputeGross(45, 's', 2135.5)
       << endl;
  cout << "ComputeGross(12, 's', 2516): " << ComputeGross(12, 's', 2516)
       << endl;
  cout << "ComputeGross(12, 'h', 25.80): " << ComputeGross(12, 'h', 25.80)
       << endl;
  cout << "ComputeGross(0, 'h', 18.50): " << ComputeGross(0, 'h', 18.50)
       << endl;
  cout << "ComputeGross(40, 'h', 23.75): " << ComputeGross(40, 'h', 23.75)
       << endl;
  cout << "ComputeGross(42, 'h', 23.75): " << ComputeGross(42, 'h', 23.75)
       << endl;
  cout << "ComputeGross(63, 'h', 18.50): " << ComputeGross(63, 'h', 18.50)
       << endl;

  // write payroll report to a file
  WritePayrollReportToFile("../reports.txt", hours, pay_type, pay_rate, names,
                           size);

  // write payroll data to a file
  WritePayrollDataToFile("../data_out.txt", hours, pay_type, pay_rate, names,
                         size);

  return 0;
}
