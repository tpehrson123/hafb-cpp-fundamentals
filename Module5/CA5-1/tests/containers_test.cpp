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
  std::vector<Car> cars;
  std::string input = "../data/MOCK_DATA_CARS.csv";
  // Act
  Load_Data(cars, input); // Load Data
  // Assert
  REQUIRE( cars.size() == 4000);
}

TEST_CASE("Test for Maximum and Minimum Value", "[part2]") 
{
  // Arrange
  std::vector<Car> cars;
  std::string input = "../data/MOCK_DATA_CARS.csv";
  // Act
  Load_Data(cars, input); // Load Data
  Car car = Car_Value_Analytics(cars, MAX);
  // Asser
  CHECK( car.value == Approx(79990.3));
  
  // Act
  car = Car_Value_Analytics(cars, MIN);
  // Assert
  CHECK( car.value == Approx(20010.6));
}


TEST_CASE("Test for Sorted Vector of Cars by decade", "[part3]") 
{
  // Arrange
  std::vector<Car> cars;
  std::string input = "../data/MOCK_DATA_CARS.csv";
  int decade = 1980;
  Car temp;
  // Act: 1980
  Load_Data(cars, input); // Load Data
  std::vector<Car> new_cars = Cars_from_decade(cars, decade);
  // Assert
  temp = new_cars.front();
  CHECK(new_cars.size() == 311);
  CHECK(temp.value == Approx(20010.6));
  temp = new_cars.back();
  CHECK(temp.value == Approx(79934.92));
  
  // Act: 2000
  decade = 2000;
  new_cars = Cars_from_decade(cars, decade);
  // Assert
  temp = new_cars.front();
  CHECK(new_cars.size() == 1710);
  CHECK(temp.value == Approx(20015.35));
  temp = new_cars.back();
  CHECK(temp.value == Approx(79979.2));
  
  // Act: 2008
  decade = 2008;
  new_cars = Cars_from_decade(cars, decade);
  // Assert
  temp = new_cars.front();
  CHECK(new_cars.size() == 1710);
  CHECK(temp.value == Approx(20015.35));
  temp = new_cars.back();
  CHECK(temp.value == Approx(79979.2));
  
  // Act: 2010
  decade = 2010;
  new_cars = Cars_from_decade(cars, decade);
  // Assert
  temp = new_cars.front();
  CHECK(new_cars.size() == 571);
  CHECK(temp.value == Approx(20237.5));
  temp = new_cars.back();
  CHECK(temp.value == Approx(79949.3));

  // Act: 3000
  decade = 3000;
  new_cars = Cars_from_decade(cars, decade);
  // Assert
  CHECK(new_cars.size() == 0);
}
