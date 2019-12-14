#include "math3dlib.h"
#include <iostream>
#include <array>
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("When given 2 and 8, distance = 6", "[distance1]") 
{
  INFO("distance1 tag: 10 points");
  // Arrange
  int num1 = 2;
  int num2 = 8;
  // Act
  int result = video::Distance(num1, num2);
  // Assert
  CHECK(result == 6);
}

TEST_CASE("When given 21 and 4, distance = 17", "[distance1]") 
{
  INFO("distance1 tag: 10 points");
  // Arrange
  int num1 = 21;
  int num2 = 4;
  // Act
  int result = video::Distance(num1, num2);
  // Assert
  CHECK(result == 17);
}

TEST_CASE("When enemy is 5 m away, circumference = 31.4", "[circumference]") 
{
  INFO("circumference tag: 10 points");
  // Arrange
  float distance = 5;
  // Act
  float enemy_distance = video::Circumference(distance);
  // Assert
  // Approximation with 2 decimals. 
  CHECK(enemy_distance == Approx(31.4).margin(2));
}

TEST_CASE("When enemy is 0.9 m away, circumference = 5.62", "[circumference]") 
{
  INFO("circumference tag: 10 points");
  // Arrange
  float distance = 0.9;
  // Act
  float enemy_distance = video::Circumference(distance);
  // Assert
  // Approximation with 2 decimals. 
  CHECK(enemy_distance == Approx(5.62).margin(2));
}

TEST_CASE("When enemy is -2.8 m away, circumference = 0", "[circumference]") 
{
  INFO("circumference tag: 10 points");
  // Arrange
  float distance = -2.8;
  // Act
  float enemy_distance = video::Circumference(distance);
  // Assert
  // Approximation with 3 decimals. 
  CHECK(enemy_distance == 0);
}

TEST_CASE("Testing your system for the Factor library", "[bi_array]") 
{
  INFO("bi_array tag: 10 points");
  CHECK( video::BiArray() == 298);
}


TEST_CASE("Selecting max of two elements and modify by reference -> does work", "[get_max_of]") 
{
  INFO("get_max_of tag: 10 points");
  // Arrange
  std::array<int, 10> list1 = {11, 22, 37, 41, 53, 66, 79, 80, 95, 101};
  std::array<int, 10> list2 = {45, -95, 820, 9, 61, 32, 41, 70, 95, 120};
  // Act
  for(auto i = 0; i < 10; ++i)
  {
    int &element_r = video::GetMaxOf(list1, list2, i);
    int max_r =list1[i] > list2[i] ? list1[i]: list2[i];
    // Assert
    CHECK(element_r == max_r);
    
    // Act
    ++element_r;
    max_r =list1[i] > list2[i] ? list1[i]: list2[i];
    // Assert
    CHECK(element_r == max_r);
  }
}

TEST_CASE("Selecting max of two elements and modify by value -> does not work", "[get_max_of]") 
{
  INFO("get_max_of tag: 10 points");
  // Arrange
  std::array<int, 10> list1 = {11, 22, 37, 41, 53, 66, 79, 80, 95, 101};
  std::array<int, 10> list2 = {45, -95, 820, 9, 61, 32, 41, 70, 95, 120};
  // Act
  for(auto i = 0; i < 10; ++i)
  {
    int element_v = video::GetMaxOf(list1, list2, i);
    int max_v =list1[i] > list2[i] ? list1[i]: list2[i];
    // Assert
    CHECK(element_v == max_v);
    
    // Act
    ++element_v;
    max_v =list1[i] > list2[i] ? list1[i]: list2[i];
    // Assert
    CHECK(element_v != max_v);
  }
}

TEST_CASE("When given 2.5 and 8.8, distance = 6.3", "[distance2]") 
{
  INFO("distance2 tag: 10 points");
  // Arrange
  float num1 = 2.5;
  float num2 = 8.8;
  // Act
  float result = video::Distance(num1, num2);
  // Assert
  CHECK(result == Approx(6.3));
}

TEST_CASE("When given 12.9 and 2.3, distance = 10.6", "[distance2]") 
{
  INFO("distance2 tag: 10 points");
  // Arrange
  float num1 = 12.9;
  float num2 = 2.3;
  // Act
  float result = video::Distance(num1, num2);
  // Assert
  CHECK(result == Approx(10.6));
}

TEST_CASE("When given points {1,2,3} and {4,5,6}, distance = 5.196f", "[distance_point]") 
{
  INFO("distance_point tag: 15 points");
  // Arrange
  std::array<float, 3> point_a = {1, 2, 3};
  std::array<float, 3> point_b = {4, 5, 6};
  // Act
  float enemy_distance = video::Distance(point_a, point_b);
  // Assert
  // Approximation with 3 decimals. 
  CHECK(enemy_distance == Approx(5.196).margin(3));
}

TEST_CASE("When given points {1,-2,-3} and {8,5,-6}, distance = 10.344f", "[distance_point]") 
{
  INFO("distance_point tag: 15 points");
  // Arrange
  std::array<float, 3> point_a = {1, -2, -3};
  std::array<float, 3> point_b = {8, 5, -6};
  // Act
  float enemy_distance = video::Distance(point_a, point_b);
  // Assert
  // Approximation with 3 decimals. 
  CHECK(enemy_distance == Approx(10.344).margin(3));
}

TEST_CASE("When given one point {1,2,3} distance = 3.741f", "[distance_point]") 
{
  INFO("distance_point tag: 15 points");
  // Arrange
  std::array<float, 3> point_a = {1, 2, 3};
  // Act
  float enemy_distance = video::Distance(point_a);
  // Assert
  // Approximation with 3 decimals. 
  CHECK(enemy_distance == Approx(3.741).margin(3));
}


TEST_CASE("When given 5 points total distance = 5.414", "[total]") 
{
  INFO("total tag: 20 points");
  // Arrange
  // An array of arrays
  std::array<std::array<float, 3>, 10> enemy_movement {{
    {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 1, 1} 
    }};
  // Act
  float total_distance = video::TotalWalkingDistance(enemy_movement);
  // Assert
  // Approximation with 3 decimals. 
  CHECK(total_distance == Approx(5.414).margin(3));
}

TEST_CASE("When given 10 points total distance = 61.583", "[total]") 
{
  INFO("total tag: 20 points");
  // Arrange
  // An array of arrays
  std::array<std::array<float, 3>, 10> enemy_movement {{
        {0, 1, 2},
        {2, -3, 0},
        {2, 3, 3}, 
        {5, 3, 3}, 
        {8, 3, 3},
        {-8, 3, 2},
        {2, 3, 2}, 
        {2, -3, 1}, 
        {-2, 3, 0}, 
        {0, 2, 4}
    }};
  // Act
  float total_distance = video::TotalWalkingDistance(enemy_movement);
  // Assert
  // Approximation with 3 decimals. 
  CHECK(total_distance == Approx(61.583).margin(3));
}