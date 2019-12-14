#include "flat.h"

#include <iomanip>
#include <iostream>

using namespace std;

/**
 * @brief Sets the length, height and thickness of the flat. Makes sure all
 * dimensions are greater than .007.
 *
 * @param length - length of the flat
 * @param width - width of the flat
 * @param thickness - thickness of the flat
 * @throw std::out_of_range exception if any measurement is out of range
 */
Flat::Flat(Address address, double weight, double length, double height,
           double thickness)
    : ShippingItem(address, weight, length) {
  set_length(length);
  set_height(height);
  set_thickness(thickness);
}

/**
 * @brief - sets the value of length. Require length to be greater than zero
 * and the longest side.
 *
 * @param length - the value of the new length
 * @throw std::out_of_range exception if parameter length is zero or less or
 * if it is shorter than thickness or height.
 */
void Flat::set_length(double length) {
  if (length < kMinSize) {
    throw out_of_range("Length must be at least .007");
  }
  if (length > 15) {
    throw out_of_range("Length must be 15 inches or less");
  }

  length_ = length;
}

/**
 * @brief - sets the value of height
 *
 * @param height - the value of the new height
 * @throw std::out_of_range exception if parameter height is zero or less or
 * if it is longer than length.
 */
void Flat::set_height(double height) {
  if (height < kMinSize) {
    throw out_of_range("Height must be at least .007");
  }
  if (height > 12) {
    throw out_of_range("Height must be 12 inches or less");
  }

  height_ = height;
}

void Flat::set_thickness(double thickness) {
  if (thickness < kMinSize) {
    throw out_of_range("Thickness must be at least .007");
  }
  if (thickness > .75) {
    throw out_of_range("Thickness must be less than 3/4 inch");
  }

  thickness_ = thickness;
}

double Flat::Volume() const { return length_ * height_ * thickness_; }

void Flat::Display(std::ostream& out) const {
  out << setprecision(1) << fixed;
  out << "Flat: " << weight_ << " lbs. " << length_ << " x " << height_ << " x "
      << thickness_ << endl;
}
