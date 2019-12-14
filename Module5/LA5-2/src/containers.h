#ifndef CONTAINERS_H_
#define CONTAINERS_H_

#include <string>
#include <vector>
#include <map>
#include <string>

// Structure for data from file
struct Data
{
    int id;
    std::string name;
    std::string animal;
};

void Load_Data(std::vector<Data> &data, const std::string &input_file);

#endif /* !CONTAINERS_H_ */
