#ifndef PAYROLL_DATA_H
#define PAYROLL_DATA_H

#include <string>

class PayrollData {
 protected:
  double pay_rate_;
  std::string first_name_;
  std::string last_name_;

 public:
  // constructors and destructor
  PayrollData() : pay_rate_(0), first_name_("it is"), last_name_("unknown") {}

  PayrollData(double pay_rate, std::string name);
  ~PayrollData(){};

  // getters
  double pay_rate() const { return pay_rate_; }
  std::string first_name() const { return first_name_; }
  std::string last_name() const { return last_name_; }
  std::string name() const { return first_name_ + " " + last_name_; }
  std::string name_last_first() const {
    return last_name_ + ", " + first_name_;
  }

  // setters
  virtual void set_pay_rate(double pay_rate);
  void set_name(std::string name);

  // other methods
  virtual double ComputeGross() const = 0;
  virtual void WriteData(std::ostream &out) const = 0;
  virtual void PayrollReport(std::ostream &out) const = 0;
};

#endif