#include <fstream> // file stream
#include "carton_fileio.h"

std::string ReadDataFormatFromFile(std::string filename,                       // by value
                                   std::array<Carton, kMaxArraySize> &cartons, // by reference
                                   int &rec_num)
{

    // create an ojbect of type ifstream
    std::ifstream data_input_file(filename); // input file stream

    if (data_input_file.fail())
    {
        std::cout << "Unable to open file";
        return "Unable to open file";
    }

    std::string message = "";
    double side1, side2, side3; // Read data from file

    while (rec_num < kMaxArraySize && data_input_file >> side1)
    {
        data_input_file >> side2 >> side3;

        // Load data into array
        try
        {
            cartons[rec_num] = Carton(side1, side2, side3);
            rec_num++;
        }
        catch (std::out_of_range e)
        {
            message += e.what();
            message += "\n";
            return message;
        }
    }

    data_input_file.close(); // close the input file

    return message;
}

void WriteDataToFile(std::string filename,
                     const std::array<Carton, kMaxArraySize> &cartons, // by reference
                     int rec_num)
{
    std::ofstream file_out(filename);
    // TODO check writing privileges

    for (int index = 0; index < rec_num; ++index)
    {
        cartons[index].WriteData(file_out);
    }
}
