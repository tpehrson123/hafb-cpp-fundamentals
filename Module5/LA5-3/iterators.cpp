#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3};
    // loop using iterator version 1
    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << "The number is: " << *it << std::endl;
    }
    // loop using iterator version 2
    for(auto number: numbers)
    {
        std::cout << "The number is: " << number << std::endl;
    }


    std::vector<int> numbers2 = {1, 2, 3, 4, 5};
    auto it = numbers2.begin();
    std::cout << *it << std::endl; // dereference: points to 1
    it++; // increment: now it points to 2
    std::cout << *it << std::endl;
    // random access: access the 2th element after the current one
    std::cout << it[2] << std::endl;
    --it; // decrement: now it points to 1 again
    std::cout << *it << std::endl;
    it += 4; // advance the iterator by 4 positions: now it points to 5
    std::cout << *it << std::endl;
    it++; // advance past the last element;
    std::cout << "'it' is after the last element: " <<
        std::boolalpha << (it == numbers2.end()) << std::endl;


    // Reverse Iterators
    std::vector<int> numbers3 = {1, 2, 3, 4, 5};
    for(auto rit = numbers3.rbegin(); rit != numbers3.rend(); ++rit) {
        std::cout << "The number is: " << *rit << std::endl;
    }
    return 0;
}