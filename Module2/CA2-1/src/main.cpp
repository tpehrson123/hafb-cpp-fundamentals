#include <array>
#include <iostream>
#include <string>
#include "fileio.h"
#include "project.h"

using namespace std;

int main() {
  array<Project, kMaxSize> projects;
  int valid_size = 0;

  // for (Project project : projects) {
  //   project.ProjectReport();
  // }

  cout << ReadProjectsFromFile("../project_data.txt", projects, valid_size)
       << endl;

  cout << "Reports\n";
  for (int i = 0; i < valid_size; i++) {
    projects[i].ProjectReport(cout);
    cout << endl;
  }

  projects[valid_size++] = Project("Update membership files", 45);

  projects[valid_size - 1].RecordTimeSpentHours(5, 10);
  projects[valid_size - 1].RecordTimeSpentMinutes(70, 15);

  cout << "Reports 2\n";
  for (int i = 0; i < valid_size; i++) {
    projects[i].ProjectReport(cout);
    cout << endl;
  }

  WriteProjectsToFile("../out_data.txt", projects, valid_size);

  int new_size = 0;
  cout << ReadProjectsFromFile("../project_data_too_many.txt", projects,
                               new_size);
  cout << "Reports after too many\n";
  for (int i = 0; i < new_size; i++) {
    projects[i].ProjectReport(cout);
    cout << endl;
  }
  return 0;
}