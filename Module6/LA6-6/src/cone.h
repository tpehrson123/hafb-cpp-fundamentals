#ifndef CONE_H
#define CONE_H


#include "round_shape.h"

class Cone : public RoundShape {
 private:
  double height_;

 public:
  Cone() : height_(1) {}
  Cone(double radius, double height);
  ~Cone() {}

  // getter
  double height() const { return height_; };

  // setter
  void set_height(double height);

  // other methods
  void Display(std::ostream& out) const;
  double Volume() const;
};

#endif