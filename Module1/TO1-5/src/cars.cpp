#include <iostream>
#include "cars.h"

int HorsePower()
{
    return 150;
}

// using namespace lamborghini;
int lamborghini::HorsePower()
{
    return 760;
}

void lamborghini::cout()
{
    std::cout << "My car is a lamborghini!" << std::endl;
}

// using namespace porsche;
int porsche::HorsePower()
{
    return 700;
}
