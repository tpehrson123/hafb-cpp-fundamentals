#include <iostream>
#include <string>

using namespace std;

int main() {
  int* count_ptr = NULL;
  double* volume_ptr = NULL;
  string* name_ptr = NULL;

  cout << "value of count_ptr: " << count_ptr << endl;
  cout << "value of volume_ptr: " << volume_ptr << endl;
  cout << "value of name_ptr: " << name_ptr << endl;

  count_ptr = new int;
  *count_ptr = 92;

  cout << "value of count_ptr: " << count_ptr << endl;
  cout << "value of the new memory pointed to by count_ptr: " << *count_ptr
       << endl;

  volume_ptr = new double;
  *volume_ptr = 384.17;

  cout << "value of volume_ptr: " << volume_ptr << endl;
  cout << "value of the new memory pointed to by count_ptr: " << *count_ptr
       << endl;

  return 0;
}
