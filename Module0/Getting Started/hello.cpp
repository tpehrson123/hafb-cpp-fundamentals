/* CS 1410 Module 0 Getting Started
 * This program prints out the message
 * Hello!
 * Welcome to CS 1410!
 */
#include<iostream>
#include<string>

using namespace std;

string getMessage();

int main(){

	cout<<getMessage();

	return 0;
}

string getMessage() {
  return "Hello!\nWelcome to CS 1410!";
}
