#include <iostream>
#include <string>
#include "cone.h"
#include "cylinder.h"
#include "round_shape.h"
#include "sphere.h"

using std::cout;
using std::endl;

int main() {
  // RoundShape round1;
  // round1.Display(cout);

  // RoundShape round2(6.3);
  // round2.Display(cout);

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

  const int size = 8;
  // RoundShape rounds[size];

  // cout << "\nArray of RoundShape objects created with the default "
  //         "constructor:\n";
  // for (RoundShape one_round : rounds) {
  //   one_round.Display(cout);
  // }

  // rounds[0] = round1;
  // rounds[1] = round2;
  // rounds[2] = sphere1;
  // rounds[3] = sphere2;
  // rounds[4] = cylinder1;
  // rounds[5] = cylinder2;
  // rounds[6] = cone1;
  // rounds[7] = cone2;

  // cout << "\nArray of mixed objects:\n";
  // for (RoundShape one_round : rounds) {
  //   one_round.Display(cout);
  // }

  RoundShape* round_ptrs[size];

  cout << "\nArray of RoundShape pointers:\n";
  for (RoundShape* one_ptr : round_ptrs) {
    cout << one_ptr << endl;
  }

  round_ptrs[0] = NULL;  //&round1;
  round_ptrs[1] = NULL;  //&round2;
  round_ptrs[2] = &sphere1;
  round_ptrs[3] = &sphere2;
  round_ptrs[4] = &cylinder1;
  round_ptrs[5] = &cylinder2;
  round_ptrs[6] = &cone1;
  round_ptrs[7] = &cone2;

  cout << "\nArray of RoundShape pointers:\n";
  for (RoundShape* one_ptr : round_ptrs) {
    cout << one_ptr << endl;
  }

  cout << "\nArray of RoundShape pointers:\n";
  for (RoundShape* one_ptr : round_ptrs) {
    if (one_ptr != NULL) {
      one_ptr->Display(cout);
    }
  }

  round_ptrs[0] = new Cylinder(3.76, 8.24);
  round_ptrs[1] = new Sphere(3.42);
  round_ptrs[2] = new Cylinder(3.4, 12.8);
  round_ptrs[3] = new Sphere(5.4);
  round_ptrs[4] = new Sphere(8.2);
  round_ptrs[5] = new Cone(8.974, 41.2);
  round_ptrs[6] = new Cone(4.56, 8.03);
  round_ptrs[7] = new Sphere(9.12);

  cout << "\nArray of RoundShape pointers:\n";
  for (RoundShape* one_ptr : round_ptrs) {
    one_ptr->Display(cout);
    cout << "Volume: " << one_ptr->Volume() << endl;
  }

  for (RoundShape*& one_ptr : round_ptrs) {
    delete one_ptr;
    one_ptr = NULL;
  }

  cout << "\nArray of RoundShape pointers:\n";
  for (RoundShape* one_ptr : round_ptrs) {
    cout << one_ptr << endl;
  }

  return 0;
}