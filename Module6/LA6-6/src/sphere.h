#ifndef SPHERE_H
#define SPHERE_H

#include "round_shape.h"

class Sphere : public RoundShape {
  private:

  public:
  // constructors and destructor
  Sphere(){}
  Sphere(double radius);
  ~Sphere(){}

  // other methods
  void Display(std::ostream& out) const;
  double Volume() const;
};

#endif