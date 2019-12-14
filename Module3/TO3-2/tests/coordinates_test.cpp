#include "coordinates.h"
#include "cout_redirect.h"
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Does the Coordinate exists","[start]")
{
    // Arrange
    Coordinates *g = new Coordinates;
    // Act
    // Assert
    CHECK(g != NULL);
}

TEST_CASE("Create Coordinate object with default constructor","[start]")
{
    // Arrange
    Coordinates p1;
    // Act
    // Assert
    CHECK(p1.latitude() == 0);
    CHECK(p1.longitude() == 0);

    // Act
    p1.set_latitude(12.5);
    p1.set_longitude(9.2);
    // Assert
    CHECK(p1.latitude() == Approx(12.5).margin(2));
    CHECK(p1.longitude() == Approx(9.2).margin(2));
}

TEST_CASE("Create Coordinate object with set values","[start]")
{
    // Arrange
    Coordinates p1(33.2, 11.3);
    // Act
    // Assert
    CHECK(p1.latitude() == Approx(33.2).margin(2));
    CHECK(p1.longitude() == Approx(11.3).margin(2));

    // Act
    p1.set_latitude(12.5);
    p1.set_longitude(9.2);
    // Assert
    CHECK(p1.latitude() == Approx(12.5).margin(2));
    CHECK(p1.longitude() == Approx(9.2).margin(2));
}

TEST_CASE("Create a != operator","[part1]")
{
    // Arrange
    Coordinates p1(33.2, 11.3);
    Coordinates p2(33.4, 11.3);
    // Act
    bool test = false;
    if(p1 != p2)
    {
        test = true;
    }
    // Assert
    CHECK(test == true);
    
    // Act
    p2.set_latitude(33.2);
    // Act
    test = false;
    if(p1 != p2)
    {
        test = true;
    }
    // Assert
    CHECK(test == false);
}

TEST_CASE("Create a == operator","[part1]")
{
    // Arrange
    Coordinates p1(33.4, 11.3);
    Coordinates p2(33.4, 11.3);
    // Act
    bool test = false;
    if(p1 == p2)
    {
        test = true;
    }
    // Assert
    CHECK(test == true);
    
    // Act
    p2.set_latitude(33.2);
    // std::cout<<"p1 "<<p1.latitude() << " " <<p1.longitude() << std::endl;
    // std::cout<<"p2 "<<p2.latitude() << " " <<p2.longitude() << std::endl;
    // Act
    test = false;
    if(p1 == p2)
    {
        test = true;
    }
    // Assert
    CHECK(test == false);
}

TEST_CASE("Test output Operator Ogden", "[part2]")
{
  // Arrange
  Coordinates p1(41.222759, -111.970421);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1;               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "lat_: 41.223 long_: -111.970";
  // Assert
  CHECK(s_out == test_string); // compare two strings
}

TEST_CASE("Test output Operator Cape Town", "[part2]")
{
  // Arrange
  Coordinates p1(-33.924870, 18.424055);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1;               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "lat_: -33.925 long_: 18.424";
  // Assert
  CHECK(s_out == test_string); // compare two strings
}

TEST_CASE("Test show_gps Cape Town", "[part3]")
{
  // Arrange
  Coordinates p1(-33.924870, 18.424055);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1.show_gps();               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "33\37055\'29\" S  18\37025\'26\" E" ;
  // Assert
  CHECK(s_out == test_string); // compare two strings
}

TEST_CASE("Test show_gps Ogden", "[part3]")
{
  // Arrange
  Coordinates p1(41.222759, -111.970421);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1.show_gps();               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "41\37013\'21\" N  111\37058\'13\" W" ;
  // Assert
  CHECK(s_out == test_string); // compare two strings
}

TEST_CASE("Test show_gps Madrid", "[part3]")
{
  // Arrange
  Coordinates p1(40.416775,-3.703790);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1.show_gps();               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "40\37025\'0\" N  3\37042\'13\" W" ;
  // Assert
  CHECK(s_out == test_string); // compare two strings
}

TEST_CASE("Test show_gps Beijin", "[part3]")
{
  // Arrange
  Coordinates p1(39.904202,116.407394);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1.show_gps();               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "39\37054\'15\" N  116\37024\'26\" E" ;
  // Assert
  CHECK(s_out == test_string); // compare two strings
}

TEST_CASE("Test show_gps Rio", "[part3]")
{
  // Arrange
  Coordinates p1(-22.906847,-43.172897);
  CoutRedirect buffer; // open buffer to capture output
  // Act
  std::cout<<p1.show_gps();               // Redirect operator
  std::string s_out = buffer.getString(); // get capture output to string
  
  std::string test_string = "22\37054\'24\" S  43\37010\'22\" W" ;
  // Assert
  CHECK(s_out == test_string); // compare two strings
}