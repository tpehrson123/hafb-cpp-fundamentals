// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <array>
#include <cmath>
#include "carton.h"
#include "min_array.h"

using namespace std;

//******************************integers******************************
TEST_CASE(
    "MinInArray function returns 3 when called with an int array with minimum "
    "value "
    "of 3 in middle of array",
    "[int]") {
  array<int, kMaxSize> integers = {45, 63, 17, 22, 99, 71, 54, 87,
                                   23, 51, 3,  19, 13, 5,  7};

  REQUIRE(MinInArray(integers, 15) == 3);
}

TEST_CASE(
    "MinInArray function returns 3 when called with an int array with minimum "
    "value "
    "of 3 is first value in array",
    "[int]") {
  array<int, kMaxSize> integers = {3,  63, 17, 22, 99, 71, 54, 87,
                                   23, 51, 45, 19, 13, 5,  7};

  REQUIRE(MinInArray(integers, 15) == 3);
}

TEST_CASE(
    "MinInArray function returns 3 when called with an int array with minimum "
    "value "
    "of 3 is last value in array",
    "[int]") {
  array<int, kMaxSize> integers = {83, 63, 17, 22, 99, 71, 54, 87,
                                   23, 51, 45, 19, 13, 5,  3};

  REQUIRE(MinInArray(integers, 15) == 3);
}

//******************************doubles******************************

TEST_CASE(
    "MinInArray function returns 42.89 when called with a double array with "
    "minimum value of 42.89 in middle of array",
    "[double]") {
  array<double, kMaxSize> doubles = {71.3,   129.5,  139.7,  382.2,
                                     91.93,  66.724, 88.382, 42.89,
                                     276.54, 301.47, 218.56, 274.87};

  REQUIRE(fabs(MinInArray(doubles, 12) - 42.89) < .001);
}

TEST_CASE(
    "MinInArray function returns 42.89 when called with a double array with "
    "minimum value of 42.89 is first value in array",
    "[double]") {
  array<double, kMaxSize> doubles = {42.89,  129.5,  139.7,  382.2,
                                     91.93,  66.724, 88.382, 71.3,
                                     276.54, 301.47, 218.56, 274.87};

  REQUIRE(fabs(MinInArray(doubles, 12) - 42.89) < .001);
}

TEST_CASE(
    "MinInArray function returns 42.89 when called with a double array with "
    "minimum value of 42.89 is last value in array",
    "[double]") {
  array<double, kMaxSize> doubles = {71.3,   129.5,  139.7,  382.2,
                                     91.93,  66.724, 88.382, 274.87,
                                     276.54, 301.47, 218.56, 42.89};

  REQUIRE(fabs(MinInArray(doubles, 12) - 42.89) < .001);
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
    "MinInArray function returns Carton(6, 8, 14) when called with a Carton "
    "array with "
    "minimum value of Carton(6, 8, 14) is first value in array",
    "[carton]") {
  array<Carton, kMaxSize> cartons = {Carton(6, 8, 14),   Carton(7, 24, 13),
                                     Carton(12, 14, 22), Carton(16, 12.8, 13),
                                     Carton(15, 8, 12),  Carton(9, 13, 21)};

  REQUIRE(fabs(MinInArray(cartons, 6).Volume() - 672) < .001);
}

TEST_CASE(
    "MinInArray function returns Carton(6, 8, 14) when called with a Carton "
    "array with "
    "minimum value of Carton(6, 8, 14) is in the middle of the array",
    "[carton]") {
  array<Carton, kMaxSize> cartons = {Carton(7, 24, 13),    Carton(12, 14, 22),
                                     Carton(16, 12.8, 13), Carton(6, 8, 14),
                                     Carton(15, 8, 12),    Carton(9, 13, 21)};

  REQUIRE(fabs(MinInArray(cartons, 6).Volume() - 672) < .001);
}

TEST_CASE(
    "MinInArray function returns Carton(6, 8, 14) when called with a Carton "
    "array with "
    "minimum value of Carton(6, 8, 14) is last value in array",
    "[carton]") {
  array<Carton, kMaxSize> cartons = {Carton(7, 24, 13),    Carton(12, 14, 22),
                                     Carton(16, 12.8, 13), Carton(15, 8, 12),
                                     Carton(9, 13, 21),    Carton(6, 8, 14)};

  REQUIRE(fabs(MinInArray(cartons, 6).Volume() - 672) < .001);
}
