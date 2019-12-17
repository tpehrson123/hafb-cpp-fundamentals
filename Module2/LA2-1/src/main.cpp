#include <iostream>
#include <string> //for string objects

/**
 * @brief Shows how to define and use a string object
 *
 * We will define string variables and then see what operators and
 * functions work with these variables.
 *
 * @return int 0 means function exited with success
 */
int main()
{
  // create a variable of type string
  std::string name = "Weber Waldo";

  // print it out
  std::cout << name << std::endl;

  // // get a string from a user
  // std::cout << "Enter a name: " << std::endl;
  // // to get strings with spaces, use getline()
  // getline(std::cin, name);
  // std::cout << "You entered: " << name << std::endl;

  // add two strings together
  std::string title = "Dr.";
  std::string formal;
  formal = title + " " + name;
  std::cout << "Hi " << formal << std::endl;

  // how long is the string (use either size or length - same thing)
  // std::cout << "The size of name is " << name.size() << std::endl;
  // std::cout << "The length of name is " << name.length() << std::endl;

  // std::cout << "The size of name is " << formal.size() << std::endl;
  // std::cout << "The length of name is " << formal.length() << std::endl;

  // // use [] to get an individual character
  // std::cout << "The first char of name is " << name[0] << std::endl;
  // std::cout << "The third char of name is " << name[2] << std::endl;

  // get name and commute information from a user
  int minutes, miles;

  // std::cout << "Enter your full name: " << std::endl;
  // // to get strings with spaces, use getline()
  // getline(std::cin, name);
  // std::cout << "Enter long is your commute in minutes? " << std::endl;
  // std::cin >> minutes;
  // std::cout << "Enter many miles is your commute? " << std::endl;
  // std::cin >> miles;

  // std::cout << "You entered: " << name << " " << minutes << " " << miles << std::endl;

  // get commute information and name from a user

  // the string function find
  std::string story =
      "Now is the time for all good men to to something"
      " and to do this and that and the other thing ... like wheres waldo";

  std::cout << "waldo is at location " << story.find("waldo") << std::endl;

  // the string function replace
  std::cout << "New story: " << story.replace(story.find("waldo"), 5, "idiot") << std::endl;

  return 0;
}

/*
      "The dragons are flying over the mountains. They are hunting for a "
      "place to settle for the waldo night. What they see is endless horizon."
*/
