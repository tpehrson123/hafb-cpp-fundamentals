#include <iostream>
#include <string>

using namespace std;

int main() {
  int* count_array = NULL;

  int size;
  cout << "How many counts do you want? ";
  cin >> size;

  count_array = new int[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter count " << i + 1 << ": ";
    cin >> count_array[i];
  }
  cout << endl;
  for (int i = 0; i < size; i++) {
    cout << count_array[i] << endl;
  }

  delete[] count_array;

  return 0;
}
