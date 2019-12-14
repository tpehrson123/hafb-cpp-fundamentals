#include "round_shape.h"

  // static constant
  const double RoundShape::kPi = 3.14159;

    // constructors and destructor
  RoundShape::RoundShape(double radius){
    set_radius(radius);
  }

  
  // setters
  void RoundShape::set_radius(double radius){
    if (radius < 0)
    {
      throw std::out_of_range("Radius must be non-negative");
    }
    
    radius_ = radius;
  }

  // other methods
  void RoundShape::Display(std::ostream& out) const{
    out << "Round shape with radius of " << radius_ <<std::endl;
  }