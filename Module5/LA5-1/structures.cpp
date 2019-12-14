#include <iostream>
using namespace std;

// Local Prototypes

struct Part                   //declare a structure
{
   int modelnumber;           //ID number of widget
   int partnumber;            //ID number of widget part
   float cost;                //cost of part
};

////////////////////////////////////////////////////////////////
struct Distance                  //English distance
{
   int feet;
   float inches;
};
////////////////////////////////////////////////////////////////
struct Room                      //rectangular area
{
   Distance length;              //length of rectangle
   Distance width;               //width of rectangle
};

// Note: if the structure is define in the same file, you need to 
// declare your function after
void Scale(Distance& dist, float factor);
void DistanceDisplay(const Distance& dist);

////////////////////////////////////////////////////////////////

int main()
{
  Part part1;                //define a structure variable

   part1.modelnumber = 6244;  //give values to structure members
   part1.partnumber = 373;
   part1.cost = 217.55F;
                              //display structure members
   cout << "Model "  << part1.modelnumber;
   cout << ", part "   << part1.partnumber;
   cout << ", costs $" << part1.cost << endl;
   
   // declare and initialize
   Part part2 = { 6247, 173, 317.55F };  
   cout << "Model "  << part2.modelnumber;
   cout << ", part "   << part2.partnumber;
   cout << ", costs $" << part2.cost << endl;
   // copy one to another
   Part part3;
   part3 = part2;
   cout << "Model "  << part3.modelnumber;
   cout << ", part "   << part3.partnumber;
   cout << ", costs $" << part3.cost << endl;

   Distance d1 = { 12, 6.5};
   DistanceDisplay(d1);
   Scale(d1, 3);
   DistanceDisplay(d1);
   return 0;
}

/**
 * @brief Modify the Distance structure by a factor
 * 
 * @param dist: structure object reference
 * @param factor: weighted factor
 */
void Scale(Distance& dist, float factor)
{
   float inches = (dist.feet*12 + dist.inches) * factor;
   dist.feet = static_cast<int>(inches/12);  // get new feet
   dist.inches = inches - dist.feet * 12;    // get new inches
}

/**
 * @brief Display Distance Object
 * 
 * @param dist: const reference
 */
void DistanceDisplay(const Distance& dist)
{
   cout << dist.feet << "\'-" << dist.inches << "\"" << endl;
}