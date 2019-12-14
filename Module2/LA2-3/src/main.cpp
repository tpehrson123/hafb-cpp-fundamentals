#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Shows how to define and use an ofstream object to write to a file.
 *
 * We will define ofstream objects and then see some of the operators
 * and functions that work with these objects.
 *
 * @return int 0 means function exited with success
 */
int main() {
  // arrays that contain data
  const int kMaxSize = 20;
  array<int, kMaxSize> commute_minutes = {22, 51, 63, 12, 17, 93, 45,
                                          18, 66, 45, 43, 77, 38, 43,
                                          52, 21, 8,  19, 7,  14};

  array<int, kMaxSize> commute_miles = {8,  22, 28, 2,  4,  62, 15, 6, 42, 28,
                                        16, 43, 27, 18, 41, 8,  3,  5, 2,  4};

  array<string, kMaxSize> towns = {
      "Bountiful",    "Centerville",        "Clinton",       "South Weber",
      "West Point",   "Cottonwood Heights", "Murray",        "Salt Lake City",
      "South Jordan", "West Jordan",        "American Fork", "Lindon",
      "Payson",       "Pleasant Grove",     "Spanish Fork",  "Harrisville",
      "Ogden",        "Pleasant View",      "Riverdale",     "South Ogden"};

  array<string, kMaxSize> names = {
      "Walter", "Chris", "Stan",   "Mary",  "Shelly", "Kim",  "Kelly",
      "George", "Sam",   "Walter", "Ann",   "Laura",  "Paul", "Phillip",
      "Susan",  "Hal",   "Olivia", "Polly", "Roy",    "Scott"};

  // create a variable of type ofstream
  ofstream out;
  // open the file commute.txt
  out.open("../commute.txt");

  // write commute_minutes and commute_miles to the file commute.txt
  for (int i = 0; i < kMaxSize; i++) {
    out << commute_minutes[i] << " " << commute_miles[i] << endl;
  }

  out.close();

  // create a variable of type ofstream and open the file town.txt
  ofstream outfile("../town.txt");

  // write the towns to the file town.txt
  for (int i = 0; i < kMaxSize; i++) {
    outfile << towns[i] << endl;
  }

  outfile.close();

  // create a variable of type ofstream and open the file commute_data.txt
  ofstream output("../commute_data.txt");

  // write commute_minutes, commute_miles, and towns to the file commute.txt
  for (int i = 0; i < kMaxSize; i++) {
    output << commute_minutes[i] << " " << commute_miles[i] << endl
           << towns[i] << endl;
  }

  output.close();

  // do computations and add labeling to data before writing to file
  ofstream out_report("../commute_report.txt");

  // write a report to the commute_report.txt file. Include name, town,
  // commute_minutes, commute_miles, and average minutes per mile to the file
  // commute.txt
  for (int i = 0; i < kMaxSize; i++) {
    out_report << names[i] << " commutes to " << towns[i] << ". The commute is "
               << commute_miles[i] << " miles and takes about "
               << commute_minutes[i] << " minutes.That is an average of "
               << commute_minutes[i] / static_cast<float>(commute_miles[i])
               << " minutes per mile." << endl;
  }

  out_report.close();

  return 0;
}
