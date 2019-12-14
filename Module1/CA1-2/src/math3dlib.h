#ifndef MATH_3D_LIB_H
#define MATH_3D_LIB_H

#include <array>

namespace video
{
// Part 1
int Distance(int a, int b);

// Part 2: 
float Circumference(float radius);
int BiArray();
int& GetMaxOf(std::array<int, 10> &array1, std::array<int, 10> &array2, int index);

// Part 3: 
// Overload distance so it is easy to use
float Distance(float a, float b);
// The point are taken by value because they are small.
// We define a default value for argument 'b' to be the origin.
float Distance(std::array<float, 3> a, std::array<float, 3> b = {0, 0, 0});

// The array of locations is big, so we use a reference. Since we do not modify it,
// we also use const.
float TotalWalkingDistance(const std::array<std::array<float, 3>, 10> &locations);
} // end of video namespace
#endif
