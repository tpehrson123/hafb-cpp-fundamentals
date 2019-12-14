#include "commission_payroll.h"

#include <iomanip>
#include <iostream>

CommissionPayroll::CommissionPayroll(double pay_rate, int how_many,
                                     double base_pay, std::string name)
    : PayrollData(pay_rate, name) {
  set_base_pay(base_pay);
  set_how_many(how_many);
}

// setters
void CommissionPayroll::set_how_many(int how_many) {
  if (how_many < 0) {
    throw std::out_of_range("How many must be positive");
  }
  how_many_ = how_many;
}
void CommissionPayroll::set_base_pay(double base_pay) {
  if (base_pay < 0) {
    throw std::out_of_range("Base pay must be positive");
  }
  base_pay_ = base_pay;
}

/**
 * @brief Computes commission for pay period
 *
 * @return double - computed commission
 */
double CommissionPayroll::ComputeCommission() const {
  return pay_rate_ * how_many_;
}

/**
 * @brief Computes gross pay for pay period
 *
 * @return double - computed gross pay
 */
double CommissionPayroll::ComputeGross() const {
  return pay_rate_ * how_many_ + base_pay_;
}

/**
 * @brief Writes the salary payroll data to the output stream sent as a
 * parameter
 *
 * @param out - output stream
 */
void CommissionPayroll::WriteData(std::ostream &out) const {
  out << "C"
      << " " << pay_rate_ << " " << how_many_ << " " << base_pay_ << std::endl
      << last_name_ << ", " << first_name_ << std::endl;
}

/**
 * @brief Writes a labeled report about the payroll data
 *
 * @param out - output stream to write the report to
 */
void CommissionPayroll::PayrollReport(std::ostream &out) const {
  out << std::setprecision(2) << std::fixed;
  out << first_name_ << " " << last_name_ << std::endl
      << "Pay Type: "
      << "commission" << std::endl
      << "Pay Rate: $" << pay_rate_ << std::endl
      << "How Many: " << how_many_ << std::endl
      << "Commission: $" << ComputeCommission() << std::endl
      << "Base Pay: $" << base_pay_ << std::endl
      << "Gross Pay: $" << ComputeGross() << std::endl;
}
