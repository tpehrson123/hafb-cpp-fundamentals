#ifndef MIN_H
#define MIN_H

template <typename T>
T MyMin(const T& one, const T& two) {
  if (one < two)
  {
    return one;
  }
  return two;
}

#endif