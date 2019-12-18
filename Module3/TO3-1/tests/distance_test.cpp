#include "distance.h"
#include "cout_redirect.h"
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Does the Distance exists","[start]")
{
    // Arrange
    Distance *g = new Distance;
    // Act
    // Assert
    CHECK(g != NULL);
}

TEST_CASE("Create distance object with default constructor","[start]")
{
    // Arrange
    Distance d1;
    // Act
    // Assert
    CHECK(d1.feet() == 0);
    CHECK(d1.inches() == 0);
}

TEST_CASE("Create distance object with second constructor","[start]")
{
    // Arrange
    Distance d1(12, 6.6);
    // Act
    // Assert
    CHECK(d1.feet() == 12);
    CHECK(d1.inches() == Approx(6.6).epsilon(0.01));
}

// TEST_CASE("Test output Operator", "[cout]")
// {
//   // Arrange
//   Distance d1(12, 6.6);
//   CoutRedirect buffer; // open buffer to capture output
//   // Act
//   std::cout<<d1;               // Redirect operator
//   std::string s_out = buffer.getString(); // get capture output to string
  
//   std::string test_string = "feet_: 12 inches_: 6.6";
//   // Assert
//   CHECK(s_out == test_string); // compare two strings
// }

TEST_CASE("Test - Operator", "[sub]")
{
  // Arrange
  Distance d1(12, 6.6);
  Distance d2(8, 9.2);
  Distance d3;
  // Act
  d3 = d1 + d2;
  d3 = d1 - d2;
  
  // Assert
  CHECK(d3.feet() ==  3); // compare two strings
  CHECK(d3.inches() == Approx(9.4).epsilon(0.01));
}

TEST_CASE("Test update_distance", "[update]")
{
  // Arrange
  Distance d1(12, 6.6);
  // Act
  d1.update_distance(9, 3.3);
  
  // Assert
  CHECK(d1.feet() ==  9); // compare two strings
  CHECK(d1.inches() == Approx(3.3).epsilon(0.01));
}