#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Get all values < 10 from a vector
    std::vector<int> numbers = {1, 2, 3, 4};
    bool all_less_than10 = std::all_of(numbers.begin(), numbers.end(), [](int value){ return value < 10;});
    std::cout << "All are less than 10: " << all_less_than10 << std::endl;

    // Some are even numbers
    bool some_are_even = std::any_of(numbers.begin(), numbers.end(), [](int value){ return value % 2 == 0;});
    std::cout << "Some are even: " << all_less_than10 << std::endl;

    // None are negative
    bool none_are_negative = std::none_of(numbers.begin(), numbers.end(), [](int value) { return value < 0;});
    std::cout << "None are negative " << none_are_negative << std::endl;
    
    // Count even numbers
    int odd_numbers = std::count_if(numbers.begin(), numbers.end(), [](int value){ return value % 2 == 1;});
    std::cout << "Odd Numbers: " << odd_numbers << std::endl;

    // Let the system determine the type, and find some number
    // Note: find is NOT index notation. 0 means not found
    auto position = std::find(numbers.begin(), numbers.end(), 6);
    std::cout << "6 was found: " << (position != numbers.end()) << std::endl;
    position = std::find(numbers.begin(), numbers.end(), 1);
    std::cout << "1 was found: " << (position != numbers.end()) << std::endl;


    return 0;
}