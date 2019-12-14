#include <iostream>
#include <string>
#include "carton.h"

using namespace std;

int main() {
  // string* name = NULL;
  // name = new string;
  // *name = "Mary Ann Walters";

  string* name = new string("Mary Ann Walters");

  cout << "the address: " << name << endl;
  cout << "the name: " << *name << endl;
  cout << "the length: " << name->length() << endl;

  delete name;

  Carton* present = new Carton;

  cout << "the address: " << present << endl;
  cout << "the carton: " << *present << endl;
  cout << "the volume: " << present->Volume() << endl;
  cout << "the length plus girth: " << present->LengthPlusGirth() << endl;

  delete present;

  present = new Carton(12, 15, 31);

  cout << "the address: " << present << endl;
  cout << "the carton: " << *present << endl;
  cout << "the volume: " << present->Volume() << endl;
  cout << "the length plus girth: " << present->LengthPlusGirth() << endl;

  delete present;

  return 0;
}