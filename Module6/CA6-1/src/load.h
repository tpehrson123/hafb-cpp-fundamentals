#ifndef LOAD_H
#define LOAD_H

#include <array>
#include <iostream>
#include <vector>
#include "shipping_item.h"

class Load {
 private:
  std::vector<ShippingItem *> items_;
  int current_item_;
  double count_;
  double total_weight_;
  double total_volume_;

 public:
  // constructors and destructor
  Load() : current_item_(0), total_volume_(0), total_weight_(0), count_(0) {}
  ~Load();

  // getters
  int count() const { return count_; }
  double total_volume() const { return total_volume_; }
  double total_weight() const { return total_weight_; }

  // other methods
  void FillLoad(std::string filename);
  void DisplayNextDelivery(std::ofstream &out) const;
  void ItemDelivered();
  void NotDeliverable();
  int HowManyDelivered() const;
  int HowManyNotDelivered() const;
};

#endif