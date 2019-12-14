// this tells catch to provide a main()
// only do this in one cpp file
// #define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include "fileio.h"
#include "payroll_data.h"

using namespace std;

//****************************ReadDataFromFile****************************
TEST_CASE("Consant kMaxSize is defined and set to 32", "[read]") {
  REQUIRE(kMaxSize == 32);
}

TEST_CASE(
    "ReadDataFromFile function returns 'Unable to open file' when file is not "
    "found",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../no_file.txt", payroll_data, size);

  REQUIRE(message == "Unable to open file.");
}

TEST_CASE(
    "ReadDataFromFile function returns size of 20 and message '' when filename "
    "is payroll_data.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_data.txt", payroll_data, size);

  REQUIRE(size == 20);
  REQUIRE(message == "");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message '' when filename is payroll_data.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_data.txt", payroll_data, size);
  array<double, kMaxSize> test_hours = {42, 37.5, 40, 40,    52, 31.75, 51,
                                        33, 40,   0,  62,    43, 29,    40.5,
                                        27, 49.8, 56, 12.75, 40, 18.2};

  for (int i = 0; i < size; i++) {
    REQUIRE(fabs(payroll_data[i].hours() - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 'h', 'h', 's', 's', 'h', 'h',
                                         'h', 'h', 'h', 's', 's', 's', 'h',
                                         'h', 'h', 's', 'h', 's', 'h'};
  array<double, kMaxSize> test_pay = {
      17.25,  12.45,  21.0,   835.0, 1215.0, 22.15, 25.0,   14.5, 27.35,  15.0,
      2250.0, 2100.0, 1845.0, 24.5,  14.75,  28.4,  1895.0, 12.6, 1920.0, 31.2};

  for (int i = 0; i < size; i++) {
    REQUIRE(payroll_data[i].pay_type() == test_pay_type[i]);
    REQUIRE(fabs(payroll_data[i].pay_rate() - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {
      "Collins, Bill",    "Smith, Bart",     "Allen, Jim",
      "Griffin, Jim",     "Stamey, Marty",   "Rose, Geri",
      "Taylor, Terri K.", "Johnson, Jill",   "Allison, Jeff",
      "Looney, Joe I.",   "Wolfe, Bill",     "James, Jean Will",
      "Weaver, Jim",      "Pore, Bob E.",    "Rutherford, Greg",
      "Javens, Renee C.", "Harrison, Rose",  "Setzer, Cathy",
      "Pike, Gordon J.",  "Holland, Beth R."};

  for (int i = 0; i < size; i++) {
    REQUIRE(payroll_data[i].name_last_first() == test_names[i]);
  }

  REQUIRE(size == 20);
  REQUIRE(message == "");
}

TEST_CASE(
    "ReadDataFromFile function reads 32 values and returns the "
    "message '' when filename is too_much_data.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../too_much_data.txt", payroll_data, size);

  INFO(
      "Possible security breach. Data has been written outside the bounds of "
      "the array!")
  REQUIRE(size == 32);
  REQUIRE(message == "");

  array<double, kMaxSize> test_hours = {
      42, 37.5, 40,   40,    52,   31.75, 51,    33, 40,   0,  62,
      43, 29,   40.5, 27,    49.8, 56,    12.75, 40, 18.2, 42, 37.5,
      40, 40,   52,   31.75, 51,   33,    40,    0,  62,   43};

  for (int i = 0; i < size; i++) {
    REQUIRE(fabs(payroll_data[i].hours() - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {
      'h', 'h', 'h', 's', 's', 'h', 'h', 'h', 'h', 'h', 's',
      's', 's', 'h', 'h', 'h', 's', 'h', 's', 'h', 'h', 'h',
      'h', 's', 's', 'h', 'h', 'h', 'h', 'h', 's', 's'};
  array<double, kMaxSize> test_pay = {
      17.25,  12.45, 21.0,   835.0,  1215.0, 22.15, 25.0,   14.5,
      27.35,  15.0,  2250.0, 2100.0, 1845.0, 24.5,  14.75,  28.4,
      1895.0, 12.6,  1920.0, 31.2,   17.25,  12.45, 21.0,   835.0,
      1215.0, 22.15, 25.0,   14.5,   27.35,  15.0,  2250.0, 2100.0};

  for (int i = 0; i < size; i++) {
    REQUIRE(payroll_data[i].pay_type() == test_pay_type[i]);
    REQUIRE(fabs(payroll_data[i].pay_rate() - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {
      "Collins, Bill",    "Smith, Bart",      "Allen, Jim",
      "Griffin, Jim",     "Stamey, Marty",    "Rose, Geri",
      "Taylor, Terri K.", "Johnson, Jill",    "Allison, Jeff",
      "Looney, Joe I.",   "Wolfe, Bill",      "James, Jean Will",
      "Weaver, Jim",      "Pore, Bob E.",     "Rutherford, Greg",
      "Javens, Renee C.", "Harrison, Rose",   "Setzer, Cathy",
      "Pike, Gordon J.",  "Holland, Beth R.", "Collins, Bill",
      "Smith, Bart",      "Allen, Jim",       "Griffin, Jim",
      "Stamey, Marty",    "Rose, Geri",       "Taylor, Terri K.",
      "Johnson, Jill",    "Allison, Jeff",    "Looney, Joe I.",
      "Wolfe, Bill",      "James, Jean Will",
  };

  for (int i = 0; i < size; i++) {
    REQUIRE(payroll_data[i].name_last_first() == test_names[i]);
  }
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns a "
    "message that begins with 'Unable to add payroll data for Stamey, Marty' "
    "when filename is payroll_error1.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error1.txt", payroll_data, size);

  REQUIRE(fabs(payroll_data[0].hours() - 31.75) < .0001);
  REQUIRE(payroll_data[0].pay_type() == 'h');
  REQUIRE(fabs(payroll_data[0].pay_rate() - 22.15) < .0001);
  REQUIRE(payroll_data[0].name_last_first() == "Rose, Geri");

  REQUIRE(size == 1);
  REQUIRE(message.substr(0, 44) ==
          "Unable to add payroll data for Stamey, Marty");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns a "
    "message that begins with 'Unable to add payroll data for Stamey, Marty' "
    "when filename is payroll_error2.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error2.txt", payroll_data, size);

  REQUIRE(fabs(payroll_data[0].hours() - 31.75) < .0001);
  REQUIRE(payroll_data[0].pay_type() == 'h');
  REQUIRE(fabs(payroll_data[0].pay_rate() - 22.15) < .0001);
  REQUIRE(payroll_data[0].name_last_first() == "Rose, Geri");

  REQUIRE(size == 1);
  REQUIRE(message.substr(0, 44) ==
          "Unable to add payroll data for Stamey, Marty");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns a "
    "message that begins with 'Unable to add payroll data for Stamey, Marty' "
    "when filename is payroll_error3.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error3.txt", payroll_data, size);

  REQUIRE(fabs(payroll_data[0].hours() - 31.75) < .0001);
  REQUIRE(payroll_data[0].pay_type() == 'h');
  REQUIRE(fabs(payroll_data[0].pay_rate() - 22.15) < .0001);
  REQUIRE(payroll_data[0].name_last_first() == "Rose, Geri");

  REQUIRE(size == 1);
  REQUIRE(message.substr(0, 44) ==
          "Unable to add payroll data for Stamey, Marty");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns a "
    "message that begins with 'Unable to add payroll data for Rose, Geri' "
    "when filename is payroll_error4.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error4.txt", payroll_data, size);

  REQUIRE(fabs(payroll_data[0].hours() - 52) < .0001);
  REQUIRE(payroll_data[0].pay_type() == 's');
  REQUIRE(fabs(payroll_data[0].pay_rate() - 1215) < .0001);
  REQUIRE(payroll_data[0].name_last_first() == "Stamey, Marty");

  REQUIRE(size == 1);
  REQUIRE(message.substr(0, 41) == "Unable to add payroll data for Rose, Geri");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns a "
    "message that begins with 'Unable to add payroll data for Stamey, Marty' "
    "when filename is payroll_error5.txt",
    "[read]") {
  array<PayrollData, kMaxSize> payroll_data;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error5.txt", payroll_data, size);

  REQUIRE(size == 0);
  REQUIRE(message.substr(0, 44) ==
          "Unable to add payroll data for Stamey, Marty");
}

//****************************WriteDataToFile****************************

TEST_CASE("WriteDataToFile writes data from array to file as expected.",
          "[write]") {
  array<PayrollData, kMaxSize> payroll_data = {
      PayrollData(29, 's', 1845, "Weaver, Jim"),
      PayrollData(40.5, 'h', 24.5, "Pore, Bob E."),
      PayrollData(27, 'h', 14.75, "Rutherford, Greg"),
      PayrollData(49.8, 'h', 28.4, "Javens, Renee C."),
      PayrollData(56, 's', 1895, "Harrison, Rose"),
      PayrollData(12.75, 'h', 12.6, "Setzer, Cathy")};

  int size = 6;
  WriteDataToFile("test.out", payroll_data, size);

  // open file
  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }

  // read data from file
  string line;
  getline(in, line);
  REQUIRE(line == "29 s 1845");
  getline(in, line);
  REQUIRE(line == "Weaver, Jim");
  getline(in, line);
  REQUIRE(line == "40.5 h 24.5");
  getline(in, line);
  REQUIRE(line == "Pore, Bob E.");
  getline(in, line);
  REQUIRE(line == "27 h 14.75");
  getline(in, line);
  REQUIRE(line == "Rutherford, Greg");
  getline(in, line);
  REQUIRE(line == "49.8 h 28.4");
  getline(in, line);
  REQUIRE(line == "Javens, Renee C.");
  getline(in, line);
  REQUIRE(line == "56 s 1895");
  getline(in, line);
  REQUIRE(line == "Harrison, Rose");
  getline(in, line);
  REQUIRE(line == "12.75 h 12.6");
  getline(in, line);
  REQUIRE(line == "Setzer, Cathy");
  getline(in, line);
  REQUIRE(line == "");
}
