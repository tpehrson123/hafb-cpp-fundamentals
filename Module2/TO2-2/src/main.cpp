#include <fstream>
#include <iostream>
#include "fileio.h"
#include "payroll_data.h"

using namespace std;

int main() {
  // PayrollData payroll_data;

  // cout << "hours: " << payroll_data.hours()
  //      << " pay type: " << payroll_data.pay_type()
  //      << " pay rate: " << payroll_data.pay_rate()
  //      << " name: " << payroll_data.name();

  // PayrollData payroll_data2(43, 'h', 18.25, "Kelly Jones");

  // cout << "\n\nhours: " << payroll_data2.hours()
  //      << " pay type: " << payroll_data2.pay_type()
  //      << " pay rate: " << payroll_data2.pay_rate()
  //      << " name: " << payroll_data2.name();

  // try {
  //   payroll_data.set_hours(25);
  //   payroll_data.set_pay_type('s');
  //   payroll_data.set_pay_rate(1265.80);
  //   payroll_data.set_name("Kim Walters");
  // } catch (out_of_range e) {
  //   cout << "Error: " << e.what() << endl;
  // }

  // cout << "\n\nhours: " << payroll_data.hours()
  //      << " pay type: " << payroll_data.pay_type()
  //      << " pay rate: " << payroll_data.pay_rate()
  //      << " name: " << payroll_data.name();

  // cout << "\nGross for payroll_data: " << payroll_data.ComputeGross() <<
  // endl; cout << "\nGross for payroll_data2: " << payroll_data2.ComputeGross()
  // << endl;

  // payroll_data.WriteData(cout);
  // payroll_data2.WriteData(cout);

  // ofstream out("../output.txt");
  // payroll_data.WriteData(out);
  // payroll_data2.WriteData(out);

  // payroll_data.PayrollReport(cout);
  // payroll_data2.PayrollReport(cout);

  // ofstream output("../reports.txt");

  // payroll_data.PayrollReport(output);
  // payroll_data2.PayrollReport(output);

  string message;
  array<PayrollData, kMaxSize> payroll;

  int size = 0;
  message = ReadDataFromFile("../too_much_data.txt", payroll, size);

  cout << "Message: " << message << endl;
  cout << "How many: " << size << endl;
  for (int i = 0; i < size; i++) {
    payroll[i].WriteData(cout);
  }

  WriteDataToFile("../output.txt",payroll, size);
}
