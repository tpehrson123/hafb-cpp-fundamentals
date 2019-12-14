#include "sphere.h"

  // constructors and destructor
  Sphere::Sphere(double radius) : RoundShape(radius){}

  
  // other methods
  void Sphere::Display(std::ostream& out) const{
    out << "Sphere with radius of " << radius_ <<std::endl;
  }

  double Sphere::Volume() const{
    return 4.0/3.0 * kPi * radius_ * radius_ * radius_;
  }