#include "height.h"
#include <iostream>

// Friend functions have access to private data members.
// When writing definition, DO NOT include the friend keyword, 
// nor the class :: scope
// Just like a regular function with special access
void print_feet(Height h1)
{
    std::cout << "Your height in inches is : " <<
    h1.inches_ << std::endl;
    std::cout << "Your height in feet is : " <<
    h1.inches_/12 << std::endl;
}
