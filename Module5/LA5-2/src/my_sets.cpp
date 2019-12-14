#include <iostream>
#include <set>

int main()
{
    std::set<int> numbers;
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);  // do I get a duplicate?

    // Find value
    if(numbers.find(10) != numbers.end())
    {
        std::cout << "10 is in numbers" << std::endl;
    }
    std::cout << "The set has " << numbers.size() << " elements" << std::endl;
     // Loop over 
    // std::cout<<"Using index notation" << std::endl; // does not work
    //Using a for loop with iterator
    std::cout<<"Using built-in function for begin and end members of containters" << std::endl;
    for(auto it = std::begin(numbers); it != std::end(numbers); ++it) 
    {
        std::cout << *it << "\n";  // dereference
    }
    // Range based
    std::cout<< "Range based for" << std::endl;
    for(const auto& value: numbers) 
    {
        std::cout << value << "\n";
    }


}