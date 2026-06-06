
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>


class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter  &src);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter  &rhs);

public:
    static void convert(std::string &literal);
 
};


std::ostream &operator<<(std::ostream &out, ScalarConverter const &rhs);

#endif
