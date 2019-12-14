#include <iostream>
#include <string>
#include "carton.h"
#include "key_value.h"

using namespace std;

int main() {
  const int kSize = 5;

  // Define a KeyValue object
  KeyValue<int, Carton, kSize> key_value;

  // Add 3 - 12 key - value pairs
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));

  // Call the ValueAt method to get a value
  // use the Found method to make sure the key exists before calling the
  // ValueAt method
  if (key_value.Found(9)) {
    cout << "The value at key 9: " << key_value.ValueAt(9) << endl;
  }
  // Remove one or more key - value pairs
  cout << "How many removed for key 5: " << key_value.RemoveAll(5) << endl;

  // Output the KeyValue object to the screen using the << operator
  cout << "The key-value container: \n" << key_value;

  // Define a KeyValue object
  KeyValue<string, int, kSize> key_value2;

  // Add 3 - 12 key - value pairs
  key_value2.Add("Mary", 7);
  key_value2.Add("Kim", 22);
  key_value2.Add("Sally", 14);
  key_value2.Add("Mark", 4);
  key_value2.Add("Kim", 12);

  // Call the ValueAt method to get a value
  // use the Found method to make sure the key exists before calling the
  // ValueAt method
  if (key_value2.Found("Sally")) {
    cout << "The age for Sally: " << key_value2.ValueAt("Sally") << endl;
  }
  // Remove one or more key - value pairs
  cout << "How many removed for Kim: " << key_value2.RemoveAll("Kim") << endl;

  // Output the KeyValue object to the screen using the << operator
  cout << "The key-value container: \n" << key_value2;

  return 0;
}
