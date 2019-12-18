#include <iostream>
#include "carton.h"
#include <array>
#include "carton_fileio.h"

using namespace std;

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
  std::array<Carton, kMaxArraySize> boxes;

  // read data from file
  int record_size = 0;
  std::string message;
  message = ReadDataFormatFromFile("../carton_data.txt", boxes, record_size);

  std::cout << message << "Records loaded: " << record_size << std::endl;

  // loop through the array
  for (auto box = 0; box < record_size; ++box)
  {
    boxes[box].ShowInfo();
  }
  
  // write data to file
  WriteDataToFile("../carton_data.csv", boxes, record_size);

  return 0;
}