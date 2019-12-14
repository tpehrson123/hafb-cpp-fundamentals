#include <iostream>
#include <string>

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

  return 0;
}