#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    (void)src; //
}

ScalarConverter::~ScalarConverter() {}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this; //
}



std::string isPseudoLiteral(const std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return "D";
    else if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return "F";
    else
        return "";
}



void HandlePseudoLiteral(const std::string &literal, std::string &type)
{

    if (type == "D")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
    else if (type == "F")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    }
}




void printChar(double d)
{
    if (d > static_cast<double>(CHAR_MAX) || d < static_cast<double>(CHAR_MIN))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (!std::isprint(c))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: " << "'" << c << "'" << std::endl;
}



void printInt(double d)
{
    if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;
}



void printFloat(double d)
{
    if(d > static_cast<double>(FLT_MAX) || d < static_cast<double>(-FLT_MAX))
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(d);
    std::cout << "float: " << std::fixed
              << std::setprecision(5)
              << f
              << "f"
              << std::endl;
}



void printDouble(double d)
{
    std::cout << "double: " << std::fixed
              << std::setprecision(1)
              << d << std::endl;
}



bool isliteral(const std::string &literal)
{
    size_t dotCount = literal.find('.');
    for (size_t i = 0; i < literal.length(); ++i)
    {
        if (std::isalpha(literal[i]) && (((dotCount != std::string::npos) && !isdigit(literal[dotCount + 1]))
        || dotCount == std::string::npos) && literal[i+1] != '\0')
            return false;
    }
            return true;
        }

std::string detectType(const std::string &literal)
{
    std::string pseudo = isPseudoLiteral(literal);
    if (pseudo != "")
        return pseudo;
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
        return "char";
    else if ((literal.find('.')) != std::string::npos)
    {
        if (!literal.empty() && literal[literal.length() - 1] == 'f' && literal.length() > 1)
            return "float";
        else
            return "double";
    }
    else if (isdigit(literal[0]) || (literal[0] == '-' && literal.length() > 1) || (literal[0] == '+' && literal.length() > 1))
        return "int";
    else
        return "unknown";
}


void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}


void ScalarConverter::convert(const std::string &literal)
{
    double d;
    char *end;
    if (!isliteral(literal))
    {
        printImpossible();
        return;
    }
    std::string type = detectType(literal);
    if (type == "D" || type == "F")
    {
        HandlePseudoLiteral(literal, type);
        return;
    }
    else if (type == "char")
        d = static_cast<double>(literal[0]);
    else
    {
        d = std::strtod(literal.c_str(), &end);
        if (type == "unknown" 
            || ((*end != 'f') && *end != '\0') 
            || ((*end == 'f') && (*(end + 1) != '\0') ))
        {
            printImpossible();
            return;
        }
    }   
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}



std::ostream &operator<<(std::ostream &out, ScalarConverter const &rhs)
{
    (void)rhs;
    return out;
}