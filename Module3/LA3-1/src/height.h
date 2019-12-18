/*
** EPITECH PROJECT, 2019
** hafb-cpp-fundamentals
** File description:
** height
*/

#pragma once

class Height
{
private:
    double inches_;

public:
    Height() {inches_ = 0;}
    Height(double inches) : inches_(inches){}
    ~Height() {}

    // Setter & Getter
    double inches() const { return inches_; }
    void set_inches(double inches) { inches_ = inches; }

    // Other methods
    friend void print_feet(Height h1);
};
