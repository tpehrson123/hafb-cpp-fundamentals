#include <iostream>
#include "carton.h"

using namespace std;

int main()
{
  // create a Carton object using the default constructor
  Carton box;

  box.set_height(2.3);
  box.set_width(1.023);
  box.set_length(3.12);

  box.ShowInfo();

  Carton box2(13.2, 111.2, 345.3);
  box2.ShowInfo();

  // create a Carton object using the other constructor

  // create an array of Cartons

  // add some valid elements to the array

  // loop through the array

  // print out the volume of packages

  // print out the girth of packages

  // print out the length plus girth of packages

  // check if package is sized to ship

  // define a package that is too big to ship

  // define a package that is too small to ship

  // print if sized to ship

  // write carton data and information

  // read data from file

  // write data to file

  return 0;
}