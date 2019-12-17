/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-12-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <array>
#include <iostream>
#include <string>
#include <fstream> // file stream

// using namespace std;

/**
 * @brief Shows how to define and use an ifstream object to read from a file.
 *
 * We will define ifstream objects and then see some operators
 * and methods that work with these objects.
 *
 * @return int 0 means function exited with success
 */

const int kMaxSize = 24;

int main()
{
  // create an ojbect of type ifstream
  std::ifstream in; // input file stream

  // open the file age.txt
  in.open("../age.txt"); // relative path from the executable

  if (in.fail())
  {
    std::cout << "Unable to open file age.txt.\n  Shutting down\n";
    return 1;
  }

  // read from the age file and store values in an array
  std::array<int, kMaxSize> ages;
  ages.fill(-1); // init all array elements to -1

  int age_size = 0;
  while (age_size < kMaxSize && in >> ages[age_size])
  {
    age_size++;
  }

  in.close(); // close the input file

  // print out the values in the array
  for (auto age : ages)
  {
    std::cout << age << std::endl;
  }

  std::cout << std::endl;

  // create an ojbect of type ifstream
  std::ifstream in_names; // input file stream

  // open the file age.txt
  in_names.open("../name.txt"); // relative path from the executable

  if (in_names.fail())
  {
    std::cout << "Unable to open file name.txt.\n  Shutting down\n";
    return 1;
  }

  // read from the age file and store values in an array
  std::array<std::string, kMaxSize> names;
  names.fill("-"); // init all array elements to -1

  int name_size = 0;

  while (name_size < kMaxSize && getline(in_names, names[name_size]))
  {
    name_size++;
  }

  in_names.close(); // close the input file

  for (auto name : names)
  {
    std::cout << name << std::endl;
  }

  std::cout << std::endl;

  // create an ojbect of type ifstream
  std::ifstream in_names_age; // input file stream

  // open the file age.txt
  in_names_age.open("../name_age.txt"); // relative path from the executable

  if (in_names_age.fail())
  {
    std::cout << "Unable to open file name_age.\n  Shutting down\n";
    return 1;
  }

  ages.fill(-1);
  names.fill("-");

  int index = 0;

  while (index < kMaxSize && in_names_age >> ages[index])
  {
    in_names_age.ignore();
    std::getline(in_names_age, names[index]);
    index++;
  }

  in_names_age.close(); // close the input file

  for (int num=0; num < index; ++num)
  {
    std::cout << "Age: " << ages[num] << " for name: " <<
    names[num] << std::endl;
  
  }

  // read to the end of the file

  // print out the valid values in the array

  // print out the all the values in the array

  // Define an ifstream object and open the file name.txt

  // read one name, store it in the array, and print it

  // read the rest of the names in the file

  // print valid elements in the names array

  // print all the elements in the names array

  // Use a file with mixed values
  // Define an ifstream object and open the file name_age.txt

  // reset age and name arrays

  // read all the values from the name_age.txt file

  // print valid elements in the names and ages array

  // print all elements in the names and ages array

  return 0;
}
