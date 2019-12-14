#ifndef FILEIO_H
#define FILEIO_H

#include <array>
#include <fstream>
#include "project.h"

const int kMaxSize = 20;

std::string ReadProjectsFromFile(const std::string filename,
                                 std::array<Project, kMaxSize>& projects,
                                 int& size);
void WriteProjectsToFile(const std::string filename,
                         const std::array<Project, kMaxSize>& projects,
                         const int size);

#endif