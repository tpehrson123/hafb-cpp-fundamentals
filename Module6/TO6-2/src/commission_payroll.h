#ifndef COMMISSION_PAYROLL_H
#define COMMISSION_PAYROLL_H

#include <fstream>
#include <iostream>
#include "payroll_data.h"

class CommissionPayroll : public PayrollData {
 private:
  int how_many_;
  double base_pay_;

 public:
  // constructors and destructor
  CommissionPayroll() : how_many_(0), base_pay_(0) {}
  CommissionPayroll(double pay_rate, int how_many, double base_pay,
                    std::string name);
  ~CommissionPayroll() {}

  // getters
  int how_many() const { return how_many_; }
  double base_pay() const { return base_pay_; }

  // setters
  void set_how_many(int how_many);
  void set_base_pay(double base_pay);

  // other methods
  double ComputeCommission() const;
  double ComputeGross() const;
  void WriteData(std::ostream &out) const;
  void PayrollReport(std::ostream &out) const;
};

#endif