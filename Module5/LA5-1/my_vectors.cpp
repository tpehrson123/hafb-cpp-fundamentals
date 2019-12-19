#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> vec;
    // Add element
    vec.push_back(100); // both, front() and back() contain 100 value
    vec.push_back(200); // front = 100 and back = 200

    cout << vec.front() << endl;
    cout << vec.back() << endl;

    vec.push_back(300);

    // Iterated over the vector
    cout << "Using index notaton" << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    cout << "Using iterator" << endl;
    for (auto it = begin(vec); it != end(vec); ++it)
    {
        cout << *it << endl;
    }

    cout << "Using range based" << endl;
    for (const auto &value : vec)
    {
        cout << value << endl;
    }

    vector<int> vec2 = {111, 222, 333, 444, 555};
    cout << "New vector" << endl;
    for (const auto &value : vec2)
    {
        cout << value << " ";
    }
    cout << endl;

    int max = 50;
    vector<int> vec3(max, -1);
    cout << "New vector" << endl;
    for (const auto &value : vec3)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}