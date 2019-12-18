#include <iostream>
#include "carton.h"
#include <string>

// const double Carton::kMaxsize = 100;
const double Carton::kMinLength = 6;
const double Carton::kMinWidth = 3;
const double Carton::kMinHeight = 0.25;

// Constructors have access to private data members
Carton::Carton()
{
    length_ = 0;
    width_ = 0;
    height_ = 0;
}

Carton::Carton(double length, double width, double height)
{
    try
    {
        SetMeasurements(length, width, height);
    }
    catch (std::out_of_range e)
    {
        std::cerr << e.what() << '\n';
        std::cout << e.what() << '\n';
        std::cout << "In catch block" << std::endl;
        throw;
    }
}

// Destructor
Carton::~Carton()
{
}

void Carton::SetMeasurements(double length, double width, double height)
{
    if (length <= 0 || width <= 0 || height <= 0)
    {
        throw std::out_of_range("All measurements must be greater than zero");
    }

    // Good to go
    height_ = height;
    width_ = width;
    length_ = length;
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
    if (length < kMinLength)
    {
        std::string error_msg = "Length must be greater than " + std::to_string(kMinLength);
        throw std::out_of_range(error_msg);
    }
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

    std::cout << std::endl;
    std::cout << "Box height: " << height() << std::endl;
    std::cout << "Box width: " << width() << std::endl;
    std::cout << "Box length: " << length() << std::endl;

    std::cout << "Box volume: " << Volume() << std::endl;

    std::cout << std::endl;
}

double Carton::Volume() const
{
    return length_ * width_ * height_;
}