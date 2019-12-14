#include <iostream>
using namespace std;
#include "roman_lib.h"
#include <vector>
#include <string>
    
// local protoype
int value(char r); 
    
void numbers::Roman::set_arabic(unsigned number)
{
    arabic_ = number;
    // TODO: Should update roman_ by calling to_roman
    roman_ = to_roman(number);

}
    
void numbers::Roman::set_roman(std::string number)
{
    roman_ = number;
    // TODO: Should update arabic by calling to_arabic

}
    
std::string numbers::Roman::to_roman(unsigned int number)
{
    std::vector<std::pair<unsigned int, char const*>> roman {
      { 1000, "M" },{ 900, "CM" }, { 500, "D" },{ 400, "CD" }, 
      { 100, "C" },{ 90, "XC" }, { 50, "L" },{ 40, "XL" },
      { 10, "X" },{ 9, "IX" }, { 5, "V" },{ 4, "IV" }, { 1, "I" }};

   std::string result;
   for (auto const & kvp : roman) {
      while (number >= kvp.first) {
         result += kvp.second;
         number -= kvp.first;
      }
   }
   return result;

}
    
    
unsigned int numbers::Roman::to_arabic(const std::string &roman_str)
{
    // Initialize result 
    int res = 0; 
  
    // Traverse given input 
    for (int i=0; i<roman_str.length(); i++) 
    { 
        // Getting value of symbol s[i] 
        int s1 = value(roman_str[i]); 
  
        if (i+1 < roman_str.length()) 
        { 
            // Getting value of symbol s[i+1] 
            int s2 = value(roman_str[i+1]); 
  
            // Comparing both values 
            if (s1 >= s2) 
            { 
                // Value of current symbol is greater 
                // or equal to the next symbol 
                res = res + s1; 
            } 
            else
            { 
                res = res + s2 - s1; 
                i++; // Value of current symbol is 
                     // less than the next symbol 
            } 
        } 
        else
        { 
            res = res + s1; 
        } 
}

int value(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
} 