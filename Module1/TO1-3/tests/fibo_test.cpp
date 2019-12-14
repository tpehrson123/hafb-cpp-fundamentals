#include "fibo.h"
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/**
 * @brief Testing function
 * 
 */
TEST_CASE("Getting the 10th Fibo Number", "[TO1-3]") 
{
  INFO("TO Activity 3 Points");
  REQUIRE( GetTenthFibonacci() == 144);
}