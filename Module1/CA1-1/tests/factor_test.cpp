#include "factor.h"
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/**
 * @brief Testing function
 * 
 */
TEST_CASE("Testing your system for the Factor library", "[M1]") 
{
  REQUIRE( FactorMod7() == 14);
}