#include <iostream>
#include <string>
#include "cylinder.h"
#include "round_shape.h"
#include "sphere.h"
#include "cone.h"

using std::cout;
using std::endl;

int main() {
  RoundShape round1;
  round1.Display(cout);

  RoundShape round2(6.3);
  round2.Display(cout);

  Sphere sphere1;
  sphere1.Display(cout);
  cout << "Radius: " << sphere1.radius() << endl;
  cout << "Volume: " << sphere1.Volume() << endl;

  Sphere sphere2(3.8);
  sphere2.Display(cout);
  cout << "Radius: " << sphere2.radius() << endl;
  cout << "Volume: " << sphere2.Volume() << endl;

  Cylinder cylinder1;
  cylinder1.Display(cout);
  cout << "Height: " << cylinder1.height() << endl;
  cout << "Radius: " << cylinder1.radius() << endl;
  cout << "Volume: " << cylinder1.Volume() << endl;

  Cylinder cylinder2(4.82, 18.3);
  cylinder2.Display(cout);
  cout << "Height: " << cylinder2.height() << endl;
  cout << "Radius: " << cylinder2.radius() << endl;
  cout << "Volume: " << cylinder2.Volume() << endl;

  Cone cone1;
  cone1.Display(cout);
  cout << "Height: " << cone1.height() << endl;
  cout << "Radius: " << cone1.radius() << endl;
  cout << "Volume: " << cone1.Volume() << endl;
  
  Cone cone2(7.1, 12.6);
  cone2.Display(cout);
  cout << "Height: " << cone2.height() << endl;
  cout << "Radius: " << cone2.radius() << endl;
  cout << "Volume: " << cone2.Volume() << endl;

  return 0;
}