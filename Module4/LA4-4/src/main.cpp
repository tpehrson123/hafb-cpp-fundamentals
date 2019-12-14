#include <iostream>
#include "point.h"

using namespace std;

int main() {
  // use the Point class with integers
  Point<int> point1;
  cout << "Point 1: " << point1.x_value() << " " << point1.y_value() << endl;

  Point<int> point2(18, 23);
  cout << "Point 2: " << point2.x_value() << " " << point2.y_value() << endl;
  cout << "Point 1: " << point1 << endl;

  point1.set_x_value(19);
  point1.set_y_value(73);
  cout << "Point 1: " << point1.x_value() << " " << point1.y_value() << endl;
  cout << "Point 2: " << point2 << endl;

  // use the Point class with doubles
  Point<double> point3;
  cout << "Point 3: " << point3.x_value() << " " << point3.y_value() << endl;
  cout << "Point 3: " << point3 << endl;

  Point<double> point4(38.23, 89.75);
  cout << "Point 4: " << point4.x_value() << " " << point4.y_value() << endl;
cout << "Point 4: " << point4 << endl;
  point3.set_x_value(12.98);
  point3.set_y_value(31.34);
  cout << "Point 3: " << point3.x_value() << " " << point3.y_value() << endl;
  cout << "Point 3: " << point3 << endl;
  return 0;
}