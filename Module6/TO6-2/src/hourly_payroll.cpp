#include "hourly_payroll.h"

#include <iomanip>
#include <iostream>

const double HourlyPayroll::kMinHours = 0;
const double HourlyPayroll::kMaxHours = 168;
const double HourlyPayroll::kRegularHours = 40;
const double HourlyPayroll::kOvertimeRate = 1.5;
const double HourlyPayroll::kMinWage = 7.25;

/**
 * @brief Sets pay rate. Pay rate must be 7.25 or greater
 *
 * @param pay_rate - the pay rate for the employee, either hourly rate or
 * salary amount
 * @throw out_of_range exception when pay type is less than 7.25
 */
void HourlyPayroll::set_pay_rate(double pay_rate) {
  if (pay_rate < kMinWage) {
    throw std::out_of_range("Pay is less than minimum wage");
  }
  pay_rate_ = pay_rate;
}

void HourlyPayroll::set_hours(double hours_worked) {
  if (hours_worked < kMinHours || hours_worked > kMaxHours) {
    throw std::out_of_range("Hours is out of range");
  }
  hours_ = hours_worked;
}

HourlyPayroll::HourlyPayroll() {
  set_pay_rate(kMinWage);
  set_hours(kMinHours);
}

HourlyPayroll::HourlyPayroll(double pay_rate, double hours_worked,
                             std::string name) {
  set_pay_rate(pay_rate);
  set_hours(hours_worked);
  set_name(name);
}

/**
 * @brief Computes gross pay for pay period
 *
 * @return double - computed gross pay
 */
double HourlyPayroll::ComputeGross() const {
  double gross_pay;

  if (hours_ <= kRegularHours) {
    gross_pay = hours_ * pay_rate_;
  } else {
    gross_pay = kRegularHours * pay_rate_;
    gross_pay += (hours_ - kRegularHours) * pay_rate_ * kOvertimeRate;
  }

  return gross_pay;
}

/**
 * @brief Writes the hourly payroll data to the output stream sent as a
 * parameter
 *
 * @param out - output stream
 */
void HourlyPayroll::WriteData(std::ostream &out) const {
  out << "H"
      << " " << pay_rate_ << " " << hours_ << std::endl
      << last_name_ << ", " << first_name_ << std::endl;
}

/**
 * @brief Writes a labeled report about the payroll data
 *
 * @param out - output stream to write the report to
 */
void HourlyPayroll::PayrollReport(std::ostream &out) const {
  out << std::setprecision(2) << std::fixed;
  out << first_name_ << " " << last_name_ << std::endl
      << "Pay Type: "
      << "hourly" << std::endl
      << "Pay Rate: $" << pay_rate_ << std::endl
      << "Hours Worked: " << hours_ << std::endl
      << "Gross Pay: $" << ComputeGross() << std::endl;
}
