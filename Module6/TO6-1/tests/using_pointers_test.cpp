// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "using_pointers.h"

TEST_CASE(
    "The WriteStats function writes the integer stats to the file as expected."
    "integer_test.txt."
    "when the file does not open as expected",
    "[write_stats]") {
  WriteStats("../tests/integer_test.txt", "../tests/test.txt");

  std::ifstream input("../tests/test.txt");

  std::string line;
  getline(input, line);
  CHECK(line == "5829");
  getline(input, line);
  CHECK(line == "96210073");
  getline(input, line);
  CHECK(line == "16505.4");
  getline(input, line);
  CHECK(line == "");
  getline(input, line);
  CHECK(line == "");

  input.close();
}

TEST_CASE(
    "The WriteStats function writes 'Unable to open file. Shutting down...' "
    "when the file does not open as expected",
    "[write_stats]") {
  WriteStats("../no_file.txt", "../tests/test.txt");

  std::ifstream input("../tests/test.txt");
  std::string line;
  getline(input, line);
  CHECK(line == "Unable to open file. Shutting down...");

  input.close();
}

TEST_CASE(
    "The WriteCartons function writes the Cartons to the file as expected."
    "when the file does not open as expected",
    "[write_cartons]") {
  WriteCartons("../tests/cartons_test.txt", "../tests/test.txt");

  std::ifstream input("../tests/test.txt");
  std::string line;

  getline(input, line);
  CHECK(line == "A carton with length 41, width 14, and height 14.");
  getline(input, line);
  CHECK(line == "A carton with length 5, width 3.5, and height 3.5.");
  getline(input, line);
  CHECK(line == "A carton with length 7, width 5.5, and height 5.5.");
  getline(input, line);
  CHECK(line == "A carton with length 19, width 17, and height 17.");
  getline(input, line);
  CHECK(line == "A carton with length 73, width 6, and height 6.");
  getline(input, line);
  CHECK(line == "A carton with length 51, width 32, and height 32.");
  getline(input, line);
  CHECK(line == "A carton with length 16, width 16, and height 16.");
  getline(input, line);
  CHECK(line == "A carton with length 24, width 23, and height 23.");
  getline(input, line);
  CHECK(line == "A carton with length 23, width 19, and height 19.");
  getline(input, line);
  CHECK(line == "A carton with length 82, width 12, and height 12.");

  input.close();
}

TEST_CASE(
    "The WriteCartons function writes 'Unable to open file. Shutting down...' "
    "when the file does not open as expected",
    "[write_cartons]") {
  WriteCartons("../no_file.txt", "../tests/test.txt");

  std::ifstream input("../tests/test.txt");
  std::string line;
  getline(input, line);
  CHECK(line == "Unable to open file. Shutting down...");

  input.close();
}
