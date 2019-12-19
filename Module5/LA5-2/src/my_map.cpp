#include <iostream>
#include <map> //
#include <string>
using namespace std;

int main()
{

    // Maps are a key-> value pair elements
    map<int, string> info;
    info.insert(make_pair(1, "Waldo Weber"));
    info.insert(make_pair(2, "Utah Jazz"));

    cout << "Size of map: " << info.size() << endl;

    auto position = info.find(1); // position is an iterator (kind of like a pointer)
    if (position != info.end())
    {
        cout << "Found the key: " << position->first << " and the value is: " << position->second << endl;
    }

    cout << "Using iterator" << endl;
    for (auto it = begin(info); it != end(info); ++it)
    {
        cout << it->first << " " << it->second << "\t";
    }
    cout << endl;

    cout << "Using range based" << endl;
    for (pair<int, string> element : info)
    {
        cout << element.first << " " << element.second << "\t";
    }

    return 0;
}