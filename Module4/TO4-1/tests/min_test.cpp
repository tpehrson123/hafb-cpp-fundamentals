// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <array>
#include <cmath>
#include "carton.h"
#include "min.h"

using namespace std;

//******************************integers******************************
TEST_CASE(
    "MyMin function returns 321 when called with int variables with values 473 "
    "and 321",
    "[int]") {
  int int1 = 473, int2 = 321;
  MyMin(int1, int2);
  REQUIRE(MyMin(int1, int2) == 321);
  REQUIRE(MyMin(int2, int1) == 321);
}

//******************************doubles******************************

TEST_CASE(
    "MyMin function returns 123.82 when called with double variables with "
    "values 123.82 and 263.79",
    "[double]") {
  double double1 = 123.82, double2 = 263.79;
  MyMin(double1, double2);
  REQUIRE(fabs(MyMin(double1, double2) - 123.82) < .001);
  REQUIRE(fabs(MyMin(double2, double1) - 123.82) < .001);
}

//******************************Cartons******************************

TEST_CASE(
    "Operator < returns true when called with "
    "Carton(5.6, 12.4, 3.7) < Carton(7.8, 13.2, 5.9) and false when called with"
    "Carton(7.8, 13.2, 5.9) < Carton(5.6, 12.4, 3.7)",
    "[less_than]") {
  Carton carton1(5.6, 12.4, 3.7);
  Carton carton2(7.8, 13.2, 5.9);
  REQUIRE(carton1 < carton2);
  REQUIRE(!(carton2 < carton1));
}

TEST_CASE(
    "MyMin function returns Carton(6.2, 12, 7.7) when called with "
    "Carton variables with values "
    "Carton(6.2, 12, 7.7) and Carton(7.3, 16.2, 9.8)",
    "[carton]") {
  Carton carton1(6.2, 12, 7.7);
  Carton carton2(7.3, 16.2, 9.8);
  REQUIRE(fabs(MyMin(carton1, carton2).Volume() - 572.88) < .001);
  REQUIRE(fabs(MyMin(carton1, carton2).Volume() - 572.88) < .001);
}
