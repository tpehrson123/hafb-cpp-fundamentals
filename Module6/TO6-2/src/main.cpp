#include <iostream>
#include <string>
#include "process_payroll.h"

using namespace std;

int main() {

  try
  {
    ProcessPayroll("../payroll_week23.txt", "../report_week23.txt");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  

  return 0;
}