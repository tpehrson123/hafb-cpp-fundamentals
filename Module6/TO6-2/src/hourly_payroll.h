#ifndef HOURLY_PAYROLL_H
#define HOURLY_PAYROLL_H

#include <fstream>
#include <iostream>
#include "payroll_data.h"

class HourlyPayroll : public PayrollData {
 private:
  double hours_;

 public:
  // static data members
  static const double kMinHours;
  static const double kMaxHours;
  static const double kRegularHours;
  static const double kOvertimeRate;
  static const double kMinWage;

  // constructors and destructor
  HourlyPayroll();
  HourlyPayroll(double pay_rate, double hours_worked, std::string name);
  ~HourlyPayroll() {}

  // getters
  double hours() const { return hours_; }

  // setters
  void set_pay_rate(double pay_rate);
  void set_hours(double hours_worked);

  // other methods
  double ComputeGross() const;
  void WriteData(std::ostream &out) const;
  void PayrollReport(std::ostream &out) const;
};

#endif