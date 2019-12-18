#include "carton.h"

// Constructors have access to private data members
Carton::Carton()
{
    length_ = 0;
    width_ = 0;
    height_ = 0;
}

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