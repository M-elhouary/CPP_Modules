#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>


class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static bool isFloatPseudo(const std::string& literal);
		static bool isDoublePseudo(const std::string& literal);
		static bool isCharLiteral(const std::string& literal);

		static void printPseudoFloat(const std::string& literal);
		static void printPseudoDouble(const std::string& literal);

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

	public:
		static void convert(const std::string& literal);
};

#endif