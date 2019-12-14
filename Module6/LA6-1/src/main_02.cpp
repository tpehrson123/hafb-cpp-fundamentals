#include <iostream>
#include <string>

using namespace std;

int main() {
  int count = 12;
  double volume = 123.78;
  string name = "kelly";

  cout << "count: " << count << endl;
  cout << "volume: " << volume << endl;
  cout << "name: " << name << endl;

  int* count_ptr = &count;
  double* volume_ptr = &volume;
  string* name_ptr = &name;

  cout << "count pointer: " << count_ptr << endl;
  cout << "volume pointer: " << volume_ptr << endl;
  cout << "name pointer: " << name_ptr << endl;

  cout << "count: " << *count_ptr << endl;
  cout << "volume: " << *volume_ptr << endl;
  cout << "name: " << *name_ptr << endl;

  return 0;
}
