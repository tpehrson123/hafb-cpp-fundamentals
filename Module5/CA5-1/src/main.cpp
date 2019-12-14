#include <iostream>
#include "containers.h"
using namespace std;

// Main Function
int main()
{
  // Part I
  std::vector<Car> cars;
  std::string input = "../data/MOCK_DATA_CARS.csv"; // DO NOT MODIFY THIS LINE
  Load_Data(cars, input);                           // Load Data
  cout << "Information size: " << cars.size() << endl;
  // Part II
  Car car = Car_Value_Analytics(cars, MAX);
  cout << "Car MAX value: " << car.value << endl;
  car = Car_Value_Analytics(cars, MIN);
  cout << "Car MIN value: " << car.value << endl;
  // Part III
  int decade = 2009;
  std::vector<Car> new_cars = Cars_from_decade(cars, decade);
  for (const Car &car : new_cars)
  {
    std::cout << "New cars for " << decade << " " << car.year << " "
              << car.value << std::endl;
  }
  cout << new_cars.size() << endl;

  return 0;
}