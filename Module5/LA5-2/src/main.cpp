#include "csvstream.h"
#include "containers.h"
#include <iostream>
#include <string>
#include <map>
// using namespace std;

// Main Function
int main()
{
  std::vector<Data> pet_owners;
  std::string in_file = "../data/input.csv";
  Load_Data(pet_owners, in_file);
  // Loop
  for(const auto& value : pet_owners)
  {
    std::cout << value.id << "\t" << value.name
      << "\t" << value.animal << std::endl;
  }

  

  return 0;
}