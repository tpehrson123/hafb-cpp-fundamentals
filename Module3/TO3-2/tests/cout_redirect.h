#ifndef COUT_REDIRECT_H_
#define COUT_REDIRECT_H_

#include <iostream>
#include <streambuf>
#include <stdio.h>
#include <iostream>
#include <streambuf>
#include <stdlib.h>
#include <string>
#include <sstream>

class CoutRedirect
{
private:
    std::stringstream buffer;
    std::streambuf *old;

public:
    CoutRedirect();
    ~CoutRedirect();
    std::string getString();

};


#endif /* !COUT_REDIRECT_H_ */
