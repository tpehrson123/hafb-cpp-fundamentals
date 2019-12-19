#include <iostream>
#include "distance.h"

void Distance::ShowDist() const
{
    std::cout << feet() << "\'-" << inches() << "\"" << std::endl;
}

/**
 * @brief Plus + Operator for distance objects
 * d3 = d1 + d2
 * @param d2 Second Distance object
 * @return Distance Sum of self + d2 objects
 */
Distance Distance::operator+(Distance rhs) const
{
    int temp_feet;
    float temp_inches;

    temp_feet = feet_ + rhs.feet_;
    temp_inches = inches_ + rhs.inches_;
    if (temp_inches >= 12.0)
    {
        temp_feet++;
        temp_inches -= 12.0;
    }

    return Distance(temp_feet, temp_inches);
}