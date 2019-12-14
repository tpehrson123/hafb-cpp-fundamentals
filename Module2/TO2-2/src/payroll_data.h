#ifndef PAYROLL_DATA_H
#define PAYROLL_DATA_H

#include <string>

class PayrollData {
 private:
  double hours_;
  char pay_type_;
  double pay_rate_;
  std::string first_name_;
  std::string last_name_;

 public:
  static const double kRegularHours;
  static const double kOvertimeRate;
  // constructors and destructor
  PayrollData()
      : hours_(0),
        pay_type_('h'),
        pay_rate_(7.25),
        first_name_("it is"),
        last_name_("unknown") {}

  PayrollData(double hours, char pay_type, double pay_rate, std::string name);
  ~PayrollData(){};

  // getters
  double hours() const { return hours_; }
  char pay_type() const { return pay_type_; }
  double pay_rate() const { return pay_rate_; }
  std::string first_name() const { return first_name_; }
  std::string last_name() const { return last_name_; }
  std::string name() const { return first_name_ + " " + last_name_; }
  std::string name_last_first() const {
    return last_name_ + ", " + first_name_;
  }

  // setters
  void set_hours(double hours);
  void set_pay_type(char pay_type);
  void set_pay_rate(double pay_rate);
  void set_name(std::string name);

  // other methods
  double ComputeGross() const;  
  void WriteData(std::ostream &out) const;
  void PayrollReport(std::ostream &out) const;
};

#endif