#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * @brief Load data from file into a vector of Data structures. 
 * 
 * @param data: reference to vector 
 */
void Load_Data(std::vector<Data> &data, const std::string &in_file)
{
    Data temp;
    // Open file. 
    csvstream csvin(in_file);  
    // Rows have key = column name, value = cell datum
    map<string, string> row;

    // Extract coloum
    while (csvin >> row)
    {
        temp.id = std::stoi(row["id"]);
        temp.gender = row["gender"];
        temp.school = row["school"];
        temp.state = row["state"];
        // cout << "id: " << temp.id << "\tgender: " << temp.gender << "\n";
        // TODO: Load structure in vector of Data structures
        data.push_back(temp);
    }
}

int Count_Gender(std::vector<Data> &data, const std::string gender)
{
    int count = 0;
    // Check for valid gender string in data set
    if (gender != "Male" && gender != "Female")
    {
        return count;
    }
    for (const auto &value : data)
    {
        // std::cout << value.gender << "\n";
        if (value.gender == gender)
        {
            count += 1;
        }
    }
    return count;
}

/**
 * @brief Create a map with the states as key and the number
 * of occurrences as the value. 
 * 
 * @param data: vector of Data Structures 
 * @param st_count: map of state counts 
 */
void Count_by_State(std::vector<Data> &data, std::map<std::string, int> &st_count)
{
    for (const auto &value : data)
    {
        auto search = st_count.find(value.state);
        if (search != st_count.end())
        {
            // std::cout << "Found " << search->first << " " << search->second << '\n';
            st_count[value.state] += 1;  // found state, increment by one
        }
        else
        {
            // std::cout << "Not found "<< value.state << endl;
            st_count.insert(pair<std::string, int>(value.state, 1)); // new entry
        }
    }
}

/**
 * @brief Display the content of a map
 * 
 * @param st_count: Reference to map with key-> states, value-> count 
 */
void Display_by_State(std::map<std::string, int> &st_count)
{
    int total = 0;

    // Iterate over the map using c++11 range based for loop
	for (std::pair<std::string, int> element : st_count) 
    {
		// std::cout << element.first << " :: " << element.second << std::endl;
		// Or more explicitly

        // Accessing KEY from element
		std::string word = element.first;
		// Accessing VALUE from element.
		int count = element.second;
		std::cout << word << " :: " << count << std::endl;
        
        total += count;
	}
    cout << "A total of "<< total << " records for all states" << endl;
}