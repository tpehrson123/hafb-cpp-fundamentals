#include "payroll_data.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const double PayrollData::kRegularHours = 40;
const double PayrollData::kOvertimeRate = 1.5;
// PayrollData::PayrollData() {
//   set_hours(0);
//   set_pay_type('h');
//   set_pay_rate(7.25);
//   set_name("unknown, it is");
// }

/**
 * @brief Construct a new Payroll Data:: Payroll Data object
 *
 * @param hours - hours worked (between 1-168)
 * @param pay_type - h for hourly or s for salary
 * @param pay_rate - pay rate, hourly pay rate or pay period salary
 * @param name - employee name in first last format or last, first format
 * @throw out_of_range exception when hours is outside of allowed range, pay
 * type is other than h or s, or pay rate is less than 7.25
 */
PayrollData::PayrollData(double hours, char pay_type, double pay_rate,
                         std::string name) {
  try {
    set_hours(hours);
    set_pay_type(pay_type);
    set_pay_rate(pay_rate);
    set_name(name);
  } catch (out_of_range e) {
    throw;
  }
}
/**
 * @brief Sets the hours worked to value sent. Requires hours is between
 * 0-168, including 0 and 168.
 *
 * @param hours - the number of hours worked this pay period
 * @throw out_of_range exception when hours is an invalid value
 */
void PayrollData::set_hours(double hours) {
  if (hours < 0 || hours > 168) {
    throw out_of_range("Hours is out of range");
  }
  hours_ = hours;
}
/**
 * @brief Sets pay type to h for hourly or s for salary
 *
 * @param pay_type - either h or s for pay type
 * @throw out_of_range exception when pay type is anything other than h or s
 */
void PayrollData::set_pay_type(char pay_type) {
  if (pay_type == 'h' || pay_type == 's') {
    pay_type_ = pay_type;
  } else {
    throw out_of_range("Pay type is incorrect");
  }
}
/**
 * @brief Sets pay rate. Pay rate must be 7.25 or greater
 *
 * @param pay_rate - the pay rate for the employee, either hourly rate or
 * salary amount
 * @throw out_of_range exception when pay type is less than 7.25
 */
void PayrollData::set_pay_rate(double pay_rate) {
  if (pay_rate < 7.25) {
    throw out_of_range("Pay is less than minimum wage");
  }
  pay_rate_ = pay_rate;
}
/**
 * @brief Sets the first and last name of the employee
 *
 * @param name - The first and last name of employee in either first last
 * format or last, first format
 */
void PayrollData::set_name(std::string name) {
  int first_start;
  int last_start;
  int first_length;
  int last_length;
  int separator_position;
  if (name.find(",") == string::npos) {
    separator_position = name.find(" ");
    first_start = 0;
    first_length = separator_position;
    last_start = separator_position + 1;
    last_length = name.length() - last_start;
  } else {
    separator_position = name.find(",");
    last_start = 0;
    last_length = separator_position;
    first_start = separator_position + 2;
    first_length = name.length() - first_start;
  }

  first_name_ = name.substr(first_start, first_length);
  last_name_ = name.substr(last_start, last_length);
}

/**
 * @brief Computes gross pay for pay period
 *
 * @return double - computed gross pay
 */
double PayrollData::ComputeGross() const {
  double gross_pay;

  if (pay_type_ == 's') {
    gross_pay = pay_rate_;
  } else {
    if (hours_ <= kRegularHours) {
      gross_pay = hours_ * pay_rate_;
    } else {
      gross_pay = kRegularHours * pay_rate_;
      gross_pay += (hours_ - kRegularHours) * pay_rate_ * kOvertimeRate;
    }
  }

  return gross_pay;
}

/**
 * @brief Writes the payroll data to the output stream sent as a parameter
 *
 * @param out - output stream
 */
void PayrollData::WriteData(std::ostream &out) const {
  out << hours_ << " " << pay_type_ << " " << pay_rate_ << endl
      << last_name_ << ", " << first_name_ << endl;
}

/**
 * @brief Writes a labeled report about the payroll data
 *
 * @param out - output stream to write the report to
 */
void PayrollData::PayrollReport(std::ostream &out) const {
  string expanded_pay_type;
  if (pay_type_ == 'h') {
    expanded_pay_type = "hourly";
  } else {
    expanded_pay_type = "salary";
  }

  out << setprecision(2) << fixed;
  out << first_name_ << " " << last_name_ << endl
      << "Hours Worked: " << hours_ << endl
      << "Pay Type: " << expanded_pay_type << endl
      << "Pay Rate: $" << pay_rate_ << endl
      << "Gross Pay: $" << ComputeGross() << endl;
}
