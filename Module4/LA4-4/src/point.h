#ifndef POINT_H
#define POINT_H

#include <iostream>
/**
 * @brief This class contains two values of a point, the x value and the y value
 *
 * @tparam T - this is the variable type, this type must be able to be set to
 * zero. It also must work with the << operator.
 */
template <typename T>
class Point {
 private:
  T x_value_;
  T y_value_;

 public:
  // constructors and destructors
  Point() : x_value_(0), y_value_(0) {}
  Point(T x_value, T y_value);
  ~Point() {}

  // getters
  T x_value() const { return x_value_; }
  T y_value() const { return y_value_; }

  // setters
  void set_x_value(T x_value);
  void set_y_value(T y_value);

  // other methods
  friend std::ostream& operator<<(std::ostream& out, const Point<T>& rhs) {
    out << "(" << rhs.x_value_ << "," << rhs.y_value_ << ")";
    return out;
  }
};

/**
 * @brief Construct a new Point<T>:: Point object
 *
 * @tparam T - variable type
 * @param x_value
 * @param y_value
 */
template <typename T>
Point<T>::Point(T x_value, T y_value) {
  set_x_value(x_value);
  set_y_value(y_value);
}

/**
 * @brief Set the x value object
 *
 * @tparam T - the variable type
 * @param x_value - the value to set x value to
 */
template <typename T>
void Point<T>::set_x_value(T x_value) {
  x_value_ = x_value;
}

/**
 * @brief Set the y value object
 *
 * @tparam T - the variable type
 * @param x_value - the value to set y value to
 */
template <typename T>
void Point<T>::set_y_value(T y_value) {
  y_value_ = y_value;
}
#endif