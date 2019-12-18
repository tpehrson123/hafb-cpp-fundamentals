#include <iostream>
#include "carton.h"
#include <array>

using namespace std;

const int kMaxSize = 10;
int main()
{
  // create a Carton object using the default constructor
  // Carton box;

  // box.set_height(6.2);
  // box.set_width(1.023);
  // box.set_length(6.12);

  // box.ShowInfo();

  // // create a Carton object using the other constructor
  // Carton box2(13.2, 111.2, 345.3);
  // box2.ShowInfo();


  // Carton box3(6.4, 111.2, 345.3);
  // box3.ShowInfo();

  // create an array of Cartons
  std::array<Carton, kMaxSize> boxes;

  // add some valid elements to the array
  boxes[0] = Carton(12,21,52);


  // loop through the array
  for (Carton box : boxes)
  {
    box.ShowInfo();
  }
  

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