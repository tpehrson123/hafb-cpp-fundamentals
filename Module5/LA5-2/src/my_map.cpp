#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> map1;
    map1.insert(std::make_pair(1, "Waldo Weber"));
    map1.insert(std::make_pair(2, "Utah Jazz"));

    std::cout << "Size of map is " << map1.size() << std::endl;

    auto position = map1.find(1);
    if(position != map1.end())
    {
        std::cout << "Found! The key is " << position->first << ", and the value is "<<
            position->second << std::endl;
    }

    //Using a for loop with iterator
    std::cout<<"Using built-in function for begin and end members of containters" << std::endl;
    for(auto it = std::begin(map1); it != std::end(map1); ++it) 
    {
        std::cout << it->first << " " << it->second << std::endl;  // dereference
    }
    // Range based
    std::cout<< "Range based for" << std::endl;
    for(std::pair<int, std::string> element : map1) 
    {
        std::cout << element.first << " " << element.second << std::endl;  // dereference
    }


    return 0;
}