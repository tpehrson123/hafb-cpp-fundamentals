#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H

#include <iostream>
#include <string>

struct Address {
  std::string name;
  std::string street_address;
  std::string city;
  std::string state;
  std::string zip;
};

class ShippingItem {
 protected:
  Address address_;
  double weight_;
  double length_;
  bool delivered_;

 public:
  // static
  static const double kMaxWeight;
  static const double kMaxSize;
  static const double kMinSize;

  // constructors and destructor
  ShippingItem()
      : weight_(2), length_(12), delivered_(false), address_{"unknown"} {}
  ShippingItem(Address address, double weight, double length);
  ~ShippingItem() {}
 
  // getters
  Address address() const { return address_; }
  double weight() const { return weight_; }
  double length() const { return length_; }
  bool delivered() const { return delivered_; };

  // setters
  void set_address(Address address);
  void set_weight(double weight);
  virtual void set_length(double length);
  void set_delivered(bool delivered);

  // other methods
  void MarkDelivered();
  virtual double Volume() const = 0;
  virtual void Display(std::ostream &out) const = 0;
};

#endif