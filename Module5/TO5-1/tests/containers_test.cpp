#include "containers.h"
#include "cout_redirect.h"    // To test cout <<
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/**
 * @brief Sample to test a function returning an int value
 * 
 */
TEST_CASE("Load Correct Number of records from csv file", "[part1]") 
{
  // Arrange
  std::vector<Data> information;
  std::string input = "../data/sample_data.csv";
  // Act
  Load_Data(information, input); // Load Data
  // Assert
  REQUIRE( information.size() == 100000);
}

TEST_CASE("Load Correct Number of Male Records", "[part2]") 
{
  // Arrange
  std::vector<Data> information;
  std::string input = "../data/sample_data.csv";
  // Act
  Load_Data(information, input); // Load Data
  // Assert
  CHECK( Count_Gender(information, "Male") == 43001);
  CHECK( Count_Gender(information, "Female") == 56999);
  CHECK( Count_Gender(information, "Robots") == 0);
}


TEST_CASE("Load Correct Number of Records per State", "[part3]") 
{
  // Arrange
  std::vector<Data> information;
  std::string input = "../data/sample_data.csv";
  std::map<std::string, int> states;
  // Act
  Load_Data(information, input); // Load Data
  Count_by_State(information, states);
  // Assert
  CHECK(states["Texas"] == 2018);
  CHECK(states["Wyoming"] == 2030);
  CHECK(states["Utah"] == 1982);
  CHECK(states["Alaska"] == 2013);
}