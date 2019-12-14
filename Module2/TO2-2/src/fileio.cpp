#include "fileio.h"

#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include "payroll_data.h"

/**
 * @brief Reads payroll data from a file, creates PayrollData objects and
 * stores them in the array
 *
 * @param filename - filename where payroll data is, including path and
 * extension
 * @param payroll_data - array of PayrollData objects
 * @param size - current location in the array
 * @return std::string - empty or error message when file does not open or
 * there is an invalid payroll data
 */
std::string ReadDataFromFile(std::string filename,
                             std::array<PayrollData, kMaxSize> &payroll_data,
                             int &size) {
  // define and open input file stream
  std::ifstream in(filename);
  if (in.fail()) {
    return "Unable to open file.";
  }

  std::string message = "";

  // set up temp variables
  double hours;
  char pay_type;
  double pay_rate;
  std::string name;

  // loop through the array
  while (size < kMaxSize && in >> hours) {
    in >> pay_type >> pay_rate;
    in.ignore();
    getline(in, name);

    try {
      payroll_data[size] = PayrollData(hours, pay_type, pay_rate, name);
      size++;
    } catch (std::out_of_range e) {
      message += "Unable to add payroll data for " + name + e.what();
    }
  }

  in.close();

  return message;
}

/**
 * @brief Writes payroll data from array to a file
 * 
 * @param filename - filename where payroll will be written, including path and
 * extension
 * @param payroll_data - array of PayrollData objects
 * @param size - current size of valid values in the array 
 */
void WriteDataToFile(std::string filename,
                     const std::array<PayrollData, kMaxSize> &payroll_data,
                     int size) {
  std::ofstream out(filename);

  // loop through array and write Payroll data to file
  for (int i = 0; i < size; i++) {
    payroll_data[i].WriteData(out);
  }

  out.close();
}