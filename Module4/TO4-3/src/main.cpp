#include <iostream>
#include <string>
#include "carton.h"
#include "stack.h"

using namespace std;

int main() {
  Stack<int, 20> one;
  try {
    one.Push(12);
    one.Push(1342);
    one.Push(943);
    one.Push(302);
  } catch (const out_of_range e) {
    cout << e.what() << '\n';
  }

  cout << one << endl;

  Stack<Carton, 5> carton_stack;

  cout << carton_stack << endl;
  try {
    carton_stack.Push(Carton(23.4, 15.2, 7));
  } catch (const out_of_range e) {
    cout << e.what() << '\n';
  }

  cout << carton_stack << endl;

  cout << one << endl;
  cout << "top value: " << one.Top() << endl;
  try {
    cout << "popped value: " << one.Pop() << endl;
    cout << one << endl;
  } catch (const out_of_range e) {
    cout << e.what() << '\n';
  }
  // try {
  //   cout << "popped value: " << one.Pop() << endl;
  //   cout << one << endl;
  //   cout << "popped value: " << one.Pop() << endl;
  //   cout << one << endl;
  //   cout << "popped value: " << one.Pop() << endl;
  //   cout << one << endl;
  //   cout << "popped value: " << one.Pop() << endl;
  //   cout << one << endl;
  //   cout << "popped value: " << one.Pop() << endl;
  //   cout << one << endl;

  // } catch (const out_of_range e) {
  //   cout << e.what() << '\n';
  // }

  while (!one.Empty()) {
    cout << "popped value: " << one.Pop() << endl;
    cout << one << endl;
  }

  Stack<int, 12> stack1(23);
  cout << stack1 << endl;

  return 0;
}