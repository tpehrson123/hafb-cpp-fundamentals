#include <iostream>
#include "math3dlib.h"
using namespace std;

int main()
{
    /**
     * Part 1
     * 
     */
    // int Distance(int point_a, int point_b) function
    int p1, p2 = 0;
    cout << "\n********Part 1********\n";
    cout << "Enter two integer points: ";
    cin >> p1 >> p2;
    cout << "Distance between " << p1 << " and "
        << p2 << " = " << video::Distance(p1, p2) << endl;
    
    // /**
    //  * Part 2
    //  * 
    //  */
    // Circumference() Function
    float radius = 0;
    cout << "\n********Part 2********\n";
    cout << "Enter circle radius: ";
    cin >> radius;
    cout << "With radius " << radius << " circumference = "
        << video::Circumference(radius) << endl;

    // BiArray() Function
    auto sum = video::BiArray();
    cout << "The sum of 3*3 array is: " << sum << endl;
    
    // get_max_of() Function
    array<int, 10> sorted = {11, 22, 37, 41, 53, 66, 79, 80, 95, 101};
    array<int, 10> reversed = {101, 95, 80, 79, 66, 53, 41, 37, 22, 11};
    cout << "sorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << endl;

    // We want to modify the element, so we need to make sure we take the result as reference.
    // If we were to return the result as a value, when we modify it it will not propagate
    // to the original element
    int& element = video::GetMaxOf(sorted, reversed, 0);
    cout << "\nMax Element: " << element << endl;

    element = 0;    // update value by reference
    cout << "\nsorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << endl;
    cout << "The original value has been updated though the reference!" << endl;

    // Note: we are taking by value. This creates a new local copy, and changes to it will not modify
    // the original value
    int value = video::GetMaxOf(sorted, reversed, 0);
    value = 10;
    cout << "\nsorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << endl;
    cout << "The original value has *not* been updated though the value!" << endl;
    
    /**
     * Part 3
     * 
     */
    
    std::array<float, 3> enemy1_location = {2, 2 ,0};
    std::array<float, 3> enemy2_location = {2, 4 ,0};

    float enemy_distance = video::Distance(enemy1_location, enemy2_location);
    float distance_from_center = video::Distance(enemy1_location);

    float view_circumference_for_enemy = video::Circumference(34.5);
    float total_distance = video::TotalWalkingDistance(
        { enemy1_location,
        {2, 3, 0}, // y += 1
        {2, 3, 3}, // z += 3
        {5, 3, 3}, // x += 3
        {8, 3, 3}, // x += 3
        {8, 3, 2}, // z -= 1
        {2, 3, 2}, // x -= 6
        {2, 3, 1}, // z -= 1
        {2, 3, 0}, // z -= 1
        enemy2_location
    });

    std::cout << "The two enemies are " << enemy_distance << "m apart and can see for a circumference of "
              << view_circumference_for_enemy << "m. To go to from one to the other they need to walk "
              << total_distance << "m.";

    return 0;
}