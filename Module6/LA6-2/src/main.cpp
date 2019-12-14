#include <iostream>
#include <string>

using namespace std;

int main() {
  int* count_ptr = NULL;
  double* volume_ptr = NULL;
  string* name_ptr = NULL;

  if (count_ptr != NULL) {
    cout << "value of the new memory pointed to by count_ptr: " << *count_ptr
         << endl;
  }

  if (volume_ptr != NULL) {
    cout << "value of the new memory pointed to by volume_ptr: " << *volume_ptr
         << endl;
  }

  if (name_ptr != NULL) {
    cout << "value of the new memory pointed to by name_ptr: " << *name_ptr
         << endl;
  }

  cout << "value of count_ptr: " << count_ptr << endl;
  cout << "value of volume_ptr: " << volume_ptr << endl;
  cout << "value of name_ptr: " << name_ptr << endl;

  count_ptr = new int;
  *count_ptr = 92;
  if (count_ptr != NULL) {
    cout << "value of count_ptr: " << count_ptr << endl;
    cout << "value of the new memory pointed to by count_ptr: " << *count_ptr
         << endl;
  }
  volume_ptr = new double;
  *volume_ptr = 384.17;
  if (volume_ptr != NULL) {
    cout << "value of volume_ptr: " << volume_ptr << endl;
    cout << "value of the new memory pointed to by count_ptr: " << *count_ptr
         << endl;
  }
  name_ptr = new string;
  *name_ptr = "Welcome to dynamic memory!";
  if (name_ptr != NULL) {
    cout << "value of name_ptr: " << name_ptr << endl;
    cout << "value of the new memory pointed to by name_ptr: " << *name_ptr
         << endl;
  }
  delete count_ptr;
  delete volume_ptr;
  delete name_ptr;

  return 0;
}
