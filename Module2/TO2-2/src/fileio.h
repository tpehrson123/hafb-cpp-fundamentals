#ifndef FILEIO_H
#define FILEIO_H

#include <array>
#include <string>
#include "payroll_data.h"

const int kMaxSize = 32;

std::string ReadDataFromFile(std::string filename,
                             std::array<PayrollData, kMaxSize> &payroll_data,
                             int &size);

void WriteDataToFile(std::string filename,
                     const std::array<PayrollData, kMaxSize> &payroll_data,
                     int size);

#endif