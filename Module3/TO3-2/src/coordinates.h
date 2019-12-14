/*
** coordinate.h 
*/

#ifndef COORDINATE_H_
#define COORDINATE_H_
#include <iostream>

// namespace point
// {
// Class definition
class Coordinates
{
private:
  float latitude_;
  float longitude_;

  // Getters and setters
public:
  Coordinates();
  Coordinates(float latitude, float longitude);
  void set_latitude(float value);
  void set_longitude(float value);
  float latitude() const;
  float longitude() const;
  void from_float_to_gps_(float number, int &degrees, int &minutes, int &seconds);
  
  // Remove all code below for students
  bool operator != (Coordinates c2) const;
  bool operator == (Coordinates c2) const;
  friend std::ostream &operator<<(std::ostream &os, const Coordinates &location);
  std::string show_gps();

};
// } // namespace point

#endif /* !COORDINATE_H_ */
