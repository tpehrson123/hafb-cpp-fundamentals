// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "carton.h"
#include "stack.h"

const int kMaxSize = 12;

//******************* int Stack ************************

TEST_CASE(
    "Default constructor creates an Stack with size = 0 "
    "when stack is of type int.",
    "[constructor][size][int]") {
  Stack<int, kMaxSize> stack;
  CHECK(stack.Size() == 0);
}

TEST_CASE(
    "Non-default constructor creates a Stack with a single item, "
    "Top method returns item added, and Size method returns 1."
    "size 1, and top equal to item when stack is of type int.",
    "[constructor][top][size][int]") {
  Stack<int, kMaxSize> stack(23);
  CHECK(stack.Size() == 1);
  CHECK(stack.Top() == 23);
}

TEST_CASE(
    "Push method adds item to stack, increases size, and top is equal to added "
    "Top method returns top value, and Size method returns expected size "
    "item when stack is of type int.",
    "[push][top][size][int]") {
  Stack<int, kMaxSize> stack;
  CHECK(stack.Size() == 0);
  stack.Push(95);
  CHECK(stack.Size() == 1);
  CHECK(stack.Top() == 95);
  stack.Push(78);
  CHECK(stack.Size() == 2);
  CHECK(stack.Top() == 78);
}

TEST_CASE(
    "Push method throws out_of_range exception when called after stack is full "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type int.",
    "[push][top][size][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(i);

    CHECK(stack.Size() == i + 1);
    CHECK(stack.Top() == i);
  }
  CHECK_THROWS_AS(stack.Push(23), std::out_of_range);
}

TEST_CASE(
    "Pop method returns top value, and reduces size of stack "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type int.",
    "[pop][top][size][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(i);

    CHECK(stack.Size() == i + 1);
    CHECK(stack.Top() == i);
  }
  for (int i = kMaxSize - 1; i > -1; i--) {
    CHECK(stack.Top() == i);
    CHECK(stack.Pop() == i);
    CHECK(stack.Size() == i);
  }
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is  "
    "empty (just created) when stack is of type int.",
    "[pop][int]") {
  Stack<int, kMaxSize> stack;
  CHECK_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is "
    "empty (Push and Pop used) when stack is of type int.",
    "[pop][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < 5; i++) {
    stack.Push(i);
  }
  for (int i = 0; i < 5; i++) {
    stack.Pop();
  }
  CHECK_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Full method returns true when stack is full and false when it is not full "
    "when stack is of type int.",
    "[full][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    CHECK(!stack.Full());
    stack.Push(i);
  }
  CHECK(stack.Full());
}

TEST_CASE(
    "Empty method returns true when stack is empty and false when it is not "
    "empty when stack is of type int.",
    "[empty][int]") {
  Stack<int, kMaxSize> stack;
  CHECK(stack.Empty());
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(i);
    CHECK(!stack.Empty());
  }
  for (int i = 0; i < kMaxSize; i++) {
    CHECK(!stack.Empty());
    stack.Pop();
  }
  CHECK(stack.Empty());
}

TEST_CASE(
    "<< operator prints Stack maximum size: and The stack is empty when stack "
    "is empty "
    "empty when stack is of type int.",
    "[empty][int]") {
  Stack<int, kMaxSize> stack;
  std::ofstream out("test.out");
  out << stack << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  CHECK("Stack maximum size: " + std::to_string(kMaxSize) == line);
  getline(in, line);
  CHECK("The stack is empty" == line);
  getline(in, line);
  CHECK("" == line);
}

TEST_CASE(
    "<< operator prints Stack maximum size: , Stack current size:, and "
    "Value at top of stack: when stack is not empty  "
    "empty when stack is of type int.",
    "[empty][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < 3; i++) {
    stack.Push(i);
  }

  std::ofstream out("test.out");
  out << stack << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  CHECK("Stack maximum size: " + std::to_string(kMaxSize) == line);
  getline(in, line);
  CHECK("Stack current size: 3" == line);
  getline(in, line);
  CHECK("Value at top of stack: 2" == line);
  getline(in, line);
  CHECK("" == line);
}

//******************* string Stack ************************

TEST_CASE(
    "Default constructor creates an Stack with size = 0 "
    "when stack is of type string.",
    "[constructor][size][string]") {
  Stack<std::string, kMaxSize> stack;
  CHECK(stack.Size() == 0);
}

TEST_CASE(
    "Non-default constructor creates a Stack with a single item, "
    "Top method returns item added, and Size method returns 1."
    "size 1, and top equal to item when stack is of type string.",
    "[constructor][top][size][string]") {
  Stack<std::string, kMaxSize> stack("green");
  CHECK(stack.Size() == 1);
  CHECK(stack.Top() == "green");
}

TEST_CASE(
    "Push method adds item to stack, increases size, and top is equal to added "
    "Top method returns top value, and Size method returns expected size "
    "item when stack is of type std::string.",
    "[push][top][size][string]") {
  Stack<std::string, kMaxSize> stack;
  CHECK(stack.Size() == 0);
  stack.Push("green");
  CHECK(stack.Size() == 1);
  CHECK(stack.Top() == "green");
  stack.Push("blue");
  CHECK(stack.Size() == 2);
  CHECK(stack.Top() == "blue");
}

TEST_CASE(
    "Push method throws out_of_range exception when called after stack is full "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type std::string.",
    "[push][top][size][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(std::to_string(i));

    CHECK(stack.Size() == i + 1);
    CHECK(stack.Top() == std::to_string(i));
  }
  CHECK_THROWS_AS(stack.Push("yellow"), std::out_of_range);
}

TEST_CASE(
    "Pop method returns top value, and reduces size of stack "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type std::string.",
    "[pop][top][size][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(std::to_string(i));

    CHECK(stack.Size() == i + 1);
    CHECK(stack.Top() == std::to_string(i));
  }
  for (int i = kMaxSize - 1; i > -1; i--) {
    CHECK(stack.Top() == std::to_string(i));
    CHECK(stack.Pop() == std::to_string(i));
    CHECK(stack.Size() == i);
  }
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is  "
    "empty (just created) when stack is of type std::string.",
    "[pop][string]") {
  Stack<std::string, kMaxSize> stack;
  CHECK_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is "
    "empty (Push and Pop used) when stack is of type std::string.",
    "[pop][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < 5; i++) {
    stack.Push(std::to_string(i));
  }
  for (int i = 0; i < 5; i++) {
    stack.Pop();
  }
  CHECK_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Full method returns true when stack is full and false when it is not full "
    "when stack is of type std::string.",
    "[full][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    CHECK(!stack.Full());
    stack.Push(std::to_string(i));
  }
  CHECK(stack.Full());
}

TEST_CASE(
    "Empty method returns true when stack is empty and false when it is not "
    "empty when stack is of type std::string.",
    "[empty][string]") {
  Stack<std::string, kMaxSize> stack;
  CHECK(stack.Empty());
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(std::to_string(i));
    CHECK(!stack.Empty());
  }
  for (int i = 0; i < kMaxSize; i++) {
    CHECK(!stack.Empty());
    stack.Pop();
  }
  CHECK(stack.Empty());
}

TEST_CASE(
    "<< operator prints Stack maximum size: and The stack is empty when stack "
    "is empty when stack is of type std::string.",
    "[empty][string]") {
  Stack<std::string, kMaxSize> stack;
  std::ofstream out("test.out");
  out << stack << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  CHECK("Stack maximum size: " + std::to_string(kMaxSize) == line);
  getline(in, line);
  CHECK("The stack is empty" == line);
  getline(in, line);
  CHECK("" == line);
}

TEST_CASE(
    "<< operator prints Stack maximum size: , Stack current size:, and "
    "Value at top of stack: when stack is not empty  "
    "empty when stack is of type std::string.",
    "[empty][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < 3; i++) {
    stack.Push(std::to_string(i));
  }

  std::ofstream out("test.out");
  out << stack << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  CHECK("Stack maximum size: " + std::to_string(kMaxSize) == line);
  getline(in, line);
  CHECK("Stack current size: 3" == line);
  getline(in, line);
  CHECK("Value at top of stack: 2" == line);
  getline(in, line);
  CHECK("" == line);
}

//************************ Carton Stack *****************************
 
TEST_CASE(
    "The << operator prints Cartons as Carton length x width x height with a "
    "precision of one digit after the decimal",
    "[insertion][carton]") {
  // test size
  Carton one(22, 7, 19.38);
  Carton two(8, 20, 9.54);

  std::ofstream out("test.out");
  out << one << std::endl;
  out << two << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  if (fabs(one.width() - 7.0) < .001) {
    CHECK("Carton 22.0 x 7.0 x 19.4" == line);
  } else {
    CHECK("Carton 22.0 x 19.4 x 7.0" == line);
  }

  getline(in, line);

  if (fabs(one.width() - 8.0) < .001) {
    CHECK("Carton 20.0 x 8.0 x 9.5" == line);
  } else {
    CHECK("Carton 20.0 x 9.5 x 8.0" == line);
  }
  getline(in, line);
  CHECK("" == line);
}

TEST_CASE(
    "Default constructor creates an Stack with size = 0 "
    "when stack is of type Carton.",
    "[constructor][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  CHECK(stack.Size() == 0);
}

TEST_CASE(
    "Non-default constructor creates a Stack with a single item, "
    "Top method returns item added, and Size method returns 1."
    "size 1, and top equal to item when stack is of type Carton.",
    "[constructor][top][size][carton]") {
  Stack<Carton, kMaxSize> stack(Carton(22, 7, 19.38));
  CHECK(stack.Size() == 1);
  Carton one(22, 7, 19.38);
  CHECK(fabs(stack.Top().Volume() - one.Volume()) < .1);
}

TEST_CASE(
    "Push method adds item to stack, increases size, and top is equal to added "
    "Top method returns top value, and Size method returns expected size "
    "item when stack is of type Carton.",
    "[push][top][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  CHECK(stack.Size() == 0);
  stack.Push(Carton(16, 8, 20));
  CHECK(stack.Size() == 1);

  Carton one(16, 8, 20);
  CHECK(fabs(stack.Top().Volume() - one.Volume()) < .1);
  stack.Push(Carton(8, 20, 9.54));
  CHECK(stack.Size() == 2);

  Carton two(8, 20, 9.54);
  CHECK(fabs(stack.Top().Volume() - two.Volume()) < .1);
}

TEST_CASE(
    "Push method throws out_of_range exception when called after stack is full "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type Carton.",
    "[push][top][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(Carton(14, i + 7, 12));
    Carton two;
    CHECK(stack.Size() == i + 1);
    two = Carton(14, i + 7, 12);
    CHECK(fabs(stack.Top().Volume() - two.Volume()) < .1);
  }
  CHECK_THROWS_AS(stack.Push(Carton(14, 9.6, 12)), std::out_of_range);
}

TEST_CASE(
    "Pop method returns top value, and reduces size of stack "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type Carton.",
    "[pop][top][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  Carton two;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(Carton(20.8, i + 7, 14.2));

    CHECK(stack.Size() == i + 1);
    two = Carton(20.8, i + 7, 14.2);
    CHECK(fabs(stack.Top().Volume() - two.Volume()) < .1);
  }
  for (int i = kMaxSize - 1; i > -1; i--) {
    two = Carton(20.8, i + 7, 14.2);
    CHECK(fabs(stack.Top().Volume() - two.Volume()) < .1);
    CHECK(fabs(stack.Pop().Volume() - two.Volume()) < .1);
    CHECK(stack.Size() == i);
  }
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is  "
    "empty (just created) when stack is of type Carton.",
    "[pop][carton]") {
  Stack<Carton, kMaxSize> stack;
  CHECK_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is "
    "empty (Push and Pop used) when stack is of type Carton.",
    "[pop][carton]") {
  Stack<Carton, kMaxSize> stack;
  for (int i = 0; i < 5; i++) {
    stack.Push(Carton(i + 7, 7.8, 19.3));
  }
  for (int i = 0; i < 5; i++) {
    stack.Pop();
  }
  CHECK_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Full method returns true when stack is full and false when it is not full "
    "when stack is of type Carton.",
    "[full][carton]") {
  Stack<Carton, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    CHECK(!stack.Full());
    stack.Push(Carton(i + 7, 7.8, 19.3));
  }
  CHECK(stack.Full());
}

TEST_CASE(
    "Empty method returns true when stack is empty and false when it is not "
    "empty when stack is of type Carton.",
    "[empty][carton]") {
  Stack<Carton, kMaxSize> stack;
  CHECK(stack.Empty());
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(Carton(i + 7, 7.8, 19.3));
    CHECK(!stack.Empty());
  }
  for (int i = 0; i < kMaxSize; i++) {
    CHECK(!stack.Empty());
    stack.Pop();
  }
  CHECK(stack.Empty());
}

TEST_CASE(
    "<< operator prints Stack maximum size: and The stack is empty when stack "
    "is empty when stack is of type Carton.",
    "[empty][carton]") {
  Stack<Carton, kMaxSize> stack;
  std::ofstream out("test.out");
  out << stack << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  CHECK("Stack maximum size: " + std::to_string(kMaxSize) == line);
  getline(in, line);
  CHECK("The stack is empty" == line);
  getline(in, line);
  CHECK("" == line);
}

TEST_CASE(
    "<< operator prints Stack maximum size: , Stack current size:, and "
    "Value at top of stack: when stack is not empty  "
    "empty when stack is of type Carton.",
    "[empty][carton]") {
  Stack<Carton, kMaxSize> stack;
  Carton next_carton;
  for (int i = 0; i < 3; i++) {
    next_carton = Carton(i + 20, 7.8, 19.3);
    stack.Push(next_carton);
  }
  std::string expected_top;
  if (fabs(next_carton.width() - 7.8) < .001) {
    expected_top = "Value at top of stack: Carton 22.0 x 7.8 x 19.3";
  } else {
    expected_top = "Value at top of stack: Carton 22.0 x 19.3 x 7.8";
  }

  std::ofstream out("test.out");
  out << stack << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  CHECK("Stack maximum size: " + std::to_string(kMaxSize) == line);
  getline(in, line);
  CHECK("Stack current size: 3" == line);
  getline(in, line);
  CHECK(expected_top == line);
  getline(in, line);
  CHECK("" == line);
}
