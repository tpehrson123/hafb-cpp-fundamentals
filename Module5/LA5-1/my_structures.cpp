#include <iostream>
using namespace std;

struct Part
{
   int model_number;
   int part_number;
   float cost;
};

struct Car
{
   Part doors;
   Part windows;
   Part tires;
};


// Local Prototypes

int main()
{
   Part part1;

   part1.model_number = 6244;
   part1.part_number = 373;
   part1.cost = 45.90;

   std::cout << "Model: " << part1.model_number << endl;
   std::cout << "Part: " << part1.part_number << endl;
   std::cout << "Cost: $" << part1.cost << endl;

   Part part2 = {6277, 71, 32.10};

   std::cout << "\nModel: " << part2.model_number << endl;
   std::cout << "Part: " << part2.part_number << endl;
   std::cout << "Cost: $" << part2.cost << endl;

   // Part part3;
   // part3 = part2;

   // std::cout << "\nModel: " << part3.model_number << endl;
   // std::cout << "Part: " << part3.part_number << endl;
   // std::cout << "Cost: $" << part3.cost << endl;

   Car sedan;
   sedan.doors.part_number = 101;
   sedan.windows.model_number = 7001;
   sedan.tires.model_number = 89.99;

   
   return 0;
}
