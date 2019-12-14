#include <iostream>
#include "containers.h"
using namespace std;

// Main Function
int main()
{
  std::vector<Data> information;
  std::string input = "../data/sample_data.csv";     // DO NOT MODIFY THIS LINE
  Load_Data(information, input); // Load Data
  cout <<"Information size: " << information.size() << endl;
  
  cout <<"Number of Males: " << Count_Gender(information, "Male")<< endl;
  cout <<"Number of Females: " << Count_Gender(information, "Female")<< endl;
  cout <<"Number of Cars: " << Count_Gender(information, "Car")<< endl;

  map<string, int> states;
  Count_by_State(information, states);
  Display_by_State(states);

  return 0;
}