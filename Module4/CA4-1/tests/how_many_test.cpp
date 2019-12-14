// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <array>
#include <cmath>
#include "carton.h"
#include "how_many.h"

using namespace std;

//******************************integers******************************
TEST_CASE(
    "HowMany function returns 3 when called with an int array with three "
    "of the value 29.",
    "[int]") {
  array<int, kMaxSize> integers = {45, 63, 17, 29, 22, 99, 71, 54, 87,
                                   23, 51, 29, 3,  19, 29, 13, 5,  7};

  REQUIRE(HowMany(29, integers, 18) == 3);
}

TEST_CASE(
    "HowMany function returns 5 when called with an int array with five "
    "of the value 29.",
    "[int]") {
  array<int, kMaxSize> integers = {29, 45, 63, 17, 29, 22, 99, 71, 54, 87,
                                   23, 51, 29, 3,  19, 29, 13, 5,  7,  29};

  REQUIRE(HowMany(29, integers, 20) == 5);
}

TEST_CASE(
    "HowMany function returns 0 when called with an int that is not "
    "found in the array.",
    "[int]") {
  array<int, kMaxSize> integers = {29, 45, 63, 17, 29, 22, 99, 71, 54, 87,
                                   23, 51, 29, 3,  19, 29, 13, 5,  7,  29};

  REQUIRE(HowMany(39, integers, 20) == 0);
}

//******************************strings******************************

TEST_CASE(
    "HowMany function returns 8 when called with a string array with eight "
    "of the value gray.",
    "[string]") {
  array<string, kMaxSize> colors = {
      "gray",    "pink", "brown",  "gray",     "green",  "gray",
      "magenta", "gray", "yellow", "gray",     "purple", "gray",
      "gray",    "blue", "orange", "lavender", "black",  "gray"};
  int color_size = 18;
  string color = "gray";

  int how_many = HowMany(color, colors, color_size);

  REQUIRE(how_many == 8);
}

TEST_CASE(
    "HowMany function returns 6 when called with a string array with six "
    "of the value sent.",
    "[string]") {
  array<string, kMaxSize> colors = {"pink",   "brown",    "gray",  "green",
                                    "gray",   "magenta",  "gray",  "yellow",
                                    "purple", "gray",     "gray",  "blue",
                                    "orange", "lavender", "black", "gray"};
  int color_size = 16;
  string color = "gray";

  int how_many = HowMany(color, colors, color_size);

  REQUIRE(how_many == 6);
}

TEST_CASE(
    "HowMany function returns 0 when called with a string that is not "
    "found in the array.",
    "[string]") {
  array<string, kMaxSize> colors = {"pink",   "brown",    "gray",  "green",
                                    "gray",   "magenta",  "gray",  "yellow",
                                    "purple", "gray",     "gray",  "blue",
                                    "orange", "lavender", "black", "gray"};
  int color_size = 16;
  string color = "silver";

  int how_many = HowMany(color, colors, color_size);

  REQUIRE(how_many == 0);
}

//******************************Cartons******************************

TEST_CASE(
    "The == returns true when two Cartons have the same volume (within .1)"
    "and false otherwise",
    "[is_equal]") {
  // test size
  REQUIRE(Carton(22, 7, 19.3) == Carton(22, 7, 19.3));
  REQUIRE(Carton(22, 7, 19.3) == Carton(19.3, 22, 7));
  REQUIRE(!(Carton(22, 7, 19.3) == Carton(20, 20, 4)));
  REQUIRE(!(Carton(22, 7, 19.3) == Carton(20, 19, 4)));
  REQUIRE(Carton(8, 20, 9.5) == Carton(20, 19, 4));
}

TEST_CASE(
    "HowMany function returns 7 when called with a Carton array with seven "
    "of the value Carton(7.32, 8, 14.62).",
    "[carton]") {
  array<Carton, kMaxSize> presents = {
      Carton(7.32, 8, 14.62), Carton(8.1, 7, 15.8),    Carton(7.32, 8, 14.62),
      Carton(9, 14, 13.8),    Carton(7.32, 8, 14.62),  Carton(7, 8.3, 12.82),
      Carton(7.32, 8, 14.62), Carton(15.2, 6.9, 12.7), Carton(7.32, 8, 14.62),
      Carton(5.9, 6.3, 9.2),  Carton(8.2, 7.92, 6.58), Carton(7.32, 8, 14.62),
      Carton(7.32, 8, 14.62)};
  int present_size = 13;
  Carton min_present;
  Carton carton(7.32, 8, 14.62);

  int how_many = HowMany(carton, presents, present_size);

  REQUIRE(how_many == 7);
}

TEST_CASE(
    "HowMany function returns 5 when called with a Carton array with five "
    "of the value Carton(7.32, 8, 14.62).",
    "[carton]") {
  array<Carton, kMaxSize> presents = {
      Carton(8.1, 7, 15.8),   Carton(7.32, 8, 14.62), Carton(9, 14, 13.8),
      Carton(7.32, 8, 14.62), Carton(7.32, 8, 14.62), Carton(15.2, 6.9, 12.7),
      Carton(7.32, 8, 14.62), Carton(5.9, 6.3, 9.2),  Carton(8.2, 7.92, 6.58),
      Carton(7.32, 8, 14.62)};
  int present_size = 10;
  Carton min_present;
  Carton carton(7.32, 8, 14.62);

  int how_many = HowMany(carton, presents, present_size);

  REQUIRE(how_many == 5);
}

TEST_CASE(
    "HowMany function returns 0 when called with a Carton that is not "
    "found in the array.",
    "[carton]") {
  array<Carton, kMaxSize> presents = {
      Carton(8.1, 7, 15.8),   Carton(7.32, 8, 14.62), Carton(9, 14, 13.8),
      Carton(7.32, 8, 14.62), Carton(7.32, 8, 14.62), Carton(15.2, 6.9, 12.7),
      Carton(7.32, 8, 14.62), Carton(5.9, 6.3, 9.2),  Carton(8.2, 7.92, 6.58),
      Carton(7.32, 8, 14.62)};
  int present_size = 10;
  Carton min_present;
  Carton carton(7, 16, 22.7);

  int how_many = HowMany(carton, presents, present_size);

  REQUIRE(how_many == 0);
}
