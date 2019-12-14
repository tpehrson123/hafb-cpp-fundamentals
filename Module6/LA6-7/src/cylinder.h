#ifndef CYLINDER_H
#define CYLINDER_H

#include "round_shape.h"

class Cylinder : public RoundShape {
 private:
  double height_;

 public:
  Cylinder() : height_(1) {}
  Cylinder(double radius, double height);
  ~Cylinder() {}

  // getter
  double height() const { return height_; };

  // setter
  void set_height(double height);

  // other methods
  void Display(std::ostream& out) const;
  double Volume() const;
};

#endif