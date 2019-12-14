#include "functions.h"

#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/**
 * @brief
 * Reads data from the file specified in the parameter and stores the values
 * in the parameter arrays.
 *
 * The data file contains
 *
 * @param filename - the name of the file to be read. It is to include the
 *  path, filename, and extension.
 * @param hours  - an array of hours worked during the pay period. Hours will be
 *  added to the array as they are read from the input file. Values for hours
 *  can be 0-168.
 * @param pay_type  - an array of pay types. These are to be an 'h' for hourly
 *  pay or 's' for salary pay.
 * @param pay_rate - an array of pay rates. Pay rates will be
 *  added to the array as they are read from the input file. Must be greater
 *  than the minimum wage of 7.25.
 * @param names - an array of names in last, first format. Names will be
 *  added to the array as they are read from the input file.
 * @param size - the index that identifies the next location to be added
 *  to the array. This index will change as items are added.
 * @return string - that reports any errors that occur during execution or
 *  the empty string if everything is valid and runs
 */
string ReadDataFromFile(string filename, array<double, kMaxSize> &hours,
                        array<char, kMaxSize> &pay_type,
                        array<double, kMaxSize> &pay_rate,
                        array<string, kMaxSize> &names, int &size) {
  // open file for input, test open worked
  ifstream in(filename);

  if (in.fail()) {
    return "Unable to open file";
  }

  string error_message = "";

  while (size < kMaxSize && in >> hours[size]) {
    in >> pay_type[size] >> pay_rate[size];
    in.ignore();
    getline(in, names[size]);

    // validate hours is between 0-168
    if (hours[size] < 0 || hours[size] > 168) {
      hours[size] = 0;
      error_message += "Hours is out of range, set to 0 ";
    }

    // validate pay type is h or s
    if (!(pay_type[size] == 'h' || pay_type[size] == 's')) {
      pay_type[size] = 's';
      error_message += "Incorrect pay type, set to s ";
    }

    // validate pay rate is greater than 7.25
    if (pay_rate[size] < 7.25) {
      pay_rate[size] = 7.25;
      error_message += "Pay is less than minimum wage, set to 7.25 ";
    }

    // validate the name has a comma
    if (names[size].find(",") == string::npos) {
      names[size] = "unknown";
      error_message += "Name is not in last, first format ";
    }

    size++;
  }

  in.close();

  return error_message;
}

/**
 * @brief This function validates the new values, adds them to the array,
 * and increments size
 *
 * @param hours - an array of hours worked during the pay period. Hours will be
 *  added to the array as they are read from the input file.
 * @param pay_type - an array of pay types. These are to be an 'h' for hourly
 *  pay or 's' for salary pay.
 *  added to the array as they are read from the input file.
 * @param pay - an array of pay rates. Pay rates will be
 *  added to the array as they are read from the input file.
 * @param names - an array of names in last, first format. Names will be
 *  added to the array as they are read from the input file.
 * @param new_hours - the new hours worked to be added
 * @param new_pay_type - the pay type to be added
 * @param new_pay_rate - the new pay rate to be added
 * @param new_name - the new name to be added
 * @param size - the index that identifies the next location to be added
 *  to the array. This index will change as items are added.
 * @return string that reports any errors that occur during execution or
 *  the empty string if everything is valid and runs
 */
string AddPayrollData(array<double, kMaxSize> &hours,
                      array<char, kMaxSize> &pay_type,
                      array<double, kMaxSize> &pay_rate,
                      array<string, kMaxSize> &names, double new_hours,
                      char new_pay_type, double new_pay_rate, string new_name,
                      int &size) {
  if (size >= kMaxSize) {
    return "Arrays are full, no payroll data added";
  }

  string error_message = "";

  // validate hours is between 0-168
  if (new_hours < 0 || new_hours > 168) {
    new_hours = 0;
    error_message += "Hours is out of range, set to 0 ";
  }

  // validate pay type is h or s
  if (!(new_pay_type == 'h' || new_pay_type == 's')) {
    new_pay_type = 's';
    error_message += "Incorrect pay type, set to s ";
  }

  // validate pay rate is greater than 7.25
  if (new_pay_rate < 7.25) {
    new_pay_rate = 7.25;
    error_message += "Pay is less than minimum wage, set to 7.25 ";
  }

  // validate the name has a comma
  if (new_name.find(",") == string::npos) {
    new_name = "unknown";
    error_message += "Name is not in last, first format ";
  }

  // add new values to arrays
  hours[size] = new_hours;
  pay_type[size] = new_pay_type;
  pay_rate[size] = new_pay_rate;
  names[size] = new_name;

  size++;

  return error_message;
}

/**
 * @brief This function computes gross pay
 *
 * @param hours - hours worked this pay period
 * @param pay_type - either h for hourly or s for salary
 * @param pay_rate - current pay rate
 * @return double - the computed gross pay
 */
double ComputeGross(double hours, char pay_type, double pay_rate) {
  double gross_pay;
  const double kRegularHours = 40;
  const double kOvertimeRate = 1.5;

  switch (pay_type) {
    case 's':
      gross_pay = pay_rate;
      break;
    case 'h':
      if (hours <= kRegularHours) {
        gross_pay = hours * pay_rate;
      } else {
        gross_pay = kRegularHours * pay_rate;
        gross_pay += (hours - kRegularHours) * pay_rate * kOvertimeRate;
      }
      break;
    default:
      gross_pay = 0;
      break;
  }

  return gross_pay;
}

/**
 * @brief This function writes a report to a file. The report includes an
 * entry for each set of payroll data in the files.
 *
 * - The first line contains a name in first last format
 * - The second line contains four items separated by a space
 * - hours worked
 * - pay type
 * - pay rate
 * - gross pay
 *
 * @param filename - the name of the file to write to. It is to include the
 *  path, filename, and extension.
 * @param hours  - an array of hours worked during the pay period. Hours will be
 *  added to the array as they are read from the input file. Values for hours
 *  can be 0-168.
 * @param pay_type  - an array of pay types. These are to be an 'h' for hourly
 *  pay or 's' for salary pay.
 * @param pay_rate - an array of pay rates. Pay rates will be
 *  added to the array as they are read from the input file. Must be greater
 *  than the minimum wage of 7.25.
 * @param names - an array of names in last, first format. Names will be
 *  added to the array as they are read from the input file.
 * @param size - the index that identifies the next location to be added
 *  to the array. This index will change as items are added.
 */
void WritePayrollReportToFile(std::string filename,
                              const std::array<double, kMaxSize> &hours,
                              const std::array<char, kMaxSize> &pay_type,
                              const std::array<double, kMaxSize> &pay_rate,
                              const std::array<std::string, kMaxSize> &names,
                              int &size) {
  ofstream outfile(filename);

  double gross;

  for (int i = 0; i < size; i++) {
    // separate first and last
    int comma_position = names[i].find(",");
    int last_start = 0;
    int last_length = comma_position;
    int first_start = comma_position + 2;
    int first_length = names[i].length() - first_start;
    string last = names[i].substr(last_start, last_length);
    string first = names[i].substr(first_start, first_length);

    outfile << first << " " << last << endl;

    gross = ComputeGross(hours[i], pay_type[i], pay_rate[i]);

    outfile << setprecision(2) << fixed;
    outfile << hours[i] << " " << pay_type[i] << " " << pay_rate[i] << " "
            << gross << endl;
  }

  outfile.close();
}

/**
 * @brief This function writes payroll to a file. The report includes an
 * entry for each set of payroll data in the files.
 *
 * - The first line contains three items separated by a space
 * - hours worked
 * - pay type
 * - pay rate 
 * - The second line contains a name in last, first format
 *
 * @param filename - the name of the file to write to. It is to include the
 *  path, filename, and extension.
 * @param hours  - an array of hours worked during the pay period. Hours will be
 *  added to the array as they are read from the input file. Values for hours
 *  can be 0-168.
 * @param pay_type  - an array of pay types. These are to be an 'h' for hourly
 *  pay or 's' for salary pay.
 * @param pay_rate - an array of pay rates. Pay rates will be
 *  added to the array as they are read from the input file. Must be greater
 *  than the minimum wage of 7.25.
 * @param names - an array of names in last, first format. Names will be
 *  added to the array as they are read from the input file.
 * @param size - the index that identifies the next location to be added
 *  to the array. This index will change as items are added.
 */
void WritePayrollDataToFile(std::string filename,
                            const std::array<double, kMaxSize> &hours,
                            const std::array<char, kMaxSize> &pay_type,
                            const std::array<double, kMaxSize> &pay_rate,
                            const std::array<std::string, kMaxSize> &names,
                            int &size) {
  ofstream out(filename);

  for (int i = 0; i < size; i++) {
    out << hours[i] << " " << pay_type[i] << " " << pay_rate[i] << endl
        << names[i] << endl;
  }

  out.close();
}