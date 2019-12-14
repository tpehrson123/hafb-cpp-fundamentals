#ifndef TUBE_H
#define TUBE_H

#include <iostream>
#include <string>
#include "shipping_item.h"

class Tube : public ShippingItem {
 private:
  double circ_;

 public:
  // static member
  static const double kPi;
  
  // constructors and destructor
  Tube() : circ_(12) {}
  Tube(Address address, double weight,
       double length, double circumference);
  ~Tube() {}

  // getters
  double circumference() const { return circ_; }

  // setters
  void set_circumference(double circumference);

  // other methods
  double Volume() const;
  double Girth() const { return circ_; }
  void Display(std::ostream &out) const;
};

#endif