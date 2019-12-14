#include "fileio.h"

#include <fstream>
#include <iostream>
#include <string>
#include "project.h"

using namespace std;

string ReadProjectsFromFile(const std::string filename,
                            std::array<Project, kMaxSize>& projects,
                            int& size) {
  ifstream in(filename);
  if (in.fail()) {
    return "Unable to open file.";
  }
  int estimated_time, actual_time, reported_percent_complete;
  double estimated_time_hours, actual_time_hours;
  string name;
  string error_message;
  while (size < kMaxSize && in >> estimated_time) {
    in >> actual_time >> reported_percent_complete;
    in.ignore();
    getline(in, name);
    // convert minutes to hours
    estimated_time_hours = estimated_time / 60.0;
    actual_time_hours = actual_time / 60.0;

    try {
      projects[size++] = Project(name, estimated_time_hours, actual_time_hours,
                                 reported_percent_complete);
    } catch (const out_of_range& e) {
      error_message += "Unable to add project named " + name + e.what();
    }
  }
  in.close();
  return error_message;
}

void WriteProjectsToFile(const std::string filename,
                         const std::array<Project, kMaxSize>& projects,
                         const int size) {
  ofstream out(filename);
  for (int i = 0; i < size; i++) {
    projects[i].WriteData(out);
  }
  out.close();
}
