/*
** EPITECH PROJECT, 2019
** hafb-cpp-fundamentals
** File description:
** carton
*/

#pragma once

// Create your first class
class Carton
{
private:
    double length_; // "_" at end of variable convention for private variables
    double width_;
    double height_;

public:

    // Static constants (shared between all objects)
    // static const double kMaxsize;
    static const double kMinLength;
    static const double kMinWidth;
    static const double kMinHeight;

    // Constructor: build/create your object
    Carton();
    Carton(double length, double width, double height);

    ~Carton();

    // Getters  - new naming convention fo getters to use name wo the "_"
    double length();
    double width();
    double height();

    // Setters - new naming convention
    void set_length(double length);
    void set_width(double width);
    void set_height(double height);

    // Other methods
    void SetMeasurements(double length, double width, double height);
    void ShowInfo();
    double Volume() const;

}; // must have a ";"
