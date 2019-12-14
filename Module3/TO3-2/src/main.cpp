#include <iostream>
#include "coordinates.h"
using namespace std;

// Main Function
int main() 
{
  // Coordinates washington_dc;
  // cout << "Object named washington_dc of type Coordinates created." << endl;

  // washington_dc.set_latitude(38.8951);
  // washington_dc.set_longitude(-77.0364);
  // cout << "Object's latitude and longitude set." << endl;

  // cout << "Washington DC has a latitude of " << washington_dc.latitude() << " and longitude of "
  //           << washington_dc.longitude() << endl;

  // // Coordinates ogden(41.2230, -111.9738);
  // Coordinates ogden(41.2230, -111.970420);
  // Coordinates ogden2(41.2230, -111.9738);
  // Coordinates logan(41.7370, -111.8338);

  Coordinates ogden(41.2230, -111.970420);
  cout<<"Ogden's Location: " << ogden << endl;
  cout<< ogden.show_gps() << endl;
  
  Coordinates cape_town(-33.924870, 18.424055);
  cout<<"CapeTown's Location: " << cape_town << endl;
  cout<< cape_town.show_gps() << endl;


  return 0;
}