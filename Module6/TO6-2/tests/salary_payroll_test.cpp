#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "salary_payroll.h"

//***************************Default Constructor*************************
TEST_CASE(
    "Default constructor sets pay rate to 0, first name to "
    "'it is', and last name to 'unknown'",
    "[start]") {
  SalaryPayroll salary;
  REQUIRE(fabs(salary.pay_rate() - 0) < .0001);
  REQUIRE(salary.first_name() == "it is");
  REQUIRE(salary.last_name() == "unknown");
}

//***************************Other constructor*************************
TEST_CASE(
    "Other constructor sets values as expected when called with "
    "'1254.8, 'Peters, Walter' ",
    "[start]") {
  SalaryPayroll salary(1254.8, "Peters, Walter");
  REQUIRE(fabs(salary.pay_rate() - 1254.8) < .0001);
  REQUIRE(salary.first_name() == "Walter");
  REQUIRE(salary.last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with pay rate "
    "less than 0",
    "[start]") {
  REQUIRE_THROWS_AS(SalaryPayroll(-34.2, "Peters, Walter"), std::out_of_range);
}

//***************************getters*************************
TEST_CASE("Getters return expected values for the SalaryPayroll", "[start]") {
  SalaryPayroll salary(2571, "Johnson, Terry");
  REQUIRE(fabs(salary.pay_rate() - 2571) < .0001);
  REQUIRE(salary.first_name() == "Terry");
  REQUIRE(salary.last_name() == "Johnson");
  REQUIRE(salary.name() == "Terry Johnson");
  REQUIRE(salary.name_last_first() == "Johnson, Terry");
}

//***************************set pay rate*************************

TEST_CASE("Pay rate setter sets pay rate to 8125", "[start]") {
  SalaryPayroll salary(1450, "Walters, Kerry");
  salary.set_pay_rate(8125);
  REQUIRE(fabs(salary.pay_rate() - 8125) < .0001);
  REQUIRE(salary.first_name() == "Kerry");
  REQUIRE(salary.last_name() == "Walters");
}

TEST_CASE("Pay rate setter sets pay rate to 7.23", "[start]") {
  SalaryPayroll salary(1450, "Walters, Kerry");
  salary.set_pay_rate(7.23);
  REQUIRE(fabs(salary.pay_rate() - 7.23) < .0001);
  REQUIRE(salary.first_name() == "Kerry");
  REQUIRE(salary.last_name() == "Walters");
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to -1.02",
          "[start]") {
  SalaryPayroll salary;
  REQUIRE_THROWS_AS(salary.set_pay_rate(-1.02), std::out_of_range);
}

//***************************set name*************************

TEST_CASE("Name setter sets name to Kelly Walter when sent Kelly Walter",
          "[start]") {
  SalaryPayroll salary;
  salary.set_name("Kelly Walter");
  REQUIRE(fabs(salary.pay_rate() - 0) < .0001);
  REQUIRE(salary.first_name() == "Kelly");
  REQUIRE(salary.last_name() == "Walter");
}

TEST_CASE("Name setter sets name to Kelly Walter when sent Walter, Kelly ",
          "[start]") {
  SalaryPayroll salary;
  salary.set_name("Walter, Kelly");
  REQUIRE(fabs(salary.pay_rate() - 0) < .0001);
  REQUIRE(salary.first_name() == "Kelly");
  REQUIRE(salary.last_name() == "Walter");
}

//***************************ComputeGross*************************

TEST_CASE("ComputeGross returns 752 when hours is 32 and pay rate is 752",
          "[gross]") {
  SalaryPayroll salary(752, "Kim Johnson");

  REQUIRE(fabs(salary.ComputeGross() - 752) < .0001);
}

TEST_CASE("ComputeGross returns 2356.4 when pay rate is 2356.4", "[gross]") {
  SalaryPayroll salary(2356.4, "Kim Johnson");

  REQUIRE(fabs(salary.ComputeGross() - 2356.4) < .0001);
}

TEST_CASE("ComputeGross returns 0 when pay rate is 0", "[gross]") {
  SalaryPayroll salary(0, "Kim Johnson");

  REQUIRE(fabs(salary.ComputeGross() - 0) < .0001);
}

//***************************WriteData*************************

TEST_CASE(
    "WriteData writes data as expected when "
    "pay rate is 1492",
    "[write_data]") {
  SalaryPayroll salary(1492, "Kim Johnson");
  std::ofstream out("test.out");
  salary.WriteData(out);
  out.close();
  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;
  getline(in, line);
  REQUIRE(line == "S 1492");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when multiple SalaryPayroll is written",
    "[write_data]") {
  SalaryPayroll salary1(1279.2, "Johnson, Kim");
  SalaryPayroll salary2(1492, "Kim Johnson");
  std::ofstream out("test.out");
  salary1.WriteData(out);
  salary2.WriteData(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;
  getline(in, line);
  REQUIRE(line == "S 1279.2");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "S 1492");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

//***************************PayrollReport*************************

TEST_CASE("PayrollReport prints expected report when pay rate is 3175.3",
          "[write_data]") {
  std::ofstream out("test.out");

  SalaryPayroll salary(3175.3, "John Jones");
  salary.PayrollReport(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: salary");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $3175.30");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $3175.30");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE("PayrollReport prints expected report when pay rate is 1370.6",
          "[write_data]") {
  std::ofstream out("test.out");

  SalaryPayroll salary(1370.6, "Jones, John");
  salary.PayrollReport(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: salary");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $1370.60");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $1370.60");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when multiple SalaryPayroll reports "
    "are written",
    "[write_data]") {
  std::ofstream out("test.out");

  SalaryPayroll salary1(1279.2, "Johnson, Kim");
  SalaryPayroll salary2(1492, "John Jones");
  salary1.PayrollReport(out);
  salary2.PayrollReport(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "Kim Johnson");
  getline(in, line);
  REQUIRE(line == "Pay Type: salary");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $1279.20");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $1279.20");
  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: salary");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $1492.00");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $1492.00");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}
