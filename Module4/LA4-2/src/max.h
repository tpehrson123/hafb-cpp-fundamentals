#ifndef MAX_H
#define MAX_H

/**
 * @brief - this function receives two variables and returns the 
 * the one with the largest value
 * 
 * @tparam T - this is the type that will vary based on the function call, the
 * type must work with the > operator
 * @param one - one variable
 * @param two - the other variable
 * @return T - returns the variable that is the largest using the > operator
 */
template <typename T>
T MyMax(const T& one, const T& two){
  if (one > two)
  {
    return one;
  }
  return two;
}

#endif