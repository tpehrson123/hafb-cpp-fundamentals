#ifndef MAX_ARRAY_H
#define MAX_ARRAY_H

#include <array>

const int kMaxSize = 20;

/**
 * @brief - this function receives an array and returns the maximum value in 
 * the array.
 * 
 * @tparam T - this is the variable type that will be determined when the
 * function is called, types must support the > operator
 * @param item_array - this is an array of the variable type
 * @param size - an integer that identifies how many valid values are in the
 * array
 * @return T - the maximum value in the array based on the > operator
 */
template <typename T>
T MaxInArray(const std::array<T, kMaxSize> item_array, int size) {
  // initial max to one value in the array
  T max_item = item_array[0];
  for (int i = 1; i < size; i++)
  {
    if(item_array[i] > max_item){
      max_item = item_array[i];
    }
  }
  return max_item;
}

#endif