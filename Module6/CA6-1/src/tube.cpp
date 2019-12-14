#include "tube.h"

#include <cmath>
#include <iomanip>

const double Tube::kPi = 3.14159;

Tube::Tube(Address address, double weight, double length, double circumference)
    : ShippingItem(address, weight, length) {
  set_circumference(circumference);
}

void Tube::set_circumference(double circumference) {
  if (circumference < kMinSize) {
    throw std::out_of_range("Circumference must be greater than .007 inches");
  }
  if ((length_ + circumference) > kMaxSize) {
    throw std::out_of_range(
        "Length plus circumference must be 108 inches or less");
  }

  circ_ = circumference;
}

// other methods
double Tube::Volume() const {
  return kPi * (circ_ / (2 * kPi)) * (circ_ / (2 * kPi)) * length_;
}

void Tube::Display(std::ostream& out) const {
  out << std::setprecision(1) << std::fixed;
  out << "Tube: " << weight_ << " lbs. " << length_ << " x " << circ_
      << std::endl;
}
