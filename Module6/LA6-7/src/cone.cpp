#include "cone.h"

Cone::Cone(double radius, double height) : RoundShape(radius) {
  set_height(height);
}

// setter
void Cone::set_height(double height) {
  if (height < 0) {
    throw std::out_of_range("Height must be non-negative");
  }
  height_ = height;
}

// other methods
void Cone::Display(std::ostream& out) const {
  out << "Cone with radius of " << radius_ << " and a height of " << height_
      << std::endl;
}

double Cone::Volume() const { return kPi * radius_ * radius_ * height_ / 3.0; }
