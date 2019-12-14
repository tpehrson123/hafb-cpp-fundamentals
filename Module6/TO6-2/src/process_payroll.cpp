
#include "process_payroll.h"

#include <fstream>
#include <string>
#include <vector>
#include "commission_payroll.h"
#include "hourly_payroll.h"
#include "payroll_data.h"
#include "salary_payroll.h"

void ProcessPayroll(std::string inputFile, std::string outputFile) {
  std::ifstream input(inputFile);
  if (input.fail()) {
    std::cout << "Unable to open file. Shutting down...\n";
    return;
  }

  std::vector<PayrollData*> payroll;

  char type;
  double pay_rate;
  double hours;
  int how_many;
  double base;
  std::string name;

  // read data from file
  while (input >> type) {
    switch (type) {
      case 'H':
        input >> pay_rate >> hours;
        input.ignore();
        getline(input, name);
        try {
          payroll.push_back(new HourlyPayroll(pay_rate, hours, name));
        } catch (const std::exception& e) {
          throw std::out_of_range(name + ": " + e.what());
        }

        break;
      case 'S':
        input >> pay_rate;
        input.ignore();
        getline(input, name);
        try {
          payroll.push_back(new SalaryPayroll(pay_rate, name));
        } catch (const std::exception& e) {
          throw std::out_of_range(name + ": " + e.what());
        }
        break;
      case 'C':
        input >> pay_rate >> how_many >> base;
        input.ignore();
        getline(input, name);
        try {
          payroll.push_back(
              new CommissionPayroll(pay_rate, how_many, base, name));
        } catch (const std::exception& e) {
          throw std::out_of_range(name + ": " + e.what());
        }
        break;
      default:
        throw std::out_of_range("Invalid payroll type");
        break;
    }
  }

  // output payroll report
  std::ofstream output(outputFile);
  for (auto &one_ptr : payroll) {
    one_ptr->PayrollReport(output);
  }

  // delete the new memory
  for (auto &one_ptr : payroll) {
    delete one_ptr;
    one_ptr = NULL;
  }
}