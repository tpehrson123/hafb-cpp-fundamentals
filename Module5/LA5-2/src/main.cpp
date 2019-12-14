#include "csvstream.h"
#include "containers.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

// Main Function
int main()
{
  // Create Containers
  std::vector<Data> pet_owners; // initial vector
  std::string in_file = "../data/input.csv";     // DO NOT MODIFY THIS
  // Load Data
  Load_Data(pet_owners, in_file);
  // Display Data
  for(const auto& value: pet_owners) 
  {
      std::cout << value.id << "\t" << value.name << "\t" << value.animal << endl;
  }
  

  return 0;
}