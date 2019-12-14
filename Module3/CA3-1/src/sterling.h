#ifndef STERLING_H_
#define STERLING_H_

#include <iostream>

// Global variable for poundsign
const unsigned char kPoundSign = static_cast<unsigned char>(156); // £

class Sterling
{
private:
    long pounds_;               // pounds
    int shills_;                // shillings: 20 per pound
    int pence_;                 // pence: 12 per shilling
    std::string old_system_;    // £13.18.1 
public:
    Sterling();                                     // no-arg constructor
    Sterling(long pounds, int shills, int pence);   // 3-arg constructor
    Sterling(double dec_pounds);                    // 1-arg constructor dec pounds to sterling
    Sterling(const std::string &old_system);      // 1-arg constructor old_system to sterling

    long pounds() const; 
    void set_pound(long pnd);

    int shills() const; 
    void set_shills(int sh);
    
    int pence() const; 
    void set_pence(int pence);
    
    const std::string &old_system() const;                // gets "£7.10.6"
    void set_old_system(const std::string &sterling);     // user types "£7.10.6"      
        
    bool operator==(const Sterling &rhs) const;
    bool operator!=(const Sterling &rhs) const;

    friend Sterling operator + (Sterling const &s1, Sterling const &s2); // sterling + sterling
    friend Sterling operator - (Sterling const &s1, Sterling const &s2); // sterling + sterling
    // Sterling operator + (Sterling s2) const; // sterling + sterling
    // Sterling operator - (Sterling s2) const; // sterling - sterling
    
    float decimal_pound();
    friend std::ostream &operator<<(std::ostream &os, const Sterling &sterling);
    bool Split_(std::string stringToBeSplitted, std::string delimiter);
    void Convert_(long&, int&, int&);
};

#endif /* !STERLING_H_ */
