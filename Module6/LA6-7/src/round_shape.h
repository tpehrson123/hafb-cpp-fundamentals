#ifndef ROUND_SHAPE_H
#define ROUND_SHAPE_H

#include <fstream>

class RoundShape {
 protected:
  double radius_;

 public:
  // static constant
  static const double kPi;

  // constructors and destructor
  RoundShape() : radius_(1) {}
  RoundShape(double radius);
  ~RoundShape() {}

  // getters
  double radius() const { return radius_; }

  // setters
  void set_radius(double radius);

  // other methods
  virtual void Display(std::ostream& out) const;
  virtual double Volume() const = 0;
};

#endif