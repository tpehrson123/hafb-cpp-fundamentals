#include "math3dlib.h"
#include <iostream>
#include <cmath> // for pow() function
using namespace std;

// Global definition of PI
const float kPI = 3.14f;

/**
 * @brief Return the distance between two points
 * 
 * @param a point_a
 * @param b point_b
 * @return abs(distance between points)
 */
int video::Distance(int a, int b) 
{
    return abs(b - a);
}

/**
 * @brief Calculate the circumference based on radius
 * 
 * @param radius input
 * @return circumference
 */
float video::Circumference(float radius) 
{
    // Use the global variable PI
    if(radius > 0)
    {
        return 2 * kPI * (radius);
    }
    else
    {
        return 0;
    }
    
}
/**
 * @brief Bi-dimensional array that displays and adds
 * the sum of a 3*3 array.
 * 
 * @return sum of 3*3 array
 */
int video::BiArray()
{
    int sum = 0;
    // int foo[3][3];               // c-style
    // array<array<int, 3>, 3> foo;  // c++11 style
    array<array<int,3>,3> foo {{
    {11, 25, 73}, {44, 51, -6}, {-72, 80, 92}
    }};
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            // foo[x][y] = x + y;
            sum += foo[x][y];
        }
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout << "foo[" << x << "][" << y << "]: " << foo[x][y] <<endl;
        }
    }
    //
    return sum;
}

/**
 * @brief Get the Max Of object. We need to modify the result, 
 * 	so we need to use non-const references for the arrays
 * 
 * @param array1 
 * @param array2 
 * @param index element to select
 * @return int& reference to the max value of the selected array
 */
int& video::GetMaxOf(array<int, 10>& array1, array<int, 10>& array2, int index) 
{
	if (array1[index] >= array2[index]) 
	{
		return array1[index];
	} 
	else 
	{
		return array2[index];
	}
}


/**
 * @brief Return the distance between two points
 * 
 * @param a point_a
 * @param b point_b
 * @return abs(distance between points)
 */
float video::Distance(float a, float b) 
{
    return fabs(b - a);
}


/**
 * @brief Return the distance between two points
 * 
 * @param a point_a
 * @param b point_b
 * @return abs(distance between points)
 */
float video::Distance(std::array<float, 3> a, std::array<float, 3> b) 
{
    // distance = square root of ( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
    // std::pow(x, 2) == x^2
    return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2) + std::pow(b[2] - a[2], 2));
}


float video::TotalWalkingDistance(const std::array<std::array<float, 3>, 10>& locations) 
{
    float distance_walked_so_far = 0;
    // We keep summing the distance between a locations and the previous one.
    // we start at 1 because the first location (at index 0) has no previous location to compute the distance from.
    for(int current_location = 1; current_location < 10; ++current_location) 
    {
        int previous_location = current_location - 1;
        // We use the overload for points
        float current_distance = video::Distance(locations[previous_location], locations[current_location]);
        distance_walked_so_far += current_distance;
    }
    return distance_walked_so_far;
}