#include <iostream>
using namespace std;
#include <array>
#include <algorithm> // For iterators

// Local Prototypes
void fun(int const &value);

int main()
{

    array<int, 3> info = {4, 7, 9};
    cout << "First element: " << info.front() << endl;
    cout << "Last element: " << info.back() << endl;
    cout << "Size: " << info.size() << endl;

    for (size_t i = 0; i < info.size(); i++)
    {
        cout << info[i] << endl;
    }

    cout << "Loop using iterator notation.  Using built-in functions for "
         << "begin and end members of containers " << endl;
    for (auto it = begin(info); it != end(info); ++it)
    {
        cout << *it << endl; // it is a pointer - so de-reference it to get value
    }

    // Range based loop
    cout << "Range based for loop" << endl;
    for (const auto &value : info)
    {
        cout << value << endl;
    }

    // For each loop
    // functor: function that acts like an object
    cout << "Foreach algorithm, using a function or functor" << endl;
    for_each(begin(info), end(info), fun);

    // Lambdas:  [](){}
    // [] to take any local variables in the scope
    // () declare the paramters of your functions
    // {} declare the body of your function
    cout << "Foreach algorithm, using a lambdas" << endl;
    for_each(begin(info), end(info), [](int const & value){std::cout << value << "\n";});

    return 0;
}

// Local function definitions
void fun(int const &value)
{
    std::cout << value << "\n";
}