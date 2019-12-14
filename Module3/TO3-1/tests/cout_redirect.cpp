/*
**  This library will help you test standard cout with unit test
**
** Made by hvalle
**
** Started on  Tue Aug 20 1:53:42 PM 2019 hvalle
** Last update Tue Aug 20 1:53:42 PM 2019 hvalle
 
TEST_CASE("Check Sterling << operator","[part4]")
    // Arrange
    Sterling s(45.67);
    // Act
    CoutRedirect buffer;  // open buffer to capture output
    std::cout << s;       // Run output   
    std::string s_out = buffer.getString(); // get capture output

    std::string test = "pounds_: 45 shills_: 13 pence_: 5";
    // Assert
    REQUIRE(s_out == test);
*/

#include "cout_redirect.h"


CoutRedirect::CoutRedirect()
{
    old = std::cout.rdbuf(buffer.rdbuf()); // redirect cout to buffer stream
}

std::string CoutRedirect::getString()
{
    return buffer.str(); // get string
}

CoutRedirect::~CoutRedirect()
{
    std::cout.rdbuf(old); // reverse redirect
}