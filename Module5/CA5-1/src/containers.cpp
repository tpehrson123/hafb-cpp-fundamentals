#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>

/**
 * @brief Load data from file into a vector of Data structures. 
 * 
 * @param data: reference to vector 
 */
void Load_Data(std::vector<Car> &cars, const std::string &in_file)
{
    Car temp;
    // Open file. 
    csvstream csvin(in_file);  
    // Rows have key = column name, value = cell datum
    std::map<std::string, std::string> row;

    // Extract colum
    while (csvin >> row)
    {
        temp.vin = row["vin"];
        temp.make = row["car_make"];
        temp.year = std::stoi(row["car_year"]);
        temp.color = row["car_color"];
        temp.value = std::stod(row["value"]);
        temp.state = row["state"];
        // std::cout << "id: " << temp.make << "\tvalue: " << temp.value << std::endl;
        // TODO: Load structure in vector of Data structures
        cars.push_back(temp);
    }
}

/**
 * @brief Car sales analytics
 * 
 * @param cars: Reference to vector or Car Objects 
 * @param operation: analytics operation:
 *      1) MAX value from car
 *      2) MIN value from car
 */
Car Car_Value_Analytics(std::vector<Car> &cars, int operation)
{
    auto car = std::minmax_element(cars.begin(), cars.end(), 
        [](const Car &lhs, const Car &rhs ){ return lhs.value < rhs.value;});

    if(operation == MAX)
    {
        // std::cout<< "Max value: " << car.second->value << std::endl;
        return *car.second;
    }
    else
    {
        // std::cout<< "Min value: " << car.first->value << std::endl;
        return *car.first;
    }
}

/**
 * @brief Select car records based on a decade. 
 * 
 * @param cars: Reference vector of Car objects 
 * @param decade: decade to filter by
 * @return std::vector<Car>: A sorted vector filter by the decade
 */
std::vector<Car> Cars_from_decade(std::vector<Car> &cars, int decade)
{
    // Get a copy of the vector to for those value
    // that pass the predicate
    std::vector<Car> new_cars;
    int mod = decade % 10;
    if(mod != 0) 
    {
        decade -= mod; // decade number: 1980, 2000, etc
    }
    
    std::copy_if(cars.begin(), cars.end(), std::back_inserter(new_cars),
        [decade](const Car& car) { 
            return car.year>= decade && car.year <= decade + 9;});
    if(new_cars.size() == 0)
    {
        std::cout<<"No cars available from this decade " << decade << std::endl;
        return new_cars;
    }

    // Sort them by value
    std::sort(new_cars.begin(), new_cars.end(),
        [](const Car& lhs, const Car& rhs) { 
            return lhs.value < rhs.value; });

    return new_cars;
}
