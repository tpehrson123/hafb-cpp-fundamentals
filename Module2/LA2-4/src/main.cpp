#include <array>
#include <iostream>
#include "carton.h"
#include "carton_fileio.h"

using namespace std;

int main() {
  // create a Carton object using the default constructor
  Carton package;

  cout << "Package information:\n"
       << "Length: " << package.length() << " Width: " << package.width()
       << " Height: " << package.height() << endl;

  // create a Carton object using the other constructor
  try {
    Carton present(21, 9, 8);

    cout << "\nPresent information:\n"
         << "Length: " << present.length() << " Width: " << present.width()
         << " Height: " << present.height() << endl;
  } catch (out_of_range e) {
    cout << "Exception thrown: " << e.what() << endl;
  }

  // create an array of Cartons

  array<Carton, kMaxSize> cartons;

  // add some valid elements to the array
  int size = 0;
  cartons[size] = Carton(12, 41, 52);
  size++;
  cartons[size] = Carton(31, 18, 17);
  size++;
  cartons[size] = Carton(23, 17, 51);
  size++;

  // loop through the array
  for (int i = 0; i < size; i++) {
    cout << "Carton " << i << ":\n"
         << cartons[i].length() << " " << cartons[i].width() << " "
         << cartons[i].height() << endl;
  }

  // print out the volume of packages
  for (int i = 0; i < size; i++) {
    cout << "Carton " << i << " volume: " << cartons[i].Volume() << endl;
  }

  // print out the girth of packages
  for (int i = 0; i < size; i++) {
    cout << "Carton " << i << " girth: " << cartons[i].Girth() << endl;
  }

  // print out the length plus girth of packages
  for (int i = 0; i < size; i++) {
    cout << "Carton " << i
         << " length plus girth: " << cartons[i].LengthPlusGirth() << endl;
  }

  // check if package is sized to ship
  // define a package that is too big to ship
  cartons[size] = Carton(35, 66, 78);
  size++;

  // define a package that is too small to ship
  cartons[size] = Carton(5, 4, 3);
  size++;
  cartons[size] = Carton(7, 2, 1);
  size++;
  cartons[size] = Carton(8, 3, 2);
  size++;
  cartons[size] = Carton(3, 7, 1);
  size++;
  cartons[size] = Carton(.25, 4, 8);
  size++;

  // print if sized to ship
  for (int i = 0; i < size; i++) {
    cout << "Carton " << i << ":\n"
         << cartons[i].length() << " " << cartons[i].width() << " "
         << cartons[i].height()
         << " length plus girth: " << cartons[i].LengthPlusGirth() << endl;
    if (cartons[i].SizedToShip()) {
      cout << "Can ship this carton.\n";
    } else {
      cout << "Cannot ship this carton. It is the wrong size.\n";
    }
  }

  // write carton data and information
  for (int i = 0; i < size; i++) {
    cartons[i].WriteData(cout);
    cartons[i].WriteCarton(cout);
  }

  // read data from file
  string message;
  array<Carton, kMaxSize> packages;
  int package_size = 0;
  message =
      ReadDataFromFile("../carton_data_error.txt", packages, package_size);
  cout << "Message: " << message << endl;

  for (int i = 0; i < package_size; i++) {
    packages[i].WriteData(cout);
  }

  // write data to file
  WriteDataToFile("../carton_out.txt", cartons, size);
  WriteDataToFile("../packages_out.dat", packages, package_size);

  return 0;
}