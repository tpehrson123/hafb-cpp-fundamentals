#include <iostream>
#include "distance.h"
    
void Distance::ShowDist() const
{
    std::cout << feet() << "\'-" << inches() << "\"" << std::endl; 
}