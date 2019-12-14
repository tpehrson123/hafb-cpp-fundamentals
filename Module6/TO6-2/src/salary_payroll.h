#ifndef SALARY_PAYROLL_H
#define SALARY_PAYROLL_H

#include <fstream>
#include <iostream>
#include "payroll_data.h"

class SalaryPayroll : public PayrollData {
 public:
  // constructors and destructor
  SalaryPayroll() {}
  SalaryPayroll(double pay_rate, std::string name)
      : PayrollData(pay_rate, name){}
  ~SalaryPayroll() {}

  // other methods
  double ComputeGross() const;
  void WriteData(std::ostream &out) const;
  void PayrollReport(std::ostream &out) const;
};

#endif