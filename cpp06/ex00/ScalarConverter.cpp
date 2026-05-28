#include "ScalarConverter.hpp"


// defaulte construtctor
ScalarConverter::ScalarConverter() {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

// copy assignment opertor

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}


bool ScalarConverter::isFloatPseudo(const std::string& literal)
{
	return (
		literal == "nanf"
		|| literal == "+inff"
		|| literal == "-inff"
	);
}

bool ScalarConverter::isDoublePseudo(const std::string& literal)
{
	return (
		literal == "nan"
		|| literal == "+inf"
		|| literal == "-inf"
	);
}

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>

// =====================================================
// Orthodox Canonical Form
// =====================================================

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

// =====================================================
// Detection Functions
// =====================================================

bool ScalarConverter::isFloatPseudo(const std::string& literal)
{
	return (
		literal == "nanf"
		|| literal == "+inff"
		|| literal == "-inff"
	);
}

bool ScalarConverter::isDoublePseudo(const std::string& literal)
{
	return (
		literal == "nan"
		|| literal == "+inf"
		|| literal == "-inf"
	);
}

bool ScalarConverter::isCharLiteral(const std::string& literal)
{
	return (
		literal.length() == 1
		&& !std::isdigit(literal[0])
	);
}

// =====================================================
// Pseudo Literal Printing
// =====================================================

void ScalarConverter::printPseudoFloat(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	std::cout << "float: "
		<< literal
		<< std::endl;

	std::cout << "double: "
		<< literal.substr(0, literal.length() - 1)
		<< std::endl;
}

void ScalarConverter::printPseudoDouble(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	std::cout << "float: "
		<< literal
		<< "f" << std::endl;

	std::cout << "double: "
		<< literal
		<< std::endl;
}

// =====================================================
// Scalar Printing
// =====================================================

void ScalarConverter::printChar(double value)
{
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < 0
		|| value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(value);

	if (!std::isprint(c))
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}

	std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	if (std::isnan(value)
		|| std::isinf(value)
		|| value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}

	std::cout << "int: "
		<< static_cast<int>(value)
		<< std::endl;
}

void ScalarConverter::printFloat(double value)
{
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: "
		<< static_cast<float>(value)
		<< "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "double: "
		<< value
		<< std::endl;
}

// Main Convert Function

void ScalarConverter::convert(const std::string& literal)
{
	// Pseudo literals

	if (isFloatPseudo(literal))
	{
		printPseudoFloat(literal);
		return;
	}

	if (isDoublePseudo(literal))
	{
		printPseudoDouble(literal);
		return;
	}

	// Char literal

	if (isCharLiteral(literal))
	{
		char c = literal[0];

		printChar(static_cast<double>(c));
		printInt(static_cast<double>(c));
		printFloat(static_cast<double>(c));
		printDouble(static_cast<double>(c));

		return;
	}

	// Numeric parsing

	char* end;

	double value = std::strtod(literal.c_str(), &end);

	// Nothing parsed

	if (end == literal.c_str())
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}

	// Invalid extra characters

	if (*end != '\0')
	{
		if (!(*end == 'f' && *(end + 1) == '\0'))
		{
			std::cout << "Invalid input" << std::endl;
			return;
		}
	}

	// Printing conversions

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}


// destructor 
ScalarConverter::~ScalarConverter() {}