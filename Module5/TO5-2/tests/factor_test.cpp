#include "factor.h"
#include "cout_redirect.h"    // To test cout <<
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/**
 * @brief Sample to test a function returning an int value
 * 
 */
TEST_CASE("Testing your system for the Factor library", "[M1]") 
{
  CHECK( FactorMod7() == 14);
}


/**
 * @brief Sample to test a void function. 
 * We will capture the cout and compare the output string 
 * 
 */
TEST_CASE("Testing cout from void function", "[M1]")
{
  // Arrange
  CoutRedirect buffer; // open buffer to capture output
  // Output string to compare. Note: if you have a << endl in your function,
  // you need to include the "\n" as part of your test string.
  std::string test_string = "Hello World!\n";
  // Act
  Hello();                                // Run Void function with output
  std::string s_out = buffer.getString(); // get capture output to string
  // Assert
  CHECK(s_out == test_string);    // compare two strings
}