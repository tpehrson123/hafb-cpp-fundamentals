#ifndef SWAP_H
#define SWAP_H

/**
 * @brief - this function receives two variables, it swaps the values in
 * these variables
 * 
 * @tparam T - the variable type will be determined when the function is called
 * @param value1 - one variable 
 * @param value2 - the other variable
 */
template <typename T>
void MySwap(T& value1, T& value2) {
  T temp;
  temp = value1;
  value1 = value2;
  value2 = temp;
}

#endif