#include "age.h"
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/**
 * @brief Testing function
 * 
 */
TEST_CASE("Incrementing value by Value", "[TO1-4]") 
{
  INFO("TO Activity 3 Points");
  // Arrange
  int age = 5;
  // Act
  ByValueAgeIn5Years(age);
  // Assert
  REQUIRE(CurrentAge(age) ==5);
}


TEST_CASE("Incrementing value by Reference", "[TO1-4]") 
{
  INFO("TO Activity 3 Points");
  // Arrange
  int age = 5;
  // Act
  ByReferenceAgeIn5Years(age);
  // Assert
  REQUIRE(CurrentAge(age) == 10);
}