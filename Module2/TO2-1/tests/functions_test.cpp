// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <array>
#include <cmath>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

TEST_CASE("Consant kMaxSize is defined and set to 32", "[read]") {
  CHECK(kMaxSize == 32);
}

TEST_CASE(
    "ReadDataFromFile function returns 'Unable to open file' when file is not "
    "found",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message =
      ReadDataFromFile("../no_file.txt", hours, pay_type, pay, names, size);

  CHECK(message == "Unable to open file");
}

TEST_CASE(
    "ReadDataFromFile function returns size of 20 and message '' when filename "
    "is payroll_data.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_data.txt", hours, pay_type, pay, names,
                             size);

  CHECK(size == 20);
  CHECK(message == "");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message '' when filename is payroll_data.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_data.txt", hours, pay_type, pay, names,
                             size);
  array<double, kMaxSize> test_hours = {42, 37.5, 40, 40,    52, 31.75, 51,
                                        33, 40,   0,  62,    43, 29,    40.5,
                                        27, 49.8, 56, 12.75, 40, 18.2};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 'h', 'h', 's', 's', 'h', 'h',
                                         'h', 'h', 'h', 's', 's', 's', 'h',
                                         'h', 'h', 's', 'h', 's', 'h'};
  array<double, kMaxSize> test_pay = {
      17.25,  12.45,  21.0,   835.0, 1215.0, 22.15, 25.0,   14.5, 27.35,  15.0,
      2250.0, 2100.0, 1845.0, 24.5,  14.75,  28.4,  1895.0, 12.6, 1920.0, 31.2};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
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
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 20);
  CHECK(message == "");
}

TEST_CASE(
    "ReadDataFromFile function reads 32 values and returns the "
    "message '' when filename is too_much_data.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../too_much_data.txt", hours, pay_type, pay,
                             names, size);
  array<double, kMaxSize> test_hours = {
      42, 37.5, 40,   40,    52,   31.75, 51,    33, 40,   0,  62,
      43, 29,   40.5, 27,    49.8, 56,    12.75, 40, 18.2, 42, 37.5,
      40, 40,   52,   31.75, 51,   33,    40,    0,  62,   43};

  for (int i = 0; i < kMaxSize; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
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

  for (int i = 0; i < kMaxSize; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
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

  for (int i = 0; i < kMaxSize; i++) {
    CHECK(names[i] == test_names[i]);
  }

  INFO(
      "Possible security breach. Data has been written outside the bounds of "
      "the array!")
  CHECK(size == 32);
  CHECK(message == "");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message 'Hours is out of range, set to 0 ' when filename is "
    "payroll_error1.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error1.txt", hours, pay_type, pay,
                             names, size);
  array<double, kMaxSize> test_hours = {0, 31.75};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 'h'};
  array<double, kMaxSize> test_pay = {1215.0, 22.15};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Stamey, Marty", "Rose, Geri"};
  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message == "Hours is out of range, set to 0 ");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message 'Hours is out of range, set to 0 ' when filename is "
    "payroll_error2.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error2.txt", hours, pay_type, pay,
                             names, size);
  array<double, kMaxSize> test_hours = {0, 31.75};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 'h'};
  array<double, kMaxSize> test_pay = {1215.0, 22.15};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Stamey, Marty", "Rose, Geri"};
  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message == "Hours is out of range, set to 0 ");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message 'Incorrect pay type, set to s ' when filename is "
    "payroll_error3.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error3.txt", hours, pay_type, pay,
                             names, size);
  array<double, kMaxSize> test_hours = {52, 31.75};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 'h'};
  array<double, kMaxSize> test_pay = {1215.0, 22.15};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Stamey, Marty", "Rose, Geri"};
  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message == "Incorrect pay type, set to s ");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message 'Pay is less than minimum wage, set to 7.25 ' when filename is "
    "payroll_error4.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error4.txt", hours, pay_type, pay,
                             names, size);
  array<double, kMaxSize> test_hours = {52, 31.75};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 'h'};
  array<double, kMaxSize> test_pay = {1215.0, 7.25};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Stamey, Marty", "Rose, Geri"};
  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message == "Pay is less than minimum wage, set to 7.25 ");
}

TEST_CASE(
    "ReadDataFromFile function reads correct values and returns the "
    "message 'Hours is out of range, set to 0 ' when filename is "
    "payroll_error5.txt",
    "[read]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int size = 0;
  string message;
  message = ReadDataFromFile("../payroll_error5.txt", hours, pay_type, pay,
                             names, size);
  array<double, kMaxSize> test_hours = {0, 31.75};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 's'};
  array<double, kMaxSize> test_pay = {1215.0, 22.15};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Stamey, Marty", "unknown"};
  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message ==
          "Hours is out of range, set to 0 Incorrect pay type, set to s Name "
          "is not in last, first format ");
}

TEST_CASE(
    "AddPayrollData function returns the message 'Arrays are full, no payroll "
    "data added' when the size parameter indicates the arrays are already "
    "full.",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = kMaxSize;

  // add payroll data
  string message = AddPayrollData(hours, pay_type, pay, names, 36, 'h', 23.5,
                                  "Wilson, Sarah", size);

  CHECK(size == kMaxSize);
  CHECK(message == "Arrays are full, no payroll data added");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message '' when data is all within range",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 36, 'h', 23.5,
                                   "Wilson, Sarah", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, 43, 's', 2395,
                                   "Jones, Kim", size);

  array<double, kMaxSize> test_hours = {36, 43};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 's'};
  array<double, kMaxSize> test_pay = {23.5, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Wilson, Sarah", "Jones, Kim"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 == "");
  CHECK(message2 == "");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message 'Hours is out of range, set to 0 ' when hours is 172",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 172, 'h', 23.5,
                                   "Wilson, Sarah", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, 43, 's', 2395,
                                   "Jones, Kim", size);

  array<double, kMaxSize> test_hours = {0, 43};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 's'};
  array<double, kMaxSize> test_pay = {23.5, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Wilson, Sarah", "Jones, Kim"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 == "Hours is out of range, set to 0 ");
  CHECK(message2 == "");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message 'Hours is out of range, set to 0 ' when hours is -3",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 35, 'h', 23.5,
                                   "Wilson, Sarah", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, -3, 's', 2395,
                                   "Jones, Kim", size);

  array<double, kMaxSize> test_hours = {35, 0};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 's'};
  array<double, kMaxSize> test_pay = {23.5, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Wilson, Sarah", "Jones, Kim"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 == "");
  CHECK(message2 == "Hours is out of range, set to 0 ");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message 'Incorrect pay type, set to s ' when pay type is 'y'",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 35, 'y', 23.5,
                                   "Wilson, Sarah", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, 53, 's', 2395,
                                   "Jones, Kim", size);

  array<double, kMaxSize> test_hours = {35, 53};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 's'};
  array<double, kMaxSize> test_pay = {23.5, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Wilson, Sarah", "Jones, Kim"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 == "Incorrect pay type, set to s ");
  CHECK(message2 == "");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message 'Hours is out of range, set to 0 ' when pay is 7.22",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 32, 'h', 7.22,
                                   "Wilson, Sarah", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, 43, 's', 2395,
                                   "Jones, Kim", size);

  array<double, kMaxSize> test_hours = {32, 43};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 's'};
  array<double, kMaxSize> test_pay = {7.25, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Wilson, Sarah", "Jones, Kim"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 == "Pay is less than minimum wage, set to 7.25 ");
  CHECK(message2 == "");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message 'Name is not in last, first format ' name is 'Kim Jones'",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 35, 'h', 23.5,
                                   "Wilson, Sarah", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, 53, 's', 2395,
                                   "Kim Jones", size);

  array<double, kMaxSize> test_hours = {35, 53};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'h', 's'};
  array<double, kMaxSize> test_pay = {23.5, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"Wilson, Sarah", "unknown"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 == "");
  CHECK(message2 == "Name is not in last, first format ");
}

TEST_CASE(
    "AddPayrollData function add values to arrays and returns the "
    "message 'Hours is out of range, set to 0 Incorrect pay type, set to s "
    "Name is not in last, first format ' when hours is 170 and name is "
    "'Sarah Wilson'",
    "[add]") {
  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  int size = 0;

  // add payroll data
  string message1 = AddPayrollData(hours, pay_type, pay, names, 170, 'y', 23.5,
                                   "Sarah Wilson", size);
  string message2 = AddPayrollData(hours, pay_type, pay, names, 53, 's', 2395,
                                   "Jones, Kim", size);

  array<double, kMaxSize> test_hours = {0, 53};

  for (int i = 0; i < size; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  array<char, kMaxSize> test_pay_type = {'s', 's'};
  array<double, kMaxSize> test_pay = {23.5, 2395};

  for (int i = 0; i < size; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  array<string, kMaxSize> test_names = {"unknown", "Jones, Kim"};

  for (int i = 0; i < size; i++) {
    CHECK(names[i] == test_names[i]);
  }

  CHECK(size == 2);
  CHECK(message1 ==
          "Hours is out of range, set to 0 Incorrect pay type, set to s Name "
          "is not in last, first format ");
  CHECK(message2 == "");
}

TEST_CASE(
    "ComputeGross returns 752 when hours is 32, pay type is h, and pay is "
    "23.5",
    "[gross]") {
  double gross = ComputeGross(32, 'h', 23.5);

  CHECK(fabs(gross - 752) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1010.5 when hours is 42, pay type is h, and pay is "
    "23.5",
    "[gross]") {
  double gross = ComputeGross(42, 'h', 23.5);

  CHECK(fabs(gross - 1010.5) < .0001);
}

TEST_CASE(
    "ComputeGross returns 0 when hours is 0, pay type is h, and pay is "
    "23.5",
    "[gross]") {
  double gross = ComputeGross(0, 'h', 23.5);

  CHECK(fabs(gross - 0) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2324.4 when hours is 63, pay type is h, and pay is "
    "31.2",
    "[gross]") {
  double gross = ComputeGross(63, 'h', 31.2);

  CHECK(fabs(gross - 2324.4) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2382 when hours is 48, pay type is s, and pay is "
    "2382",
    "[gross]") {
  double gross = ComputeGross(48, 's', 2382);

  CHECK(fabs(gross - 2382) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1279 when hours is 26, pay type is s, and pay is "
    "1279",
    "[gross]") {
  double gross = ComputeGross(26, 's', 1279);

  CHECK(fabs(gross - 1279) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1279 when hours is 0, pay type is s, and pay is "
    "1279",
    "[gross]") {
  double gross = ComputeGross(0, 's', 1279);

  CHECK(fabs(gross - 1279) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2150 when hours is 68, pay type is s, and pay is "
    "2150",
    "[gross]") {
  double gross = ComputeGross(0, 's', 2150);

  CHECK(fabs(gross - 2150) < .0001);
}

TEST_CASE(
    "WritePayrollReportToFile writes data from arrays to file as expected.",
    "[write_report]") {
  array<double, kMaxSize> test_hours = {42, 37.5, 40, 40,    52, 31.75, 51,
                                        33, 40,   0,  62,    43, 29,    40.5,
                                        27, 49.8, 56, 12.75, 40, 18.2};

  array<char, kMaxSize> test_pay_type = {'h', 'h', 'h', 's', 's', 'h', 'h',
                                         'h', 'h', 'h', 's', 's', 's', 'h',
                                         'h', 'h', 's', 'h', 's', 'h'};
  array<double, kMaxSize> test_pay = {
      17.25,  12.45,  21.0,   835.0, 1215.0, 22.15, 25.0,   14.5, 27.35,  15.0,
      2250.0, 2100.0, 1845.0, 24.5,  14.75,  28.4,  1895.0, 12.6, 1920.0, 31.2};

  array<string, kMaxSize> names_in = {
      "Collins, Bill",    "Smith, Bart",     "Allen, Jim",
      "Griffin, Jim",     "Stamey, Marty",   "Rose, Geri",
      "Taylor, Terri K.", "Johnson, Jill",   "Allison, Jeff",
      "Looney, Joe I.",   "Wolfe, Bill",     "James, Jean Will",
      "Weaver, Jim",      "Pore, Bob E.",    "Rutherford, Greg",
      "Javens, Renee C.", "Harrison, Rose",  "Setzer, Cathy",
      "Pike, Gordon J.",  "Holland, Beth R."};

  array<string, kMaxSize> test_names = {
      "Bill Collins",  "Bart Smith",    "Jim Allen",       "Jim Griffin",
      "Marty Stamey",  "Geri Rose",     "Terri K. Taylor", "Jill Johnson",
      "Jeff Allison",  "Joe I. Looney", "Bill Wolfe",      "Jean Will James",
      "Jim Weaver",    "Bob E. Pore",   "Greg Rutherford", "Renee C. Javens",
      "Rose Harrison", "Cathy Setzer",  "Gordon J. Pike",  "Beth R. Holland"};

  int size = 20;
  WritePayrollReportToFile("test.out", test_hours, test_pay_type, test_pay,
                           names_in, size);

  // open file
  ifstream in("test.out");
  if (in.fail()) {
    CHECK("File Opened" == "Unable to open file");
  }

  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names_out;
  array<double, kMaxSize> gross;

  // read data from file
  int test_index = 0;

  while (getline(in, names_out[test_index])) {
    in >> hours[test_index] >> pay_type[test_index] >> pay[test_index] >>
        gross[test_index];
    in.ignore();
    ;
    test_index++;
  }

  in.close();

  for (int i = 0; i < test_index; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  for (int i = 0; i < test_index; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  double computed_gross;
  double rounded_gross;

  for (int i = 0; i < test_index; i++) {
    // compute gross and round to two digits
    computed_gross = ComputeGross(test_hours[i], test_pay_type[i], test_pay[i]);
    rounded_gross = static_cast<int>(computed_gross * 100 + .5) / 100.0;

    CHECK(fabs(gross[i] - rounded_gross) < .0001);
  }

  for (int i = 0; i < test_index; i++) {
    CHECK(names_out[i] == test_names[i]);
  }
}

//*************************

TEST_CASE("WritePayrollDataToFile writes data from arrays to file as expected.",
          "[write_data]") {
  array<double, kMaxSize> test_hours = {42, 37.5, 40, 40,    52, 31.75, 51,
                                        33, 40,   0,  62,    43, 29,    40.5,
                                        27, 49.8, 56, 12.75, 40, 18.2};

  array<char, kMaxSize> test_pay_type = {'h', 'h', 'h', 's', 's', 'h', 'h',
                                         'h', 'h', 'h', 's', 's', 's', 'h',
                                         'h', 'h', 's', 'h', 's', 'h'};
  array<double, kMaxSize> test_pay = {
      17.25,  12.45,  21.0,   835.0, 1215.0, 22.15, 25.0,   14.5, 27.35,  15.0,
      2250.0, 2100.0, 1845.0, 24.5,  14.75,  28.4,  1895.0, 12.6, 1920.0, 31.2};

  array<string, kMaxSize> names_in = {
      "Collins, Bill",    "Smith, Bart",     "Allen, Jim",
      "Griffin, Jim",     "Stamey, Marty",   "Rose, Geri",
      "Taylor, Terri K.", "Johnson, Jill",   "Allison, Jeff",
      "Looney, Joe I.",   "Wolfe, Bill",     "James, Jean Will",
      "Weaver, Jim",      "Pore, Bob E.",    "Rutherford, Greg",
      "Javens, Renee C.", "Harrison, Rose",  "Setzer, Cathy",
      "Pike, Gordon J.",  "Holland, Beth R."};

  array<string, kMaxSize> test_names = {
      "Collins, Bill",    "Smith, Bart",     "Allen, Jim",
      "Griffin, Jim",     "Stamey, Marty",   "Rose, Geri",
      "Taylor, Terri K.", "Johnson, Jill",   "Allison, Jeff",
      "Looney, Joe I.",   "Wolfe, Bill",     "James, Jean Will",
      "Weaver, Jim",      "Pore, Bob E.",    "Rutherford, Greg",
      "Javens, Renee C.", "Harrison, Rose",  "Setzer, Cathy",
      "Pike, Gordon J.",  "Holland, Beth R."};

  int size = 20;
  WritePayrollDataToFile("test.out", test_hours, test_pay_type, test_pay,
                         test_names, size);

  // open file
  ifstream in("test.out");
  if (in.fail()) {
    CHECK("File Opened" == "Unable to open file");
  }

  array<double, kMaxSize> hours;
  array<char, kMaxSize> pay_type;
  array<double, kMaxSize> pay;
  array<string, kMaxSize> names;

  // read data from file
  int test_index = 0;

  while (in >> hours[test_index]) {
    in >> pay_type[test_index] >> pay[test_index];
    in.ignore();
    getline(in, names[test_index]);
    test_index++;
  }

  in.close();

  for (int i = 0; i < test_index; i++) {
    CHECK(fabs(hours[i] - test_hours[i]) < .0001);
  }

  for (int i = 0; i < test_index; i++) {
    CHECK(pay_type[i] == test_pay_type[i]);
    CHECK(fabs(pay[i] - test_pay[i]) < .0001);
  }

  for (int i = 0; i < test_index; i++) {
    CHECK(names[i] == test_names[i]);
  }
}
