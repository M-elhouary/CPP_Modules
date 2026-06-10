
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
#include <cfloat>
#include <climits>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &rhs);
 
public:
    static void convert(const std::string &literal);
};

std::ostream &operator<<(std::ostream &out, ScalarConverter const &rhs);

#endif
