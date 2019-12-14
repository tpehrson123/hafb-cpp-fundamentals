#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec;

    vec.push_back(100); // both front and back contains the value 100
    vec.push_back(10); // now back vector holds the 10, and front the 100 

    vec.front() -= vec.back(); // we substracted from the value with back

    cout<<"Front of the vector: " << vec.front() << endl;
    cout<<"Back of the vector: " << vec.back() << endl;

    
    // Loop over 
    cout<<"Using index notation" << endl;
    for(size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
    }
    //Using a for loop with iterator
    cout<<"Using built-in function for begin and end members of containters" << endl;
    for(auto it = std::begin(vec); it != std::end(vec); ++it) 
    {
        std::cout << *it << "\n";  // dereference
    }
    // Range based
    cout<< "Range based for" << endl;
    for(const auto& value: vec) 
    {
        std::cout << value << "\n";
    }

    // Create a vector of size n with  all values as -1.
    int n = 5;
    std::vector<int> vec2 = {-1, -1, -1, -1, -1}; 
    // std::vector<int> vec2(n, -1); 
  
    for (int x : vec2) 
    {
        cout << x << " "; 
    }

    return 0;
}