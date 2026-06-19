#include "ScalarConverter.hpp"

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO_DOUBLE, PSEUDO_FLOAT, UNKNOWN };



ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)src; 
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}

Type isPseudoLiteral(const std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return PSEUDO_DOUBLE;
    else if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return PSEUDO_FLOAT;
    else
        return UNKNOWN;
}

void HandlePseudoLiteral(const std::string &literal, Type type)
{

    if (type == PSEUDO_DOUBLE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
    else if (type == PSEUDO_FLOAT)
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
    if (d > static_cast<double>(FLT_MAX) || d < static_cast<double>(-FLT_MAX))
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
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

bool haveOneDot(const std::string &literal)
{
    int dots = std::count(literal.begin(), literal.end(), '.');
    if (dots == 1)
        return true;
    else
        return false;
}

bool isFlDb(char* end, const std::string &literal)
{
    // Check 1: Invalid character at end (not null terminator or 'f')
    if (*end != '\0' && *end != 'f')
        return false;
    
    // Check 2: If 'f' exists, nothing should come after it
    if (*end == 'f' && *(end + 1) != '\0')
        return false;
    
    // Check 3: No decimal point = must not have 'f'
    if (!haveOneDot(literal) && *end == 'f')
        return false;
    
    return true;
}


Type detectType(const std::string &literal)
{
    Type pseudo = isPseudoLiteral(literal);
    if (pseudo != UNKNOWN)
        return pseudo;
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
        return CHAR;
    else if ((literal.find('.')) != std::string::npos)
    {
        if (!literal.empty() && literal.find('f') != std::string::npos)
            return FLOAT;
        else
            return DOUBLE;
    }
    else if (isdigit(literal[0]) || (literal[0] == '-' && literal.length() > 1) || (literal[0] == '+' && literal.length() > 1))
        return INT;
    else
        return UNKNOWN;
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
    if (literal.empty())
    {
        printImpossible();
        return;
    }

    double d;
    char* end;
    errno = 0;

    Type type = detectType(literal);
    if (type == PSEUDO_DOUBLE || type == PSEUDO_FLOAT)
    {
        HandlePseudoLiteral(literal, type);
        return;
    }
    else if (type == CHAR)
        d = static_cast<double>(literal[0]);
    else
    {
        d = std::strtod(literal.c_str(), &end);
        if (errno == ERANGE)
        {
            printImpossible();
            return;
        }
        if (type == UNKNOWN || !isFlDb(end, literal))
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