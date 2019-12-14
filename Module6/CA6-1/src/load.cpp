#include "load.h"

#include <fstream>
#include <string>
#include "carton.h"
#include "flat.h"
#include "tube.h"

// constructors and destructor
Load::~Load() {
  for (auto &one_ptr : items_) {
    delete one_ptr;
  }
}

// other methods
void Load::FillLoad(std::string filename) {
  std::ifstream in(filename);
  char type;
  Address address;
  double weight;
  double length;
  double width;
  double height;
  double circumference;
  double thickness;

  while (in >> type) {
    // read next item from file'
    in.ignore();
    getline(in, address.name);
    getline(in, address.street_address);
    getline(in, address.city);
    getline(in, address.state);
    getline(in, address.zip);

    switch (type) {
      case 'F':
        in >> weight >> length >> height >> thickness;
        items_.push_back(new Flat(address, weight, length, height, thickness));
        break;
      case 'C':
        in >> weight >> length >> width >> height;
        items_.push_back(new Carton(address, weight, length, width, height));
        break;
      case 'T':
        in >> weight >> length >> circumference;
        items_.push_back(new Tube(address, weight, length, circumference));
        break;
      default:
        throw std::out_of_range("Invalid shipping item type");
        break;
    }
    count_++;
    total_volume_ += items_.back()->Volume();
    total_weight_ += items_.back()->weight();
  }
}

void Load::DisplayNextDelivery(std::ofstream &out) const {
  if (current_item_ < items_.size()) {
    out << items_[current_item_]->address().name << std::endl
        << items_[current_item_]->address().street_address << std::endl
        << items_[current_item_]->address().city << ", "
        << items_[current_item_]->address().state << " "
        << items_[current_item_]->address().zip << std::endl;
    items_[current_item_]->Display(out);
  } else {
    out << "No more items to deliver" << std::endl;
  }
}

void Load::ItemDelivered() {
  items_[current_item_]->MarkDelivered();
  current_item_++;
}

void Load::NotDeliverable() { current_item_++; }

int Load::HowManyDelivered() const {
  int count = 0;
  for (auto one_ptr : items_) {
    if (one_ptr->delivered()) {
      count++;
    }
  }
  return count;
}
int Load::HowManyNotDelivered() const {
  int count = 0;
  for (auto one_ptr : items_) {
    if (!one_ptr->delivered()) {
      count++;
    }
  }
  return count;
}
