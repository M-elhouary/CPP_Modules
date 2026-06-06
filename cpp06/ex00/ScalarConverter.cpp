#include "ScalarConverter.hpp"

// nan      (Not A Number)
// +inf     (positive infinity)
// -inf     (negative infinity)

// nanf

// +inff
// -inff

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

std::string ScalarConverter::isPseudoLiteral(std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return "D";
    else if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return "F";
    else
        return "";
}

void ScalarConverter::HandlePseudoLiteral(std::string &literal, std::string &type)
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

void ScalarConverter::printAfterCast(double literal)
{
    char c = static_cast<char>(literal);
    std::cout << "char: " << c << std::endl;

    int i = static_cast<int>(literal);
    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(literal);
    std::cout << "float: " << std::fixed
              << std::setprecision(1)
              << f 
              << "f"
              << std::endl;

    std::cout << "double: "<< std::fixed
              << std::setprecision(1)
              << literal << std::endl;
}

std::string ScalarConverter::detectType(std::string &literal)
{
    std::string pseudo = isPseudoLiteral(literal);
    if (pseudo != "")
        return pseudo;
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        return "char";
    }
    else if (literal.find('.') != std::string::npos)
    {
        if (!literal.empty() && literal[literal.size() - 1] == 'f')
            return "float";
        else
            return "double";
    }
    else if (isdigit(literal[0]) || (literal[0] == '-' && literal.length() > 1) || (literal[0] == '+' && literal.length() > 1))
    {
        return "int";
    }
    else
    {
        return "unknown";
    }
}

void ScalarConverter::convert(std::string &literal)
{
    ScalarConverter sc; // allowed inside class methods
    std::string type = sc.detectType(literal);
    char *end;
    double d = std::strtod(literal.c_str(), &end);

    if (type == "D" || type == "F")
    {
        sc.HandlePseudoLiteral(literal, type);
        return;
    }
    else if (type == "unknown" || (*(end+1) != '\0'))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    // check if conversion succeeded using end pointer

    if (d)
    {
        sc.printAfterCast(d);
    }
}

std::ostream &operator<<(std::ostream &out, ScalarConverter const &rhs)
{
    (void)rhs;
    return out;
}