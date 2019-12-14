#ifndef KEY_VALUE_H
#define KEY_VALUE_H

#include <array>
#include <iostream>

template <typename TK, typename TV, int max_size>
class KeyValue {
 private:
  std::array<TK, max_size> keys_;
  std::array<TV, max_size> values_;
  int size_ = 0;
  int Find(TK key) const;

 public:
  KeyValue();
  ~KeyValue(){};

  int size() const { return size_; }
  void Add(TK key, TV item);
  bool RemoveOne(TK key);
  int RemoveAll(TK key);
  bool Found(TK key) const;
  TV ValueAt(TK key) const;
  bool Full() const;
  bool Empty() const;
  friend std::ostream& operator<<(std::ostream& out,
                                  const KeyValue<TK, TV, max_size>& rhs) {
    for (int i = 0; i < rhs.size_; i++) {
      out << rhs.keys_[i] << ": " << rhs.values_[i] << std::endl;
    }
    return out;
  }
};

template <typename TK, typename TV, int max_size>
KeyValue<TK, TV, max_size>::KeyValue() {
  size_ = 0;
}

template <typename TK, typename TV, int max_size>
void KeyValue<TK, TV, max_size>::Add(TK key, TV item) {
  if (size_ >= max_size) {
    throw std::out_of_range("KeyValue is full. Unable to add key/value.");
  }
  keys_[size_] = key;
  values_[size_] = item;
  size_++;
}

template <typename TK, typename TV, int max_size>
int KeyValue<TK, TV, max_size>::Find(TK key) const {
  for (int i = 0; i < size_; i++) {
    if (keys_[i] == key) {
      return i;
    }
  }

  return -1;
}

template <typename TK, typename TV, int max_size>
bool KeyValue<TK, TV, max_size>::Found(TK key) const {
  if (Find(key) == -1) {
    return false;
  }
  return true;
}

template <typename TK, typename TV, int max_size>
TV KeyValue<TK, TV, max_size>::ValueAt(TK key) const {
  if (!Found(key)) {
    throw std::out_of_range("Key not found");
  }
  return values_[Find(key)];
}

template <typename TK, typename TV, int max_size>
bool KeyValue<TK, TV, max_size>::Empty() const {
  return size_ == 0;
}

template <typename TK, typename TV, int max_size>
bool KeyValue<TK, TV, max_size>::Full() const {
  return size_ == max_size;
}

template <typename TK, typename TV, int max_size>
bool KeyValue<TK, TV, max_size>::RemoveOne(TK key) {
  if (Empty()) {
    // empty, return false
    return false;
  }
  int location = Find(key);
  if (location == -1) {
    // not found, return false
    return false;
  } else {
    // remove from array
    // loop through array above item, shift keys and values down by one
    for (int i = location; i < size_ - 1; i++) {
      // move key
      keys_[i] = keys_[i + 1];
      // move value
      values_[i] = values_[i + 1];
    }
    // decrement size_
    size_--;
    // found and removed
    return true;
  }
}

template <typename TK, typename TV, int max_size>
int KeyValue<TK, TV, max_size>::RemoveAll(TK key) {
  if (Empty()) {
    return 0;
  }
  int count = 0;
  while (RemoveOne(key)) {
    count++;
  }
  return count;
}

#endif