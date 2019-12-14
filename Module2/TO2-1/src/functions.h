#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <array>
#include <string>

const int kMaxSize = 32;

std::string ReadDataFromFile(std::string filename,
                             std::array<double, kMaxSize> &hours,
                             std::array<char, kMaxSize> &pay_type,
                             std::array<double, kMaxSize> &pay_rate,
                             std::array<std::string, kMaxSize> &names,
                             int &size);

std::string AddPayrollData(std::array<double, kMaxSize> &hours,
                           std::array<char, kMaxSize> &pay_type,
                           std::array<double, kMaxSize> &pay_rate,
                           std::array<std::string, kMaxSize> &names,
                           double new_hours, char new_pay_type,
                           double new_pay_rate, std::string new_name,
                           int &size);

double ComputeGross(double hours, char pay_type, double pay_rate);

void WritePayrollReportToFile(std::string filename,
                              const std::array<double, kMaxSize> &hours,
                              const std::array<char, kMaxSize> &pay_type,
                              const std::array<double, kMaxSize> &pay_rate,
                              const std::array<std::string, kMaxSize> &names,
                              int &size);

void WritePayrollDataToFile(std::string filename,
                            const std::array<double, kMaxSize> &hours,
                            const std::array<char, kMaxSize> &pay_type,
                            const std::array<double, kMaxSize> &pay_rate,
                            const std::array<std::string, kMaxSize> &names,
                            int &size);

#endif