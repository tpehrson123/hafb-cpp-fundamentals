#ifndef ROMAN_LIB_H_
#define ROMAN_LIB_H_

#include <iostream>

namespace numbers
{
class Roman
{
    private:
        unsigned int arabic_;
        std::string roman_;
    public:
    // Constructors
    Roman() : arabic_(0), roman_("nulla") {}
    Roman(unsigned int number) { arabic_ = number;}
    // Accessor
    unsigned int arabic() const {return arabic_;}
    std::string roman() const {return roman_;}
    void set_arabic(unsigned number);
    void set_roman(std::string number);
    // Other methods
    std::string to_roman(unsigned int number);
    unsigned int to_arabic(const std::string &roman_str);
};
} // end of numbers namespace

#endif /* !ROMAN_LIB_H_ */
