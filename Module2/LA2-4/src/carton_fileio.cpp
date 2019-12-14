#include "carton_fileio.h"

#include <array>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief - reads from file and stores in the parameter array
 * 
 * @param filename - name of file to be read, including path and extension
 * @param cartons - array to store the data in
 * @param size - current location in the array to write to
 * @return std::string - empty or error message
 */
std::string ReadDataFromFile(std::string filename,
                             std::array<Carton, kMaxSize>& cartons, int& size) {
  ifstream in(filename);

  if (in.fail()) {
    return "Unable to open file.";
  }

  string message = "";
  double side1, side2, side3;

  while (size < kMaxSize && in >> side1) {
    in >> side2 >> side3;

    try {
      cartons[size] = Carton(side1, side2, side3);
      size++;
    } catch (out_of_range e) {
      message += e.what();
      message += "\n";
    }
  }

  in.close();
  return message;
}

/**
 * @brief - writes data to file
 * 
 * @param filename - name of file to write to
 * @param cartons - array with data
 * @param size - size of valid elements in the array
 */
void WriteDataToFile(std::string filename,
                     const std::array<Carton, kMaxSize>& cartons, int size) {
  ofstream out(filename);

  for (int i = 0; i < size; i++) {
    cartons[i].WriteData(out);
  }

  out.close();
}