#include <iostream>
#include "cars.h"
// using namespace lamborghini;
// using namespace porsche;

// Define a function named 'output' inside the namespace LamborghiniCar
int lamborghini::HorsePower() 
{ 
    return 759;
}

// Define a function named 'output' inside the namespace porsche
int porsche::HorsePower() 
{ 
    return 700;
}

// Define a function named 'output' inside the anonymous namespace
int HorsePower() 
{
    return 120;
}