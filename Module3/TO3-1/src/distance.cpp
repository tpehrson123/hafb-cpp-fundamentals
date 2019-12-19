#include <iostream>
#include "distance.h"

void Distance::ShowDist() const
{
    std::cout << feet() << "\'-" << inches() << "\"" << std::endl;
}

void Distance::update_distance(int ft, float in)
{
    set_feet(ft);
    set_inches(in);
}

/**
 * @brief Plus + Operator for distance objects
 * d3 = d1 + d2
 * @param rhs Second Distance object (rhs Right hand side of + operator)
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

/**
 * @brief Minus Operator for distance objects
 * d3 = d1 - d2
 * @param rhs Second Distance object (rhs Right hand side of + operator)
 * @return Distance Sum of self - d2 objects
 */
Distance Distance::operator-(Distance rhs) const
{
    int temp_feet;
    float temp_inches;

    temp_feet = feet_ - rhs.feet_;
    temp_inches = 0;

    if (inches_ < rhs.inches_)
    {
        temp_feet-= 1;
        temp_inches = (inches_ + 12) - rhs.inches_;
    }

    return Distance(temp_feet, temp_inches);
}

std::ostream &operator<<(std::ostream &os, const Distance &distance)
{
    // Recommended NOT to include a '\n' or endl character (so user has control)
    os << "feet: " << distance.feet_ << " inches: " << distance.inches_;
    return os;
}
