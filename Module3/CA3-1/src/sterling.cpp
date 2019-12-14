#include <iostream>
#include <array>
#include <string>
#include <math.h>
#include "sterling.h"
using namespace std;

/**
 * @brief Construct a new Sterling:: Sterling object
 * Sets class members to 0.
 */
Sterling::Sterling()
{
    pounds_ = 0;
    shills_ = 0;
    pence_ = 0;
    std::string old_system_ = "none";   
}

/**
 * @brief Construct a new Sterling:: Sterling object
 * 
 * @param pnd pound
 * @param sh shellings
 * @param pen pence
 */
Sterling::Sterling(long pnd, int sh, int pen)
{
    // Check for conversion
    Convert_(pnd, sh, pen);
    set_pound(pnd);
    set_shills(sh);
    set_pence(pen);
    old_system_  = to_string(pen) + "." + to_string(sh) + "." + to_string(pen);
}

/**
 * @brief Construct a new Sterling:: Sterling object
 * 
 * @param decpounds: Pounds in decimal input
 * ex: 2.15 
 */
Sterling::Sterling(double dec_pounds)
{
    long pounds;
    int shills, pence;
	
	pounds =  static_cast<long>(dec_pounds);
	shills =  static_cast<long>((dec_pounds - pounds) * 20);

	pence = ceil((dec_pounds*240 - pounds*240 - (shills*12)));
	
	// cout << "Pounds: " << pounds << " shills: " << shills << " Pence: " << pence <<endl;
	set_pound(pounds);
	set_shills(shills);
	set_pence(pence);
}

/**
 * @brief Construct a new Sterling:: with old system string: £12.2.5
 * 
 * @param old_system 
 */
Sterling::Sterling(const std::string& old_system)
{
    if(!Split_(old_system, "."))
    {  
        cout << "Error Spliting record" << endl;
    }
    // unsigned char poundsign = static_cast<unsigned char>(156);
    old_system_ = old_system;

}


/**
 * @brief Get pound value
 * 
 * @return pound 
 */
long Sterling::pounds() const
{
    return pounds_;
} 

/**
 * @brief Set the pound value
 * 
 * @param pounds 
 */
void Sterling::set_pound(long pnd) 
{
    pounds_ = pnd;
}

/**
 * @brief Get the Shillings value
 * 
 * @return shillins 
 */
int Sterling::shills() const
{
    return shills_;
} 

/**
 * @brief Sets shilling value. Will calculate if it needs to 
 * adjust the pound value
 * 
 * @param shilling 
 */
void Sterling::set_shills(int shills)
{
    if (shills >= 20)
    {
        shills -= 20;
        pounds_++;
        set_shills(shills);
    }
    else
    {
        shills_ = shills;
    }
}

/**
 * @brief Gets the pence value
 * 
 * @return pence 
 */
int Sterling::pence() const
{
    return pence_;
} 

/**
 * @brief Sets pence value. It will adjust the shilling and pound values if 
 * necessary. 
 * 
 * @param pence 
 */
void Sterling::set_pence(int pence)
{
    int shills = 0;
    if (pence > 12)
    {
        pence -= 12;
        shills_++;
        set_pence(pence);
        set_shills(shills_);
    }
    else
    {
        pence_ = pence;
    }
}

/**
 * @brief Gets the string version of the sterling old notation
 * example: "32.11.10"
 * 
 * @return const std::string& 
 */
const std::string &Sterling::old_system() const
{
    return old_system_;
} 

/**
 * @brief Sets the old_notation and splits the string into the 
 * three components: pound, shillings, and pence
 * 
 * @param sterling 
 */
void Sterling::set_old_system(const std::string &sterling)
{
    if(!Split_(sterling, "."))
    {  
        cout << "Error Spliting record" << endl;
    }
    // unsigned char poundsign = static_cast<unsigned char>(156);
    old_system_ = sterling;
}

/**
 * @brief Output stream operator for the Sterling object
 * 
 * @param os 
 * @param sterling object
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Sterling &sterling)
{
    os << "pounds_: " << sterling.pounds_ << " shills_: " << sterling.shills_ << " pence_: " << sterling.pence_;
    return os;
}

/**
 * @brief Equality operator == for Sterling objects
 * 
 * @param Sterling object to compare to 
 * @return true if equal
 * @return false if not equal
 */
bool Sterling::operator==(const Sterling &rhs) const
{
    return pounds_ == rhs.pounds_ &&
           shills_ == rhs.shills_ &&
           pence_ == rhs.pence_ &&
           old_system_ == rhs.old_system_;
}

/**
 * @brief Inequality operator == for Sterling objects
 * 
 * @param Sterling object to compare to 
 * @return true if equal
 * @return false if not equal
 */
bool Sterling::operator!=(const Sterling &rhs) const
{
    return !(rhs == *this);
}

// convert Sterling to double
/**
 * @brief Convert the Sterling to decimal pound format
 * 
 * @return double 
 */
float Sterling::decimal_pound()
{
    return static_cast<double>(pounds_) +
           static_cast<double>(shills_) / 20.0 +
           static_cast<double>(pence_) / 240.0;
}

/**
 * @brief Overload + operator for two Sterling objects
 * 
 * @param s2 Object type Sterling
 * @return Sterling new object after addition
 */
Sterling operator + (Sterling const &s1, Sterling const &s2) // ster + ster
{
    int pounds = s1.pounds() + s2.pounds();
    int shills = s1.shills() + s2.shills();
    int pence = s1.pence() + s2.pence();

    return Sterling(pounds, shills, pence);
}

/**
 * @brief Overload - operator for two Sterling objects
 * 
 * @param s2 Object type Sterling
 * @return Sterling new object after substraction
 */
Sterling operator - (Sterling const &s1, Sterling const &s2) // ster + ster
{
    int pounds = s1.pounds() - s2.pounds();
    int shills = s1.shills() - s2.shills();
    int pence = s1.pence() - s2.pence();

    return Sterling(pounds, shills, pence);
}

/**
 * @brief Internal method to split a string by a delimiter
 * 
 * @param stringToBeSplitted 
 * @param delimeter 
 * @return true 
 * @return false 
 */
bool Sterling::Split_(std::string stringToBeSplitted, std::string delimiter)
{
    // Check for minimum length
    if (stringToBeSplitted.length() < 5)
    {
        return false;
    }

    int startIndex = 0;
    int endIndex = 0;
    std::array<int, 3> money = {0,0,0};
    int index = 0;
    while ((endIndex = stringToBeSplitted.find(delimiter, startIndex)) < stringToBeSplitted.size())
    {

        std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
        money[index] = std::stoi(val);
        index++;
        startIndex = endIndex + delimiter.size();
    }
    if (startIndex < stringToBeSplitted.size())
    {
        std::string val = stringToBeSplitted.substr(startIndex);
        money[index] = std::stoi(val);
    }
  
    // Save original string
    old_system_ = stringToBeSplitted;
    pounds_ = money[0];
    shills_ = money[1];
    pence_ = money[2];
    return true;
}

void Sterling::Convert_(long& pnd, int& sh, int& pen)
{
    // 20 shilling = 1 pound
    // 12 pence = 1 shilling

    // Convert pence to shilling
    if(pen >= 12)
    {
        sh += pen/12;
        pen = pen %12;
    }
    // convert shilling to pounds
    if(sh >= 20)
    {
        pnd += sh/20;
        sh = sh % 20; 
    }
}