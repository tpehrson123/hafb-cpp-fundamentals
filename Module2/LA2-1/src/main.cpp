#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Shows how to define and use a string object
 *
 * We will define string variables and then see what operators and
 * functions work with these variables.
 *
 * @return int 0 means function exited with success
 */
int main() {
  // create a variable of type string
  string name = "William Hansen";

  // print it out
  cout << "Name: " << name << endl;

  // get a string from a user
  // cout << "Enter a name: ";
  // getline(cin, name);
  // cout << "Name: " << name << endl;

  // add two strings together
  string title = "Dr. ";
  string formal;
  formal = title + name;
  cout << "Name: " << formal << endl;

  // how long is the string
  cout << "The length of name is " << name.size() << endl;
  cout << "The length of formal is " << formal.length() << endl;
  cout << "The length of title is " << title.length() << endl;

  // use [] to get an individual character
  cout << "The third character is " << name[2] << endl;
  cout << "The third character is " << name[2] << endl;

  // get name and commute information from a user
  // int minutes;
  // int miles;
  // cout << "Enter a name: ";
  // getline(cin, name);
  // cout << "How long is your commute in minutes? ";
  // cin >> minutes;
  // cout << "How many miles is your commute? ";
  // cin >> miles;
  // cout << name << " has a " << minutes << " minute, " << miles
  //      << " mile commute\n";

  // get commute information and name from a user
  // cout << "\n\nHow long is your commute in minutes? ";
  // cin >> minutes;
  // cout << "How many miles is your commute? ";
  // cin >> miles;
  // cout << "Enter a name: ";
  // cin.ignore();
  // getline(cin, name);
  // cout << name << " has a " << minutes << " minute, " << miles
  //      << " mile commute\n";

  // the string function find
  string story =
      "The dragons are flying over the mountains. They are hunting for a "
      "place to settle for the waldo night. What they see is endless horizon.";

  cout << "Waldo is at location " << story.find("waldo") << endl;

  // the string function replace
  cout << story << endl;
  story.replace(story.find("waldo"), 6, "");
  cout << story << endl;

  return 0;
}

/*
      "The dragons are flying over the mountains. They are hunting for a "
      "place to settle for the waldo night. What they see is endless horizon."
*/
