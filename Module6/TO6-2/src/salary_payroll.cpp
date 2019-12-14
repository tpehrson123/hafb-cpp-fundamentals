#include "salary_payroll.h"

#include <iomanip>
#include <iostream>

/**
 * @brief Computes gross pay for pay period
 *
 * @return double - computed gross pay
 */
double SalaryPayroll::ComputeGross() const { return pay_rate_; }

/**
 * @brief Writes the salary payroll data to the output stream sent as a
 * parameter
 *
 * @param out - output stream
 */
void SalaryPayroll::WriteData(std::ostream &out) const {
  out << "S"
      << " " << pay_rate_ << std::endl
      << last_name_ << ", " << first_name_ << std::endl;
}

/**
 * @brief Writes a labeled report about the payroll data
 *
 * @param out - output stream to write the report to
 */
void SalaryPayroll::PayrollReport(std::ostream &out) const {
  out << std::setprecision(2) << std::fixed;
  out << first_name_ << " " << last_name_ << std::endl
      << "Pay Type: "
      << "salary" << std::endl
      << "Pay Rate: $" << pay_rate_ << std::endl
      << "Gross Pay: $" << ComputeGross() << std::endl;
}
