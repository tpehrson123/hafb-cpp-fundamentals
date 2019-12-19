/**
 * @file my_sets.cpp
 * @author your name (you@domain.com)
 * @brief 
 * Elements are sorted according to the values
 * Elements are distinct values
 * @version 0.1
 * @date 2019-12-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
using namespace std;
#include <set> // Container with a UNIQUE group SORTED elements
// Methods: size(), empty(), insert(), erase(), find()
// find() : returns the position of the first element equal to the provided value
//          you should always compare the value against the end() of the container

int main()
{
    std::set<int> numbers;
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);
    numbers.insert(30);  // Will override previous 30 add (sets do not include duplicates!)

    // search for a value
    if (numbers.find(10) != numbers.end()) // end() is NOT the last element, but then end of set...
    {
        std::cout << "10 is in numbers" << std::endl;
    }

    cout << "The set has: " << numbers.size() << " elements" << endl;

    cout << "Using iterator" << endl;
    for (auto it = begin(numbers); it != end(numbers); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}