#include <iostream>
#include <string>

using namespace std;

int main() {
  // int count = 12;
  // double volume = 123.78;
  // string name = "kelly";

  // cout << "count: " << count << endl;
  // cout << "volume: " << volume << endl;
  // cout << "name: " << name << endl;

  // int* count_ptr = &count;
  // double* volume_ptr = &volume;
  // string* name_ptr = &name;

  // cout << "count pointer: " << count_ptr << endl;
  // cout << "volume pointer: " << volume_ptr << endl;
  // cout << "name pointer: " << name_ptr << endl;

  // cout << "count: " << *count_ptr << endl;
  // cout << "volume: " << *volume_ptr << endl;
  // cout << "name: " << *name_ptr << endl;

  // *count_ptr = 18;
  // *volume_ptr = 108.34;
  // *name_ptr = "Walter";

  // cout << "Values after change, using variable names:\n";
  // cout << "count: " << count << endl;
  // cout << "volume: " << volume << endl;
  // cout << "name: " << name << endl;

  // cout << "Values after change, using pointers:\n";
  // cout << "count: " << *count_ptr << endl;
  // cout << "volume: " << *volume_ptr << endl;
  // cout << "name: " << *name_ptr << endl;

  const int size = 25;
  int counts[size];

  int* array_ptr = counts;

  // *array_ptr = 22;
  // *(array_ptr + 1) = 73;
  // *(array_ptr + 2) = 51;

  array_ptr[0] = 22;
  array_ptr[1] = 73;
  array_ptr[2] = 51;

  cout << "output values using array name\n";
  cout << counts[0] << endl;
  cout << counts[1] << endl;
  cout << counts[2] << endl;

  cout << "\n output values using pointer and +\n";
  cout << *array_ptr << endl;
  cout << *(array_ptr + 1) << endl;
  cout << *(array_ptr + 2) << endl;

  cout << "output values using pointer and []\n";
  cout << array_ptr[0] << endl;
  cout << array_ptr[1] << endl;
  cout << array_ptr[2] << endl;

  return 0;
}
