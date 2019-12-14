#include "shipping_item.h"

// define the static members
const double ShippingItem::kMaxWeight = 70;
const double ShippingItem::kMaxSize = 108;
const double ShippingItem::kMinSize = .007;

ShippingItem::ShippingItem(Address address, double weight, double length) {
  set_address(address);
  set_weight(weight);
  set_length(length);
  delivered_ = false;
}

void ShippingItem::set_address(Address address) { address_ = address; }

void ShippingItem::set_weight(double weight) {
  if (weight >= 0 && weight <= kMaxWeight) {
    weight_ = weight;
  } else {
    std::string weight_string = std::to_string(weight);
    throw std::out_of_range(weight_string +
                            "Shipping weight must be between 0-70 lbs.");
  }
}

void ShippingItem::set_length(double length) {
  if (length >= kMinSize && length <= kMaxSize) {
    length_ = length;
  } else {
    throw std::out_of_range("Length must be between .007-108 inches.");
  }
}

void ShippingItem::set_delivered(bool delivered) { delivered_ = delivered; }

// other methods
void ShippingItem::MarkDelivered() { delivered_ = true; }
