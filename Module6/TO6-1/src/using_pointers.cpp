
#include "using_pointers.h"

#include <fstream>
#include <string>
#include <vector>
#include "carton.h"

void WriteStats(std::string input_file, std::string output_file) {
  // define and open output file
  std::ofstream out(output_file);

  // define and open input file
  std::ifstream in(input_file);
  if (in.fail()) {
    out << "Unable to open file. Shutting down...";
    return;
  }

  // read how many
  int how_many;
  in >> how_many;

  // dynamically allocate an array that big
  int* int_array = new int[how_many];

  // fill the array from the input file
  for (int i = 0; i < how_many; i++) {
    in >> int_array[i];
  }

  // close the input file
  in.close();

  // compute total and average
  int total = 0;
  double average = 0;
  for (int i = 0; i < how_many; i++) {
    total += int_array[i];
  }
  average = static_cast<double>(total) / how_many;

  // output count, total, and average to output file
  out << how_many << std::endl << total << std::endl << average << std::endl;

  // delete the dynamically allocated array
  delete[] int_array;

  // close the output file
  out.close();

  return;
}

void WriteCartons(std::string input_file, std::string output_file) {
  // define and open output file
  std::ofstream out(output_file);

  // define and open input file
  std::ifstream in(input_file);
  if (in.fail()) {
    out << "Unable to open file. Shutting down...";
    return;
  }

  // declare a vector or Carton pointers
  std::vector<Carton*> cartons;

  // loop through file, read Carton data, create new Carton objects, and
  // store pointers in vector
  double side1, side2, side3;
  while (in >> side1) {
    in >> side2 >> side3;
    cartons.push_back(new Carton(side1, side2, side3));
  }

  // close the input file
  in.close();

  // loop through vector and write cartons to output file
  for (Carton* one_ptr : cartons) {
    one_ptr->WriteCarton(out);
  }

  // loop through vector, delete memory for each pointer, and set pointer
  // equal to NULL
  for (Carton*& one_ptr : cartons) {
    delete one_ptr;
    one_ptr = NULL;
  }

  // close the output file
  out.close();

  return;
}
