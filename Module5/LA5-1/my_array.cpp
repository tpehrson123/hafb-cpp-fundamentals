#include <iostream>
using namespace std;
#include <array>
#include <algorithm>

// Local Prototypes
void fun(int const& value); 

struct Distance                  //English distance
{
   int feet;
   float inches;
};

// Constants

int main()
{
    array<int, 3> ar = {4, 5, 6};

    cout << "First element: " << ar.front() << endl;
    cout << "Last element: " << ar.back() << endl;
    cout << "Array size: " << ar.size() << endl;

    // Loop over 
    cout<<"Using index notation" << endl;
    for(size_t i = 0; i < ar.size(); ++i)
    {
        cout << ar[i] << endl;
    }
    //Using a for loop with iterator
    cout<<"Using built-in function for begin and end members of containters" << endl;
    for(auto it = std::begin(ar); it != std::end(ar); ++it) 
    {
        std::cout << *it << "\n";  // dereference
    }
    // Range based
    cout<< "Range based for" << endl;
    for(const auto& value: ar) 
    {
        std::cout << value << "\n";
    }

    // Using for_each algorithm, using a function or functor, need <algorithm> library
    cout<< "Using for_each algorithm, using a function or functor" << endl;
    std::for_each(std::begin(ar), std::end(ar), fun);

    // Using for_each algorithm. Using a lambda, MORE LATER
    cout << "Using for_each algorithm. Using a lambda:" << endl; 
    std::for_each(std::begin(ar), std::end(ar), [](int const& value) 
    {
        std::cout << value << "\n";
    });
    
    array<Distance, 3> distances = {
                    6, 2.5, 
                    8, 1.9, 
                    7, 5.7};

    cout<< "Range based for structures" << endl;
    for(const auto& distance: distances) 
    {
        std::cout << distance.feet << " " << distance.inches << endl;
    }

    return 0;
}

// Local function definitions
void fun(int const& value) 
{
    std::cout << value << "\n";
}