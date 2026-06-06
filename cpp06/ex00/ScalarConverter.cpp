#include "ScalarConverter.hpp"


//    std::string detectType(std::string  &literal);
//     std::string isPseudoLiteral(std::string  &literal);
//     void HandlePseudoLiteral(std::string  &literal, std::string &type);
//     void printChar(double d);
//     void printInt(double d);
//     void printFloat(double d);
//     void printDouble(double d); 
//     void printImpossible();



ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    (void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}

std::string isPseudoLiteral(std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return "D";
    else if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return "F";
    else
        return "";
}

void HandlePseudoLiteral(std::string &literal, std::string &type)
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
    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;
}

void printFloat(double d)
{
    float f = static_cast<float>(d);
    std::cout << "float: " << std::fixed
              << std::setprecision(1)
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

std::string detectType(std::string &literal)
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

void ScalarConverter::convert(std::string &literal)
{
    // ScalarConverter sc; // allowed inside class methods
    double d;
    char *end = NULL;
    std::string type = detectType(literal);
    if (type == "char")
    {
        d = static_cast<double>(literal[0]);
        std::cout << "char: " << "'" << literal[0] << "'" << std::endl;
        std::cout << d << std::endl;

    }
    else
        d = std::strtod(literal.c_str(), &end);


    if (type == "D" || type == "F")
    {
        HandlePseudoLiteral(literal, type);
        return;
    }
    else if (type == "unknown" || ((*end == 'f') && (*(end + 1) != '\0')) 
                                    || ((*end != 'f') && (*end != '\0'))) // check if there are extra characters after the number (except for 'f' in float)
    { 
        printImpossible();
        return;
    }
    // check if conversion succeeded using end pointer
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