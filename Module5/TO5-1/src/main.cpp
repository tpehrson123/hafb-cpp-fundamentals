#include <iostream>
#include "containers.h"
using namespace std;

// Main Function
int main()
{
  std::vector<Data> info;
  std::string in_file = "../data/sample_data.csv";
  Load_Data(info, in_file);

  std::cout << "You loaded: " << info.size() << " records " << endl;

  return 0;
}