#include "cylinder.h"

Cylinder::Cylinder(double radius, double height) : RoundShape(radius) {
  set_height(height);
}

// setter
void Cylinder::set_height(double height) {
  if (height < 0) {
    throw std::out_of_range("Height must be non-negative");
  }
  height_ = height;
}

// other methods
void Cylinder::Display(std::ostream& out) const {
  out << "Cylinder with radius of " << radius_ << " and a height of " << height_
      << std::endl;
}

double Cylinder::Volume() const {
  return kPi * radius_ * radius_ * height_;
}
