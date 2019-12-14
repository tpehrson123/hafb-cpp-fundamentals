#include "payroll_data.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


/**
 * @brief Construct a new Payroll Data:: Payroll Data object
 *
 * @param hours - hours worked (between 1-168) 
 * @param pay_rate - pay rate, hourly pay rate or pay period salary
 * @param name - employee name in first last format or last, first format
 * @throw out_of_range exception when hours is outside of allowed range, pay
 * type is other than h or s, or pay rate is less than 7.25
 */
PayrollData::PayrollData(double pay_rate, std::string name) {
  try {
    set_pay_rate(pay_rate);
    set_name(name);
  } catch (out_of_range e) {
    throw;
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
  if (pay_rate < 0) {
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
