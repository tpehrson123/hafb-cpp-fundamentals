#include <iostream>
#include <string>

using namespace std;

int main() {
  int* count_array = NULL;

  // int size;
  // cout << "How many counts do you want? ";
  // cin >> size;

  // count_array = new int[size];

  // for (int i = 0; i < size; i++) {
  //   cout << "Enter count " << i + 1 << ": ";
  //   cin >> count_array[i];
  // }
  // cout << endl;
  // for (int i = 0; i < size; i++) {
  //   cout << count_array[i] << endl;
  // }

  // delete[] count_array;

  double* volume_array = NULL;

  int volume_size;
  cout << "How many volumes do you have? ";
  cin >> volume_size;

  volume_array = new double[volume_size];

  for (int i = 0; i < volume_size; i++) {
    cout << "Enter a volume: " << endl;
    cin >> volume_array[i];
  }
  for (int i = 0; i < volume_size; i++) {
    cout << volume_array[i] << endl;
  }

  delete[] volume_array;

  return 0;
}
