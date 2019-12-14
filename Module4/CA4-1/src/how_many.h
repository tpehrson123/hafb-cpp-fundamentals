#ifndef HOW_MANY_H
#define HOW_MANY_H

const int kMaxSize = 20;

/**
 * @brief - receives a value and an array, counts how many times the value
 * is found in the array and returns that count.
 * 
 * @tparam T - variable type, must work with the == operator
 * @param item - the value to be counted
 * @param item_array - the array that contains values
 * @param size - the number of valid elements in the array
 * @return int - a count of how many times the item is found in the array
 */
template <typename T>
int HowMany(const T item, const std::array<T, kMaxSize>& item_array, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (item_array[i] == item) {
      count++;
    }
  }
  return count;
}

#endif