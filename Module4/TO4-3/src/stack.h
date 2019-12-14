#ifndef STACK_H
#define STACK_H

#include <array>
#include <iostream>

template <typename T, int max_size>
class Stack {
 private:
  std::array<T, max_size> stack_;
  int top_position_;

 public:
  // constructors and destructor
  Stack() : top_position_(0){};
  Stack(T item);
  ~Stack(){};

  void Push(T item);
  T Pop();
  T Top() const;
  int Size() const;
  bool Empty() const;
  bool Full() const;
  friend std::ostream& operator<<(std::ostream& out,
                                  const Stack<T, max_size>& rhs) {
    out << "Stack maximum size: " << max_size << std::endl;
    if (rhs.Empty()) {
      out << "The stack is empty" << std::endl;
    } else {
      out << "Stack current size: " << rhs.Size() << std::endl
          << "Value at top of stack: " << rhs.Top() << std::endl;
    }
    return out;
  }
};

template <typename T, int max_size>
Stack<T, max_size>::Stack(T item) : top_position_(0) {
  Push(item);
}

template <typename T, int max_size>
void ::Stack<T, max_size>::Push(T item) {
  if (top_position_ == max_size) {
    throw std::out_of_range("Stack is full. Unable to push value.");
  }

  stack_[top_position_++] = item;
}

template <typename T, int max_size>
T Stack<T, max_size>::Pop() {
  if (top_position_ == 0) {
    throw std::out_of_range("Stack is empty. No value to return.");
  }
  return stack_[--top_position_];
}

template <typename T, int max_size>
T Stack<T, max_size>::Top() const {
  if (top_position_ == 0) {
    throw std::out_of_range("Stack is empty. No value to return.");
  }
  return stack_[top_position_ - 1];
}

template <typename T, int max_size>
int Stack<T, max_size>::Size() const {
  return top_position_;
}

template <typename T, int max_size>
bool Stack<T, max_size>::Empty() const {
  return top_position_ == 0;
}

template <typename T, int max_size>
bool Stack<T, max_size>::Full() const {
  return top_position_ == max_size;
}

#endif