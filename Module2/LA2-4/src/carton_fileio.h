#ifndef CARTON_FILEIO_H
#define CARTON_FILEIO_H

#include <array>
#include <string>
#include "carton.h"

const int kMaxSize = 20;

std::string ReadDataFromFile(std::string filename,
                             std::array<Carton, kMaxSize>& cartons, int& size);
void WriteDataToFile(std::string filename,
                     const std::array<Carton, kMaxSize>& cartons, int size);

#endif