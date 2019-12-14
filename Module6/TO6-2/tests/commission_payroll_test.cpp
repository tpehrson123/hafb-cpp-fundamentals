#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "commission_payroll.h"

//***************************Default Constructor*************************
TEST_CASE(
    "Default constructor sets pay rate to 0, how many to 0, base pay to 0, "
    "first name to "
    "'it is', and last name to 'unknown'",
    "[start]") {
  CommissionPayroll commission;
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 0);
  REQUIRE(fabs(commission.base_pay() - 0) < .0001);
  REQUIRE(commission.first_name() == "it is");
  REQUIRE(commission.last_name() == "unknown");
}

//***************************Other constructor*************************
TEST_CASE(
    "Other constructor sets values as expected when called with "
    "'250, 6, 520, 'Peters, Walter' ",
    "[start]") {
  CommissionPayroll commission(250, 6, 520, "Peters, Walter");
  REQUIRE(fabs(commission.pay_rate() - 250) < .0001);
  REQUIRE(commission.how_many() == 6);
  REQUIRE(fabs(commission.base_pay() - 520) < .0001);
  REQUIRE(commission.first_name() == "Walter");
  REQUIRE(commission.last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with pay rate "
    "less than 0 for CommissionPayroll",
    "[start]") {
  REQUIRE_THROWS_AS(CommissionPayroll(-1, 6, 520, "Peters, Walter"),
                    std::out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with how many "
    "less than 0",
    "[start]") {
  REQUIRE_THROWS_AS(CommissionPayroll(250, -6, 520, "Peters, Walter"),
                    std::out_of_range);
}

TEST_CASE(
    "Other constructor throws out of range exception when called with base pay "
    "less than 0",
    "[start]") {
  REQUIRE_THROWS_AS(CommissionPayroll(250, 6, -1, "Peters, Walter"),
                    std::out_of_range);
}

//***************************getters*************************
TEST_CASE("Getters return expected values for the CommissionPayroll",
          "[start]") {
  CommissionPayroll commission(250, 6, 520, "Peters, Walter");
  REQUIRE(fabs(commission.pay_rate() - 250) < .0001);
  REQUIRE(commission.how_many() == 6);
  REQUIRE(fabs(commission.base_pay() - 520) < .0001);
  REQUIRE(commission.first_name() == "Walter");
  REQUIRE(commission.last_name() == "Peters");
}

//***************************set pay rate*************************

TEST_CASE("Pay rate setter sets pay rate to 750", "[start]") {
  CommissionPayroll commission(1450.0, 1, 324.6, "Walters, Kerry");
  commission.set_pay_rate(750);
  REQUIRE(fabs(commission.pay_rate() - 750) < .0001);
  REQUIRE(commission.how_many() == 1);
  REQUIRE(fabs(commission.base_pay() - 324.6) < .0001);
  REQUIRE(commission.first_name() == "Kerry");
  REQUIRE(commission.last_name() == "Walters");
}

TEST_CASE("Pay rate setter sets pay rate to 12.5", "[start]") {
  CommissionPayroll commission(1450, 42, 0, "Walters, Kerry");
  commission.set_pay_rate(12.5);
  REQUIRE(fabs(commission.pay_rate() - 12.5) < .0001);
  REQUIRE(commission.how_many() == 42);
  REQUIRE(fabs(commission.base_pay() - 0) < .0001);
  REQUIRE(commission.first_name() == "Kerry");
  REQUIRE(commission.last_name() == "Walters");
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to -1",
          "[start]") {
  CommissionPayroll commission;
  REQUIRE_THROWS_AS(commission.set_pay_rate(-1), std::out_of_range);
}

//***************************set how many*************************

TEST_CASE("How many setter sets how many to 12 when sent 12", "[start]") {
  CommissionPayroll commission;
  commission.set_how_many(12);
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 12);
  REQUIRE(fabs(commission.base_pay() - 0) < .0001);
  REQUIRE(commission.first_name() == "it is");
  REQUIRE(commission.last_name() == "unknown");
}

TEST_CASE("How many setter sets how many to 351 when sent 351", "[start]") {
  CommissionPayroll commission;
  commission.set_how_many(351);
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 351);
  REQUIRE(fabs(commission.base_pay() - 0) < .0001);
  REQUIRE(commission.first_name() == "it is");
  REQUIRE(commission.last_name() == "unknown");
}

TEST_CASE("How many setter throws out of bounds exception when set to -1",
          "[start]") {
  CommissionPayroll commission;
  REQUIRE_THROWS_AS(commission.set_how_many(-1), std::out_of_range);
}

//***************************set base pay*************************

TEST_CASE("Base pay setter sets base pay to 65 when sent 65", "[start]") {
  CommissionPayroll commission;
  commission.set_base_pay(65);
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 0);
  REQUIRE(fabs(commission.base_pay() - 65) < .0001);
  REQUIRE(commission.first_name() == "it is");
  REQUIRE(commission.last_name() == "unknown");
}

TEST_CASE("Base pay setter sets base pay to 1250 when sent 1250", "[start]") {
  CommissionPayroll commission;
  commission.set_base_pay(1250);
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 0);
  REQUIRE(fabs(commission.base_pay() - 1250) < .0001);
  REQUIRE(commission.first_name() == "it is");
  REQUIRE(commission.last_name() == "unknown");
}

TEST_CASE("Base pay setter throws out of bounds exception when set to -1",
          "[start]") {
  CommissionPayroll commission;
  REQUIRE_THROWS_AS(commission.set_base_pay(-1), std::out_of_range);
}

//***************************set name*************************

TEST_CASE("Name setter sets name to Kim Walter when sent Kim Walter",
          "[start]") {
  CommissionPayroll commission;
  commission.set_name("Kim Walter");
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 0);
  REQUIRE(fabs(commission.base_pay() - 0) < .0001);
  REQUIRE(commission.first_name() == "Kim");
  REQUIRE(commission.last_name() == "Walter");
}

TEST_CASE("Name setter sets name to Kim Walter when sent Walter, Kim ",
          "[start]") {
  CommissionPayroll commission;
  commission.set_name("Walter, Kim");
  REQUIRE(fabs(commission.pay_rate() - 0) < .0001);
  REQUIRE(commission.how_many() == 0);
  REQUIRE(fabs(commission.base_pay() - 0) < .0001);
  REQUIRE(commission.first_name() == "Kim");
  REQUIRE(commission.last_name() == "Walter");
}

//***************************ComputeCommission*************************

TEST_CASE(
    "ComputeCommission returns 752 when how many is 3, pay rate is 752, and "
    "base "
    "pay is 1250.",
    "[gross]") {
  CommissionPayroll commission(752, 3, 1250, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeCommission() - 2256) < .0001);
}

TEST_CASE(
    "ComputeCommission returns 1107.25 when values sent are 7.35, 35, 850, "
    "'Kim "
    "Johnson'",
    "[gross]") {
  CommissionPayroll commission(7.35, 35, 850, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeCommission() - 257.25) < .0001);
}

TEST_CASE(
    "ComputeCommission returns 0 when values sent are 752, 0, 0, 'Kim Johnson'",
    "[gross]") {
  CommissionPayroll commission(752, 0, 0, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeCommission() - 0) < .0001);
}

TEST_CASE(
    "ComputeCommission returns 0 when values sent are 0, 1200, 0, 'Kim "
    "Johnson'",
    "[gross]") {
  CommissionPayroll commission(0, 1200, 0, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeCommission() - 0) < .0001);
}

TEST_CASE(
    "ComputeCommission returns 850 when values sent are 0, 1200, 0, 'Kim "
    "Johnson'",
    "[gross]") {
  CommissionPayroll commission(0, 1200, 0, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeCommission() - 0) < .0001);
}

//***************************ComputeGross*************************

TEST_CASE(
    "ComputeGross returns 752 when how many is 3, pay rate is 752, and base "
    "pay is 1250.",
    "[gross]") {
  CommissionPayroll commission(752, 3, 1250, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeGross() - 3506) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1107.25 when values sent are 7.35, 35, 850, 'Kim "
    "Johnson'",
    "[gross]") {
  CommissionPayroll commission(7.35, 35, 850, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeGross() - 1107.25) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1250 when values sent are 752, 0, 1250, 'Kim "
    "Johnson'",
    "[gross]") {
  CommissionPayroll commission(752, 0, 1250, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeGross() - 1250) < .0001);
}

TEST_CASE(
    "ComputeGross returns 0 when values sent are 752, 0, 0, 'Kim Johnson'",
    "[gross]") {
  CommissionPayroll commission(752, 0, 0, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeGross() - 0) < .0001);
}

TEST_CASE(
    "ComputeGross returns 0 when values sent are 0, 1200, 0, 'Kim Johnson'",
    "[gross]") {
  CommissionPayroll commission(0, 1200, 0, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeGross() - 0) < .0001);
}

TEST_CASE(
    "ComputeGross returns 850 when values sent are 0, 1200, 850, 'Kim Johnson'",
    "[gross]") {
  CommissionPayroll commission(0, 1200, 850, "Kim Johnson");

  REQUIRE(fabs(commission.ComputeGross() - 850) < .0001);
}
//***************************WriteData*************************

TEST_CASE(
    "WriteData writes data as expected when "
    "pay rate is 14.92, how many is 61, and base pay is 455.8",
    "[write_data]") {
  CommissionPayroll commission(14.92, 61, 455.80, "Kim Johnson");
  std::ofstream out("test.out");
  commission.WriteData(out);
  out.close();
  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;
  getline(in, line);
  REQUIRE(line == "C 14.92 61 455.8");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when two CommissionPayroll objects are "
    "output.",
    "[write_data]") {
  CommissionPayroll commission1(63, 28, 975.6, "Johnson, Kim");
  CommissionPayroll commission2(14.92, 61, 455.80, "Kim Johnson");
  std::ofstream out("test.out");
  commission1.WriteData(out);
  commission2.WriteData(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;
  getline(in, line);
  REQUIRE(line == "C 63 28 975.6");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "C 14.92 61 455.8");
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
    "PayrollReport prints expected report when pay rate is 12.2, how many is "
    "180, and base pay is 1175.3",
    "[write_data]") {
  std::ofstream out("test.out");

  CommissionPayroll commission(12.2, 180, 1175.3, "John Jones");
  commission.PayrollReport(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: commission");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $12.20");
  getline(in, line);
  REQUIRE(line == "How Many: 180");
  getline(in, line);
  REQUIRE(line == "Commission: $2196.00");
  getline(in, line);
  REQUIRE(line == "Base Pay: $1175.30");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $3371.30");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when values are 63, 28, 975.6, "
    "'Johnson, Kim'",
    "[write_data]") {
  std::ofstream out("test.out");

  CommissionPayroll commission(63, 28, 975.6, "Johnson, Kim");
  commission.PayrollReport(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "Kim Johnson");
  getline(in, line);
  REQUIRE(line == "Pay Type: commission");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $63.00");
  getline(in, line);
  REQUIRE(line == "How Many: 28");
  getline(in, line);
  REQUIRE(line == "Commission: $1764.00");
  getline(in, line);
  REQUIRE(line == "Base Pay: $975.60");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $2739.60");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "PayrollReport prints expected report when multiple CommissionPayroll "
    "reports "
    "are output",
    "[write_data]") {
  std::ofstream out("test.out");

  CommissionPayroll commission1(63, 28, 975.6, "Johnson, Kim");
  CommissionPayroll commission2(14.92, 61, 455.80, "John Jones");
  commission1.PayrollReport(out);
  commission2.PayrollReport(out);
  out.close();

  std::ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "Kim Johnson");
  getline(in, line);
  REQUIRE(line == "Pay Type: commission");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $63.00");
  getline(in, line);
  REQUIRE(line == "How Many: 28");
  getline(in, line);
  REQUIRE(line == "Commission: $1764.00");
  getline(in, line);
  REQUIRE(line == "Base Pay: $975.60");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $2739.60");
  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "Pay Type: commission");
  getline(in, line);
  REQUIRE(line == "Pay Rate: $14.92");
  getline(in, line);
  REQUIRE(line == "How Many: 61");
  getline(in, line);
  REQUIRE(line == "Commission: $910.12");
  getline(in, line);
  REQUIRE(line == "Base Pay: $455.80");
  getline(in, line);
  REQUIRE(line == "Gross Pay: $1365.92");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}
