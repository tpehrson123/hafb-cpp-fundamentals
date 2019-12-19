#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>

void Load_Data(std::vector<Data> &data, const std::string &input_file)
{
  csvstream csvinput(input_file);   // open file
  // Rows have a key = column name, value = cell data
  std::map<std::string, std::string> row;
  Data temp;
  // Extract the animal column
  while(csvinput >> row)
  {
      // The key is the column name
    //   std::cout << row["id"] << "," << row["name"] << "," << row["animal"] << std::endl;
      temp.id = std::stoi(row["id"]);   // cast string to integer
      temp.name = row["name"];
      temp.animal = row["animal"];
      data.push_back(temp);     // load Data struct into vector
  }
}