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
        double length_;  // "_" at end of variable convention for private variables
        double width_;
        double height_;
    public:
         // Constructor: build/create your object
         Carton();
         // Getters  - new naming convention fo getters to use name wo the "_"
         double length();
         double width();
         double height();         

};  // must have a ";"
