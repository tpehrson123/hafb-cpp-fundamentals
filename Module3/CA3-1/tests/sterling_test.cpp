#include "sterling.h"

// These include files are needed if you want to test for output
#include "cout_redirect.h"

// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace Catch::literals;


TEST_CASE("Does the Sterling exists","[part1]")
{
    // Arrange
    Sterling *s = new Sterling;
    // Act
    // Assert
    REQUIRE(s != NULL);
}

TEST_CASE("Check Default Sterling Constructor","[part1]")
{
    // Arrange
    Sterling s;
    // Act
    // Assert
    REQUIRE(s.pounds() == 0);
    REQUIRE(s.shills() == 0);
    REQUIRE(s.pence() == 0);
}

TEST_CASE("Check Sterling Constructor with three inputs","[part1]")
{
    // Arrange
    Sterling s(45, 13, 5);
    // Act
    // Assert
    CHECK(s.pounds() == 45);
    CHECK(s.shills() == 13);
    CHECK(s.pence() == 5);
}

TEST_CASE("Check Sterling Constructor with three inputs and conversion","[part1]")
{
    // Arrange
    Sterling s(45, 59, 25);
    // Act
    // Assert
    CHECK(s.pounds() == 48);
    CHECK(s.shills() == 1);
    CHECK(s.pence() == 1);
}

TEST_CASE("Check Sterling Constructor with old notation and conversion","[part1]")
{
    // Arrange
    Sterling s(45, 59, 25);
    // Act
    // Assert
    CHECK(s.pounds() == 48);
    CHECK(s.shills() == 1);
    CHECK(s.pence() == 1);
}
TEST_CASE("Check Sterling Constructor with string old notation gets old_notation string","[part2]")
{
    // Arrange
    Sterling s("45.19.2");
    // Act
    // Assert
    REQUIRE(s.old_system() == "45.19.2");
}

TEST_CASE("Check Sterling Constructor with string old notation use three getters 1","[part2]")
{
    // Arrange
    Sterling s("45.19.2");
    // Act
    // Assert
    CHECK(s.pounds() == 45);
    CHECK(s.shills() == 19);
    CHECK(s.pence() == 2);
}
TEST_CASE("Check Sterling Constructor with string old notation use three getters 2","[part2]")
{
    // Arrange
    Sterling s("5.1.2");
    // Act
    // Assert
    CHECK(s.pounds() == 5);
    CHECK(s.shills() == 1);
    CHECK(s.pence() == 2);
}


TEST_CASE("Check Sterling Constructor with decimal pound to old notation","[part3]")
{
    // Arrange
    Sterling s(45.67);
    // Act
    // Assert
    CHECK(s.pounds() == 45);
    CHECK(s.shills() == 13);
    CHECK(s.pence() == 5);
}

TEST_CASE("Check Sterling << operator","[part4]")
{
    // Arrange
    Sterling s(45.67);
    // Act
    CoutRedirect buffer;  // open buffer to capture output
    std::cout << s;       // Run output   
    std::string s_out = buffer.getString(); // get capture output

    std::string test = "pounds_: 45 shills_: 13 pence_: 5";
    // Assert
    REQUIRE(s_out == test);
}


TEST_CASE("Check Sterling setting pounds","[part5]")
{
    // Arrange
    Sterling s(45, 13, 5);
    // Act
    s.set_pound(10);
    // Assert
    CHECK(s.pounds() == 10);
    CHECK(s.shills() == 13);
    CHECK(s.pence() == 5);
}

TEST_CASE("Check Sterling setting shills","[part5]")
{
    // Arrange
    Sterling s(45, 13, 5);
    // Act
    s.set_shills(25);
    // Assert
    CHECK(s.pounds() == 46);
    CHECK(s.shills() == 5);
    CHECK(s.pence() == 5);
}

TEST_CASE("Check Sterling setting pence","[part5]")
{
    // Arrange
    Sterling s(45, 13, 5);
    // Act
    s.set_pence(25);
    // Assert
    CHECK(s.pounds() == 45);
    CHECK(s.shills() == 15);
    CHECK(s.pence() == 1);
}

TEST_CASE("Check == operator True","[part6]")
{
    // Arrange
    Sterling s1(11.23);
    Sterling s2(11.23);
    // Act
    // Assert
    REQUIRE(s1 == s2);
}

TEST_CASE("Check == operator False","[part6]")
{
    // Arrange
    Sterling s1(11.23);
    Sterling s2(18.23);
    // Act
    // Assert
    REQUIRE_FALSE(s1 == s2);
}

TEST_CASE("Check != operator True","[part6]")
{
    // Arrange
    Sterling s1(11.23);
    Sterling s2(21.23);
    // Act
    // Assert
    REQUIRE(s1 != s2);
}

TEST_CASE("Check != operator False","[part6]")
{
    // Arrange
    Sterling s1(11.23);
    Sterling s2(11.23);
    // Act
    // Assert
    REQUIRE_FALSE(s1 != s2);
}

TEST_CASE("Check decimal pound","[part7]")
{
    // Arrange
    Sterling s1(11.23);
    // Act
    // Assert
    REQUIRE(s1.decimal_pound() == Approx(11.23).epsilon(0.01));
}


TEST_CASE("Check + operator","[part8]")
{
    // Arrange
    Sterling s1(11.23);
    Sterling s2(7.88);
    // Act
    Sterling s3 = s1 + s2;
    // Assert
    // REQUIRE(s3.decimal_pound() == Approx(18.05).epsilon(0.01));
    REQUIRE(s3.decimal_pound() == Approx(19.11).epsilon(0.01));
}

TEST_CASE("Check - operator","[part8]")
{
    // Arrange
    Sterling s1(11.23);
    Sterling s2(7.88);
    // Act
    Sterling s3 = s1 - s2;
    // Assert
    REQUIRE(s3.decimal_pound() == Approx(3.35).epsilon(0.01));
}