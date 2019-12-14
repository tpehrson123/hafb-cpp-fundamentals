#include <iostream>
#include <string>

using namespace std;

int main() {
  int count = 0;
  int volume = 892.23;
  string name =
      "Charlie Brown went on a walk to the end of the world. It was dark and "
      "cold so he came back home.";

  int* count_ptr = NULL;
  double* volume_ptr = NULL;
  string* name_ptr = NULL;

  cout << "value of count: " << count << endl;
  cout << "value of volume: " << volume << endl;
  cout << "value of name: " << name << endl;
  cout << "value of count_ptr: " << count_ptr << endl;
  cout << "value of volume_ptr: " << volume_ptr << endl;
  cout << "value of name_ptr: " << name_ptr << endl;

  cout << "size of count: " << sizeof(count) << endl;
  cout << "size of volume: " << sizeof(volume) << endl;
  cout << "size of name: " << sizeof(name) << endl;
  cout << "number of characters in name: " << name.size() << endl;
  cout << "size of count_ptr: " << sizeof(count_ptr) << endl;
  cout << "size of volume_ptr: " << sizeof(volume_ptr) << endl;
  cout << "size of name_ptr: " << sizeof(name_ptr) << endl;

  return 0;
}
