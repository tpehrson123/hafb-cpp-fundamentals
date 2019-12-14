#include <iostream>
#include <string>
#include <vector>
#include "carton.h"

using namespace std;

int main() {
  // vector<double*> vector1;

  // vector1.push_back(new double(14.28));
  // vector1.push_back(new double(31.7));
  // vector1.push_back(new double(22.3));
  // vector1.push_back(new double(11.89));
  // cout << "value pointed by the first pointer: " << *vector1[0] << endl;
  // cout << "value of the first pointer: " << vector1[0] << endl;
  // cout << "value pointed by the first pointer: " << *vector1[1] << endl;
  // cout << "value of the first pointer: " << vector1[1] << endl;
  // cout << "value pointed by the first pointer: " << *vector1[2] << endl;
  // cout << "value of the first pointer: " << vector1[2] << endl;
  // cout << "value pointed by the first pointer: " << *vector1[3] << endl;
  // cout << "value of the first pointer: " << vector1[3] << endl;

  // for (double*& one_ptr : vector1) {
  //   delete one_ptr;
  //   one_ptr = NULL;
  // }

  // for (double* one_ptr : vector1) {
  //   cout << "value of the pointer: " << one_ptr << endl;
  // }

  vector<Carton*> carton_vector;

  carton_vector.push_back(new Carton);
  carton_vector.push_back(new Carton(12.3, 14, 16.2));

  carton_vector[0]->WriteCarton(cout);
  carton_vector[1]->WriteCarton(cout);

  for (Carton*& one_ptr : carton_vector) {
    delete one_ptr;
    one_ptr = NULL;
  }

  for (Carton* one_ptr : carton_vector) {
    cout << "value of the pointer: " << one_ptr << endl;
  }

  return 0;
}