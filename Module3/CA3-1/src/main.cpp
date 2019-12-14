#include <iostream>
using namespace std;
#include "sterling.h"

// exp08_11.cpp (poundovr)
// sterling class represents pounds, shillings and pence
// overloaded +, -, * and / operators
// uses conversions: double to sterling, sterling to double
// (does not use friends)
////////////////////////////////////////////////////////////////
//--------------------------------------------------------------
////////////////////////////////////////////////////////////////
int main()
{
  cout << "Constructor with no arguments gives you: " << endl;
  Sterling s1;
  cout << "Pounds: " << s1.pounds() << " Shilling: " << s1.shills()
    << " pence: " << s1.pence() << endl;

  cout << "Constructor with three arguments (12, 18, 9) gives you: " << endl;
  Sterling s2(12, 18, 9);
  cout << "Pounds: " << s2.pounds() << " Shilling: " << s2.shills()
    << " pence: " << s2.pence() << endl;
  
  cout << "Constructor with three arguments (12, 48, 29) gives you: " << endl;
  Sterling s3(12, 48, 29);
  cout << "Pounds: " << s3.pounds() << " Shilling: " << s3.shills()
    << " pence: " << s3.pence() << endl;
  
  cout << "Constructor with one arguments (\"12.8.9\") gives you: " << endl;
  Sterling s4(12, 8, 9);
  cout << "Pounds: " << s4.pounds() << " Shilling: " << s4.shills()
    << " pence: " << s4.pence() << endl;
  cout << " or using old_system() method: " << s4.old_system() << endl;

  cout << "Constructor with one arguments (45.67) gives you: " << endl;
  Sterling s5(45.67);
  cout << "Pounds: " << s5.pounds() << " Shilling: " << s5.shills()
    << " pence: " << s5.pence() << endl;

  cout << "Constructor with one arguments (45.67) and using << operator " << endl;
  Sterling s6(45.67);
  cout << s6;

  cout << "\nConstructor with one arguments (42.27) " << endl;
  Sterling s7(42.27);
  cout << s7 << endl;
  s7.set_pound(23);
  cout << "Update pounds to 23 "<< endl;
  cout << s7 << endl;


  cout << "\nConstructor with one arguments (42.27) " << endl;
  Sterling s8(42.27);
  cout << s8 << endl;
  s8.set_shills(67);
  cout << "Update shills to 67, and adjust numbers "<< endl;
  cout << s8 << endl;


  cout << "\nConstructor with one arguments (42.27) " << endl;
  Sterling s9(42.27);
  cout << s9 << endl;
  s9.set_pence(31);
  cout << "Update shills to 31, and adjust numbers "<< endl;
  cout << s9 << endl;
  
  
  cout << "\nCreate two objects:" << endl;
  Sterling s10(33.11);
  Sterling s11(33.11);
  cout << s10 << endl;
  cout << s11 << endl;
  if(s10 != s11)
  {
    cout << "object1 and object2 are not equal"<< endl;
  }
  else
  {
    cout << "object1 and object2 are equal "<< endl;
  }
  
  cout << "\nConstructor with one arguments (12.27) " << endl;
  Sterling s12(12.27);
  cout << s12 << endl;
  cout << "Using decimal_pound() operator "<< s12.decimal_pound() << endl;

  cout << "\nCreate two objects:" << endl;
  Sterling s13(33.15);
  Sterling s14(6.21);
  cout << s13 << endl;
  cout << s14 << endl;
  Sterling s15 = s13 + s14;
  cout << "The difference of obj1 - obj2 = " << s15.decimal_pound() << endl;
  return 0;
}
