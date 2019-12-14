#include <fstream>
#include <iostream>
#include <string>
#include "using_pointers.h"

using namespace std;

int main() {
  // ofstream out("../tests/integer_test.txt");

  // out << 5829 << " ";

  // int number;
  // for (int i = 0; i < 5829; i++) {
  //   out << rand() << " ";
  // }
  // out.close();

  WriteStats("../no_file.txt", "../stats.txt");
  WriteStats("../integers.txt", "../stats.txt");

  WriteCartons("../no_file.txt", "../cartons_out.txt");
  WriteCartons("../cartons.txt", "../cartons_out.txt");

  return 0;
}