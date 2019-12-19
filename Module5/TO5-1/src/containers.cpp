#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>

void Load_Data(std::vector<Data> &data, const std::string &input_file)
{
	csvstream csvinput(input_file); // open file
	// Rows have a key = column name, value = cell data
	std::map<std::string, std::string> row;
	Data temp;
	// Extract the animal column
	while (csvinput >> row)
	{
		// The key is the column name
		//   std::cout << row["id"] << "," << row["name"] << "," << row["animal"] << std::endl;
		temp.id = std::stoi(row["id"]); // cast string to integer
		temp.gender = row["gender"];
		temp.school = row["school"];
		temp.state = row["state"];
		data.push_back(temp); // load Data struct into vector
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
	std::cout << "A total of " << total << " records for all states" << std::endl;
}