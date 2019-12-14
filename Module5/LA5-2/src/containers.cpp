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
void Load_Data(std::vector<Data> &data, const std::string &input_file)
{
    Data temp;
    // Open file. 
    csvstream csvin(input_file);
    // Rows have key = column name, value = cell datum
    map<string, string> row;

    // Extract colum
    while (csvin >> row)
    {
        temp.id = std::stoi(row["id"]);
        temp.name = row["name"];
        temp.animal = row["animal"];
        cout << "id: " << temp.id << "\tanimal: " << temp.animal << endl;
        // TODO: Load structure in vector of Data structures
        data.push_back(temp);
    }
}