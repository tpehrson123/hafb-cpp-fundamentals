#include <array>
#include <iostream>
#include <string>
#include <fstream> // file stream

// using namespace std;

/**
 * @brief Shows how to define and use an ofstream object to write to a file.
 *
 * We will define ofstream objects and then see some of the operators
 * and functions that work with these objects.
 *
 * @return int 0 means function exited with success
 */
int main()
{
  // arrays that contain data
  const int kMaxSize = 20;
  std::array<int, kMaxSize> commute_minutes = {22, 51, 63, 12, 17, 93, 45,
                                               18, 66, 45, 43, 77, 38, 43,
                                               52, 21, 8, 19, 7, 14};

  std::array<int, kMaxSize> commute_miles = {8, 22, 28, 2, 4, 62, 15, 6, 42, 28,
                                             16, 43, 27, 18, 41, 8, 3, 5, 2, 4};

  std::array<std::string, kMaxSize> towns = {
      "Bountiful", "Centerville", "Clinton", "South Weber",
      "West Point", "Cottonwood Heights", "Murray", "Salt Lake City",
      "South Jordan", "West Jordan", "American Fork", "Lindon",
      "Payson", "Pleasant Grove", "Spanish Fork", "Harrisville",
      "Ogden", "Pleasant View", "Riverdale", "South Ogden"};

  std::array<std::string, kMaxSize> names = {
      "Walter", "Chris", "Stan", "Mary", "Shelly", "Kim", "Kelly",
      "George", "Sam", "Walter", "Ann", "Laura", "Paul", "Phillip",
      "Susan", "Hal", "Olivia", "Polly", "Roy", "Scott"};

  // create a variable of type ofstream
  std::ofstream commute_file; // output file stream

  // open the file commute.txt
  commute_file.open("../commute.csv"); // relative path from the executable
  if (commute_file.fail())
  {
    std::cout << "Unable to open file commute.csv.\n  Shutting down\n";
    return 1;
  }

  // write commute_minutes and commute_miles to the file commute.txt
  for (int index = 0; index < kMaxSize; ++index)
  {
    //  std::cout << commute_minutes[index] << "," << commute_miles[index] << std::endl;
    commute_file << commute_minutes[index] << "," << commute_miles[index] << std::endl;
  }

  commute_file.close();

  // --------------------------------------------------------------------------------------
  // --------------------------------------------------------------------------------------

  // create a variable of type ofstream and open the file town.txt
  std::ofstream town_file; // output file stream

  // open the file town.txt
  town_file.open("../town.csv"); // relative path from the executable
  if (town_file.fail())
  {
    std::cout << "Unable to open file town.csv.\n  Shutting down\n";
    return 1;
  }

  // write towns and names to the file town.txt
  for (int index = 0; index < kMaxSize; ++index)
  {
    //  std::cout << names[index] << "," << towns[index] << std::endl;
    town_file << names[index] << "," << towns[index] << std::endl;
  }

  town_file.close();

  // create a variable of type ofstream and open the file utah_info.csv

  // --------------------------------------------------------------------------------------
  // Create a CSV record file as follows:
  // Header : Verison, minutes, miles, min/miles, name, town
  // Follow by the actual data
  // --------------------------------------------------------------------------------------

  // create a variable of type ofstream and open the commute_data
  std::ofstream utah_info_file; // output file stream

  // open the file town.txt
  utah_info_file.open("../utah_info.csv"); // relative path from the executable
  if (utah_info_file.fail())
  {
    std::cout << "Unable to open file utah_info.csv.\n  Shutting down\n";
    return 1;
  }

  utah_info_file << "Version, Minutes, Miles, Minutes/Miles, Name, Town" << std::endl;

  // write data
  for (int index = 0; index < kMaxSize; ++index)
  {
    // float min_per_mile = (float)commute_minutes[index] / (float)commute_miles[index];  // old c-style cast
    float min_per_mile = static_cast<float>(commute_minutes[index]) / commute_miles[index];

    utah_info_file << "V1 "
                   << commute_minutes[index] << "," << commute_miles[index]
                   << "," << min_per_mile << "," << names[index] << ","
                   << towns[index] << std::endl;
  }

  utah_info_file.close();

  return 0;
}
