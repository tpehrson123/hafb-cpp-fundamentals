#ifndef MIN_ARRAY_H
#define MIN_ARRAY_H

const int kMaxSize = 20;

template <typename T>
T MinInArray(const std::array<T, kMaxSize>& item_array, int size) {
  T min_item = item_array[0];
  for (int i = 1; i < size; i++) {
    if (item_array[i] < min_item) {
      min_item = item_array[i];
    }
  }
  return min_item;
}

#endif