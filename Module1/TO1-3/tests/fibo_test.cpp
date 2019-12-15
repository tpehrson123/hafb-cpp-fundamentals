#include "fibo.h"
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/**
 * @brief Testing function
 * 
 */
TEST_CASE("Getting the 1st Fibo Number", "[TO1-3]") 
{
  INFO("TO Activity 3 Points");
  CHECK( GetTenthFibonacci(0) == 0);
}

TEST_CASE("Getting the 2nd Fibo Number", "[TO1-3]") 
{
  INFO("TO Activity 3 Points");
  CHECK( GetTenthFibonacci(2) == 1);
}

TEST_CASE("Getting the 9th Fibo Number", "[TO1-3]") 
{
  INFO("TO Activity 3 Points");
  CHECK( GetTenthFibonacci(9) == 34);
}