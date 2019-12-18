#include <iostream>
#include "carton.h"

// Constructors have access to private data members
Carton::Carton()
{
    length_ = 0;
    width_ = 0;
    height_ = 0;
}

// Getters
double Carton::length()
{
    return length_;
}
double Carton::width()
{
    return width_;
}
double Carton::height()
{
    return height_;
}

// Setters
void Carton::set_length(double length)
{
    length_ = length;
}
void Carton::set_width(double width)
{
    width_ = width;
}
void Carton::set_height(double height)
{
    height_ = height;
}

void Carton::ShowInfo()
{
    std::cout << "Box height: " << height() << std::endl;
    std::cout << "Box width: " << width() << std::endl;
    std::cout << "Box length: " << length() << std::endl;
}