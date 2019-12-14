#include <iostream>
#include <string>
#include "carton.h"

using namespace std;

int main() {
  Carton carton;

  cout << carton.address().name << endl;
  cout << carton.address().street_address << endl;
  cout << carton.address().city << endl;
  cout << carton.address().state << endl;
  cout << carton.address().zip << endl;
  cout << carton.height() << endl;
  cout << carton.length() << endl;
  cout << carton.width() << endl;

  return 0;
}