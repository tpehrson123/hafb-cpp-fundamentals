#include "csvstream.h"
#include "containers.h"
#include <iostream>
#include <string>
#include <map>
// using namespace std;

// Main Function
int main()
{
  std::vector<Data> info;
  std::string in_file = "../data/sample_data.csv";
  Load_Data(info, in_file);
  // Loop
  for(const auto& value : info)
  {
    std::cout << value.id << "\t" << value
      << "\t" << value.animal << std::endl;
  }

  

  return 0;
}