#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Shows how to define and use an ifstream object to read from a file.
 *
 * We will define ifstream objects and then see some operators
 * and methods that work with these objects.
 *
 * @return int 0 means function exited with success
 */
int main() {
  // create an ojbect of type ifstream
  ifstream in;

  // open the file age.txt
  in.open("../age.txt");

  if (in.fail()) {
    cout << "Unable to open file age.txt.\nShutting down ...\n";
    return 1;
  }

  // // read from the age file and store values in an array
  const int kMaxSize = 24;
  array<int, kMaxSize> ages;
  ages.fill(-1);
  int age_size = 0;

  // in >> ages[age_size];
  // age_size++;
  // in >> ages[age_size];
  // age_size++;
  // in >> ages[age_size];
  // age_size++;
  // in >> ages[age_size];
  // age_size++;

  // // print out the values in the array
  // for (int i = 0; i < kMaxSize; i++) {
  //   cout << ages[i] << endl;
  // }

  // // read to the end of the file
  while (age_size < kMaxSize && in >> ages[age_size]) {
    age_size++;
  }

  // // print out the valid values in the array
  // cout << "\nAll valid elements in ages array:\n";
  // for (int i = 0; i < age_size; i++) {
  //   cout << ages[i] << endl;
  // }

  // print out the all the values in the array
  cout << "\nAll elements in ages array:\n";
  for (int i = 0; i < kMaxSize; i++) {
    cout << ages[i] << endl;
  }

  in.close();

  // Define an ifstream object and open the file name.txt
  ifstream infile("../name.txt");

  if (infile.fail()) {
    cout << "Unable to open file name.txt.\nShutting down ...\n";
    return 1;
  }

  // read one name, store it in the array, and print it
  array<string, kMaxSize> names;
  names.fill("-");
  int name_size = 0;

  getline(infile, names[name_size]);
  name_size++;

  // read the rest of the names in the file
  while (name_size < kMaxSize && getline(infile, names[name_size])) {
    name_size++;
  }

  infile.close();

  // print valid elements in the names array
  cout << "\nValid elements in the names array: \n";
  for (int i = 0; i < name_size; i++) {
    cout << names[i] << endl;
  }

  // print all the elements in the names array
  cout << "\nAll elements in the names array: \n";
  for (int i = 0; i < kMaxSize; i++) {
    cout << names[i] << endl;
  }

  // Use a file with mixed values
  // Define an ifstream object and open the file name_age.txt
  ifstream input("../name_age.txt");

  if (input.fail()) {
    cout << "Unable to open file name_age.txt.\nShutting down ...\n";
    return 1;
  }

  // reset age and name arrays
  ages.fill(-1);
  names.fill("-");
  int size = 0;

  // read all the values from the name_age.txt file
  while (size < kMaxSize && input >> ages[size]) {
    input.ignore();
    getline(input, names[size]);
    size++;
  }

  input.close();

  // print valid elements in the names and ages array
  cout << "\nValid elements in the names and ages array: \n";
  for (int i = 0; i < size; i++) {
    cout << names[i] << " " << ages[i] << endl;
  }

  // print all elements in the names and ages array
  cout << "\nALL elements in the names and ages array: \n";
  for (int i = 0; i < kMaxSize; i++) {
    cout << names[i] << " " << ages[i] << endl;
  }

  return 0;
}
