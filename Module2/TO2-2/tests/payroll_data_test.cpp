// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <iostream>
#include <string>
#include "payroll_data.h"

using namespace std;

//***************************kRegularHours*************************
TEST_CASE("Consant kRegularHours is defined and set to 40", "[start]") {
  REQUIRE(PayrollData::kRegularHours == 40);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kOvertimeRate is defined and set to 1.5", "[start]") {
  REQUIRE(PayrollData::kOvertimeRate == 1.5);
}

//***************************Default Constructor*************************
TEST_CASE(
    "Default constructor sets hours to 0, pay type to 'h',pay rate to "
    "7.25, first name to 'it is', last name to 'unknown'",
    "[start]") {
  PayrollData payroll_data;
  REQUIRE(fabs(payroll_data.hours() - 0) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

//***************************Other constructor*************************
TEST_CASE(
    "Other constructor sets values as expected when called with "
    "34,'h',12.54,'Peters, Walter' ",
    "[start]") {
  PayrollData payroll_data(34, 'h', 12.54, "Peters, Walter");
  REQUIRE(fabs(payroll_data.hours() - 34) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 12.54) < .0001);
  REQUIRE(payroll_data.first_name() == "Walter");
  REQUIRE(payroll_data.last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with negative "
    "hours",
    "[start]") {
  REQUIRE_THROWS_AS(PayrollData(-34, 'h', 12.54, "Peters, Walter"),
                    out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with hours "
    "greater than 168",
    "[start]") {
  REQUIRE_THROWS_AS(PayrollData(174, 'h', 12.54, "Peters, Walter"),
                    out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with invalid "
    "pay type",
    "[start]") {
  REQUIRE_THROWS_AS(PayrollData(63, 'z', 12.54, "Peters, Walter"),
                    out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with pay rate "
    "less than 7.25",
    "[start]") {
  REQUIRE_THROWS_AS(PayrollData(63, 'h', 7.24, "Peters, Walter"), out_of_range);
}

//***************************getters*************************
TEST_CASE("Getters return expected values", "[start]") {
  PayrollData payroll_data(47, 's', 2571, "Johnson, Terry");
  REQUIRE(fabs(payroll_data.hours() - 47) < .0001);
  REQUIRE(payroll_data.pay_type() == 's');
  REQUIRE(fabs(payroll_data.pay_rate() - 2571) < .0001);
  REQUIRE(payroll_data.first_name() == "Terry");
  REQUIRE(payroll_data.last_name() == "Johnson");
  REQUIRE(payroll_data.name() == "Terry Johnson");
  REQUIRE(payroll_data.name_last_first() == "Johnson, Terry");
}

//***************************set hours*************************
TEST_CASE("Hours setter sets hours to 0", "[start]") {
  PayrollData payroll_data;
  payroll_data.set_hours(0);
  REQUIRE(fabs(payroll_data.hours() - 0) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 168", "[start]") {
  PayrollData payroll_data;
  payroll_data.set_hours(168);
  REQUIRE(fabs(payroll_data.hours() - 168) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 54", "[start]") {
  PayrollData payroll_data;
  payroll_data.set_hours(54);
  REQUIRE(fabs(payroll_data.hours() - 54) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 22.3", "[start]") {
  PayrollData payroll_data;
  payroll_data.set_hours(22.3);
  REQUIRE(fabs(payroll_data.hours() - 22.3) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

TEST_CASE(
    "Hours setter throws out of bounds exception when set to negative number",
    "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_hours(-1), out_of_range);
}

TEST_CASE(
    "Hours setter throws out of bounds exception when set to number greater "
    "than 168",
    "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_hours(169), out_of_range);
}

TEST_CASE("Hours setter throws out of bounds exception when set to 168.1",
          "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_hours(168.1), out_of_range);
}

//***************************set pay type*************************

TEST_CASE("Pay type setter sets pay type to 's'", "[start]") {
  PayrollData payroll_data;
  payroll_data.set_pay_type('s');
  REQUIRE(fabs(payroll_data.hours() - 0) < .0001);
  REQUIRE(payroll_data.pay_type() == 's');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

TEST_CASE("Pay type setter sets pay type to 'h'", "[start]") {
  PayrollData payroll_data(18, 's', 837, "Walters, Kerry");
  payroll_data.set_pay_type('h');
  REQUIRE(fabs(payroll_data.hours() - 18) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 837) < .0001);
  REQUIRE(payroll_data.first_name() == "Kerry");
  REQUIRE(payroll_data.last_name() == "Walters");
}

TEST_CASE("Pay type setter throws out of bounds exception when set to 'g'",
          "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_pay_type('g'), out_of_range);
}

TEST_CASE("Pay type setter throws out of bounds exception when set to '2'",
          "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_pay_type('2'), out_of_range);
}

TEST_CASE("Pay type setter throws out of bounds exception when set to 'w'",
          "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_pay_type('w'), out_of_range);
}

//***************************set pay rate*************************

TEST_CASE("Pay rate setter sets pay rate to 1237.2", "[start]") {
  PayrollData payroll_data(18, 's', 837, "Walters, Kerry");
  payroll_data.set_pay_rate(1237.2);
  REQUIRE(fabs(payroll_data.hours() - 18) < .0001);
  REQUIRE(payroll_data.pay_type() == 's');
  REQUIRE(fabs(payroll_data.pay_rate() - 1237.2) < .0001);
  REQUIRE(payroll_data.first_name() == "Kerry");
  REQUIRE(payroll_data.last_name() == "Walters");
}

TEST_CASE("Pay rate setter sets pay rate to 8.12", "[start]") {
  PayrollData payroll_data(18, 's', 837, "Walters, Kerry");
  payroll_data.set_pay_rate(8.12);
  REQUIRE(fabs(payroll_data.hours() - 18) < .0001);
  REQUIRE(payroll_data.pay_type() == 's');
  REQUIRE(fabs(payroll_data.pay_rate() - 8.12) < .0001);
  REQUIRE(payroll_data.first_name() == "Kerry");
  REQUIRE(payroll_data.last_name() == "Walters");
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to 7.01",
          "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_pay_rate(7.01), out_of_range);
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to -7.01",
          "[start]") {
  PayrollData payroll_data;
  REQUIRE_THROWS_AS(payroll_data.set_pay_rate(-7.01), out_of_range);
}

TEST_CASE("Name setter sets name to Kelly Walters", "[start]") {
  PayrollData payroll_data;
  payroll_data.set_pay_type('s');
  REQUIRE(fabs(payroll_data.hours() - 0) < .0001);
  REQUIRE(payroll_data.pay_type() == 's');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "it is");
  REQUIRE(payroll_data.last_name() == "unknown");
}

//***************************set name*************************

TEST_CASE("Name setter sets name to Kelly Walters when sent Kelly Walters",
          "[start]") {
  PayrollData payroll_data;
  payroll_data.set_name("Kelly Walters");
  REQUIRE(fabs(payroll_data.hours() - 0) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "Kelly");
  REQUIRE(payroll_data.last_name() == "Walters");
}

TEST_CASE("Name setter sets name to Kelly Walters when sent Walters, Kelly ",
          "[start]") {
  PayrollData payroll_data;
  payroll_data.set_name("Walters, Kelly");
  REQUIRE(fabs(payroll_data.hours() - 0) < .0001);
  REQUIRE(payroll_data.pay_type() == 'h');
  REQUIRE(fabs(payroll_data.pay_rate() - 7.25) < .0001);
  REQUIRE(payroll_data.first_name() == "Kelly");
  REQUIRE(payroll_data.last_name() == "Walters");
}

//***************************ComputeGross*************************

TEST_CASE(
    "ComputeGross returns 752 when hours is 32, pay type is h, and pay is "
    "23.5",
    "[gross]") {
  PayrollData payroll_data(32, 'h', 23.5, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 752) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1010.5 when hours is 42, pay type is h, and pay is "
    "23.5",
    "[gross]") {
  PayrollData payroll_data(42, 'h', 23.5, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 1010.5) < .0001);
}

TEST_CASE(
    "ComputeGross returns 0 when hours is 0, pay type is h, and pay is "
    "23.5",
    "[gross]") {
  PayrollData payroll_data(0, 'h', 23.5, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 0) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2324.4 when hours is 63, pay type is h, and pay is "
    "31.2",
    "[gross]") {
  PayrollData payroll_data(63, 'h', 31.2, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 2324.4) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2382 when hours is 48, pay type is s, and pay is "
    "2382",
    "[gross]") {
  PayrollData payroll_data(48, 's', 2382, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 2382) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1279 when hours is 26, pay type is s, and pay is "
    "1279",
    "[gross]") {
  PayrollData payroll_data(26, 's', 1279, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 1279) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1279 when hours is 0, pay type is s, and pay is "
    "1279",
    "[gross]") {
  PayrollData payroll_data(0, 's', 1279, "Kim Johnson");

  REQUIRE(fabs(payroll_data.ComputeGross() - 1279) < .0001);
}

//***************************WriteData*************************

TEST_CASE(
    "WriteData writes data as expected when hours is 0, pay type is s, and "
    "pay is 1279",
    "[write_data]") {
  PayrollData payroll_data(0, 's', 1279, "Kim Johnson");
  ofstream out("test.out");
  payroll_data.WriteData(out);
  out.close();
  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "0 s 1279");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when hours is 43, pay type is h, and "
    "pay is 14.92",
    "[write_data]") {
  PayrollData payroll_data(43, 'h', 14.92, "Kim Johnson");
  ofstream out("test.out");
  payroll_data.WriteData(out);
  out.close();
  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "43 h 14.92");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when multiple PayrollData is written",
    "[write_data]") {
  PayrollData payroll_data(0, 's', 1279, "Johnson, Kim");
  PayrollData payroll_data2(43, 'h', 14.92, "Kim Johnson");
  ofstream out("test.out");
  payroll_data.WriteData(out);
  payroll_data2.WriteData(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "0 s 1279");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "43 h 14.92");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

//***************************PayrollReport*************************

TEST_CASE(
    "PayrollReport prints expected report when hours is 35, pay type is h, and "
    "pay is 17.5",
    "[write_data]") {
  ofstream out("test.out");

  PayrollData payroll_data(35, 'h', 17.5, "John Jones");
  payroll_data.PayrollReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 35.00");
  getline(in, line);
  REQUIRE(line == "Pay Type: hourly");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $17.50");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $612.50");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when hours is 72.3, pay type is s,"
    " and pay is 1722.6",
    "[write_data]") {
  ofstream out("test.out");

  PayrollData payroll_data(72.3, 's', 1722.6, "Jones, John");
  payroll_data.PayrollReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 72.30");
  getline(in, line);
  REQUIRE(line == "Pay Type: salary");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $1722.60");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $1722.60");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when multiple reports are written",
    "[write_data]") {
  ofstream out("test.out");

  PayrollData payroll_data(72.3, 's', 1722.6, "Jones, John");
  PayrollData payroll_data2(35, 'h', 17.5, "John Jones");
  payroll_data.PayrollReport(out);
  payroll_data2.PayrollReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 72.30");
  getline(in, line);
  REQUIRE(line == "Pay Type: salary");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $1722.60");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $1722.60");
  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 35.00");
  getline(in, line);
  REQUIRE(line == "Pay Type: hourly");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $17.50");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $612.50");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}
