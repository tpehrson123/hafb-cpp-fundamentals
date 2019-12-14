// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <iostream>
#include "hourly_payroll.h"

using namespace std;

//***************************kRegularHours*************************
TEST_CASE("Consant kRegularHours is defined and set to 40", "[start]") {
  REQUIRE(HourlyPayroll::kRegularHours == 40);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kOvertimeRate is defined and set to 1.5", "[start]") {
  REQUIRE(HourlyPayroll::kOvertimeRate == 1.5);
}

//***************************kRegularHours*************************
TEST_CASE("Consant kMinHours is defined and set to 0", "[start]") {
  REQUIRE(HourlyPayroll::kMinHours == 0);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kMaxHours is defined and set to 168", "[start]") {
  REQUIRE(HourlyPayroll::kMaxHours == 168);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kMinWage is defined and set to 7.25", "[start]") {
  REQUIRE(HourlyPayroll::kMinWage == 7.25);
}

//***************************Default Constructor*************************
TEST_CASE(
    "Default constructor sets pay rate to kMinWage, first name to "
    "'it is', last name to 'unknown', and hours worked to 0",
    "[start]") {
  HourlyPayroll hourly;
  REQUIRE(fabs(hourly.hours() - 0) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "it is");
  REQUIRE(hourly.last_name() == "unknown");
}

//***************************Other constructor*************************
TEST_CASE(
    "Other constructor sets values as expected when called with "
    "'12.54, 34, 'Peters, Walter' ",
    "[start]") {
  HourlyPayroll hourly(12.54, 34, "Peters, Walter");
  REQUIRE(fabs(hourly.hours() - 34) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - 12.54) < .0001);
  REQUIRE(hourly.first_name() == "Walter");
  REQUIRE(hourly.last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with negative "
    "hours",
    "[start]") {
  REQUIRE_THROWS_AS(HourlyPayroll(12.54, -34, "Peters, Walter"), out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with hours "
    "greater than 168",
    "[start]") {
  REQUIRE_THROWS_AS(HourlyPayroll(12.54, 169, "Peters, Walter"), out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with pay rate "
    "less than 7.25",
    "[start]") {
  double low_wage = HourlyPayroll::kMinWage - .02;
  REQUIRE_THROWS_AS(HourlyPayroll(low_wage, 34, "Peters, Walter"),
                    out_of_range);
}

//***************************getters*************************
TEST_CASE("Getters return expected values", "[start]") {
  HourlyPayroll hourly(25.71, 47, "Johnson, Terry");
  REQUIRE(fabs(hourly.hours() - 47) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - 25.71) < .0001);
  REQUIRE(hourly.first_name() == "Terry");
  REQUIRE(hourly.last_name() == "Johnson");
  REQUIRE(hourly.name() == "Terry Johnson");
  REQUIRE(hourly.name_last_first() == "Johnson, Terry");
}

//***************************set hours*************************
TEST_CASE("Hours setter sets hours to 0", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(0);
  REQUIRE(fabs(hourly.hours() - 0) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "it is");
  REQUIRE(hourly.last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 168", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(168);
  REQUIRE(fabs(hourly.hours() - 168) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "it is");
  REQUIRE(hourly.last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 54", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(54);
  REQUIRE(fabs(hourly.hours() - 54) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "it is");
  REQUIRE(hourly.last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 22.3", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(22.3);
  REQUIRE(fabs(hourly.hours() - 22.3) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "it is");
  REQUIRE(hourly.last_name() == "unknown");
}

TEST_CASE(
    "Hours setter throws out of bounds exception when set to negative number",
    "[start]") {
  HourlyPayroll hourly;
  REQUIRE_THROWS_AS(hourly.set_hours(-1), out_of_range);
}

TEST_CASE(
    "Hours setter throws out of bounds exception when set to number greater "
    "than 168",
    "[start]") {
  HourlyPayroll hourly;
  REQUIRE_THROWS_AS(hourly.set_hours(169), out_of_range);
}

TEST_CASE("Hours setter throws out of bounds exception when set to 168.1",
          "[start]") {
  HourlyPayroll hourly;
  REQUIRE_THROWS_AS(hourly.set_hours(168.1), out_of_range);
}

//***************************set pay rate*************************

TEST_CASE("Pay rate setter sets pay rate to 8.12", "[start]") {
  HourlyPayroll hourly(14.50, 18, "Walters, Kerry");
  hourly.set_pay_rate(8.12);
  REQUIRE(fabs(hourly.hours() - 18) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - 8.12) < .0001);
  REQUIRE(hourly.first_name() == "Kerry");
  REQUIRE(hourly.last_name() == "Walters");
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to 7.01",
          "[start]") {
  HourlyPayroll hourly;
  REQUIRE_THROWS_AS(hourly.set_pay_rate(7.01), out_of_range);
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to -7.01",
          "[start]") {
  HourlyPayroll hourly;
  REQUIRE_THROWS_AS(hourly.set_pay_rate(-7.01), out_of_range);
}

//***************************set name*************************

TEST_CASE("Name setter sets name to Kelly Walters when sent Kelly Walters",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_name("Kelly Walters");
  REQUIRE(fabs(hourly.hours() - 0) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "Kelly");
  REQUIRE(hourly.last_name() == "Walters");
}

TEST_CASE("Name setter sets name to Kelly Walters when sent Walters, Kelly ",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_name("Walters, Kelly");
  REQUIRE(fabs(hourly.hours() - 0) < .0001);
  REQUIRE(fabs(hourly.pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.first_name() == "Kelly");
  REQUIRE(hourly.last_name() == "Walters");
}

//***************************ComputeGross*************************

TEST_CASE(
    "ComputeGross returns 752 when hours is 32 and pay is "
    "23.5",
    "[gross]") {
  HourlyPayroll hourly(23.5, 32, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 752) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1010.5 when hours is 42 and pay is "
    "23.5",
    "[gross]") {
  HourlyPayroll hourly(23.5, 42, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 1010.5) < .0001);
}

TEST_CASE(
    "ComputeGross returns 0 when hours is 0 and pay is "
    "23.5",
    "[gross]") {
  HourlyPayroll hourly(23.5, 0, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 0) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2324.4 when hours is 63 and pay is "
    "31.2",
    "[gross]") {
  HourlyPayroll hourly(31.2, 63, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 2324.4) < .0001);
}

//***************************WriteData*************************

TEST_CASE(
    "WriteData writes data as expected when hours is 43 and "
    "pay is 14.92",
    "[write_data]") {
  HourlyPayroll hourly(14.92, 43, "Kim Johnson");
  ofstream out("test.out");
  hourly.WriteData(out);
  out.close();
  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "H 14.92 43");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when multiple HourlyPayroll is written",
    "[write_data]") {
  HourlyPayroll hourly1(12.79, 22, "Johnson, Kim");
  HourlyPayroll hourly2(14.92, 43, "Kim Johnson");
  ofstream out("test.out");
  hourly1.WriteData(out);
  hourly2.WriteData(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "H 12.79 22");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "H 14.92 43");
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
    "PayrollReport prints expected report when hours is 35 and "
    "pay is 17.5",
    "[write_data]") {
  ofstream out("test.out");

  HourlyPayroll hourly(17.5, 35, "John Jones");
  hourly.PayrollReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: hourly");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $17.50");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 35.00");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $612.50");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when hours is 72.3"
    " and pay rate is 37.6",
    "[write_data]") {
  ofstream out("test.out");

  HourlyPayroll hourly(37.6, 72.3, "Jones, John");
  hourly.PayrollReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: hourly");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $37.60");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 72.30");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $3325.72");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when multiple reports are written",
    "[write_data]") {
  ofstream out("test.out");

  HourlyPayroll hourly1(37.6, 72.3, "Jones, John");
  HourlyPayroll hourly2(17.5, 35, "John Jones");
  hourly1.PayrollReport(out);
  hourly2.PayrollReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: hourly");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $37.60");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 72.30");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $3325.72");
  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: hourly");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $17.50");
  getline(in, line);
  REQUIRE(line == "Hours Worked: 35.00");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $612.50");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}
