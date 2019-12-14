#include <fstream>
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

  // double* volume_array = NULL;

  // int volume_size;
  // cout << "How many volumes do you have? ";
  // cin >> volume_size;

  // volume_array = new double[volume_size];

  // for (int i = 0; i < volume_size; i++) {
  //   cout << "Enter a volume: " << endl;
  //   cin >> volume_array[i];
  // }
  // for (int i = 0; i < volume_size; i++) {
  //   cout << volume_array[i] << endl;
  // }

  // delete[] volume_array;

  ifstream input("../first_names.txt");
  if (input.fail()) {
    cout << "Unable to open file. Shutting down...";
    return 1;
  }
  string* name_array = NULL;

  int how_many;
  input >> how_many;

  name_array = new string[how_many];

  for (int i = 0; i < how_many; i++) {
    input >> name_array[i];
  }
  cout << endl;

  cout << "first one: " << name_array[0] << endl;
  cout << "last one: " << name_array[how_many - 1] << endl;

  delete[] name_array;

  return 0;
}
