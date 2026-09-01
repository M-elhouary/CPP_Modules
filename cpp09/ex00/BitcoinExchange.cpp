#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &text) const
{
    std::string::size_type start = 0;
    std::string::size_type end = text.length();

    // Trim leading and trailing whitespace
    while (start < end && std::isspace(static_cast<unsigned char>(text[start])))
        ++start;
    // Trim trailing whitespace
    while (end > start && std::isspace(static_cast<unsigned char>(text[end - 1])))
        --end;

    // Return the trimmed string
    return text.substr(start, end - start);
}

int BitcoinExchange::parseToInt(const std::string &text) const
{
    std::istringstream iss(text);
    int value = 0;
    iss >> value;
    return value;
}

bool BitcoinExchange::parseToDouble(const std::string &text, double &result) const
{
    if (text.empty())
        return false;

    std::string t = trim(text);
    if (t.empty())
        return false;

    std::istringstream iss(t);
    double value = 0.0;
    iss >> value;
    if (iss.fail())
        return false;

    while (iss.good() && std::isspace(static_cast<unsigned char>(iss.peek())))
        iss.get();
    char extra;
    if (iss.get(extra))
        return false;

    result = value;
    return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return year % 4 == 0;
}

int BitcoinExchange::daysInMonth(int year, int month) const
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

bool BitcoinExchange::isValideDate(const std::string &date) const
{
    // check if the date is in the format YYYY-MM-DD
    if (date.length() != 10)
        return false;

    // check if the date is in the format YYYY-MM-DD
    if (date[4] != '-' || date[7] != '-')
        return false;

    // check if the numbers are valid
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    // parse the year, month, and day to integers
    int year = parseToInt(date.substr(0, 4));
    int month = parseToInt(date.substr(5, 2));
    int day = parseToInt(date.substr(8, 2));

    if (year < 1 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (day > daysInMonth(year, month))
        return false;

    return true;
}


bool checkHeader(bool &firstLine, const std::string &DateStr, const std::string &ValueStr)
{
    if (firstLine)
    {
        firstLine = false;
        if (DateStr == "date" && ValueStr == "exchange_rate")
            return true;
    }
    return false;
}


bool detectSeparator(const std::string &line, char &separator)
{
    size_t commaCount = std::count(line.begin(), line.end(), ',');
    size_t pipeCount = std::count(line.begin(), line.end(), '|');

    if (commaCount == 1 && pipeCount == 0)
    {
        separator = ',';
        return true;
    }
    else if (pipeCount == 1 && commaCount == 0)
    {
        separator = '|';
        return true;
    }
    else
        return false;
}

bool BitcoinExchange::LoadData(const std::string &dbfilename)
{
    std::ifstream file(dbfilename.c_str());

    // check if the file is open
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;

    // for the first line, check if it is the header
    bool firstLine = true;

    while (std::getline(file, line))
    {

        // remove carriage return character if present (for Windows compatibility)
        if (!line.empty() && line[line.length() - 1] == '\r')
            line.erase(line.length() - 1);



        // check if the line is empty
        if (trim(line).empty())
        {
            std::cerr << "Error: empty line in database file." << std::endl;
            return false;
        }

        // check if there is a separator in the line
        char separator ;
        if (!detectSeparator(line, separator))
        {
            std::cerr << "Error: parsing database file ! check the format." << std::endl;
            return false;
        }
        
        // extract the date and rate
        std::string DateStr = trim(line.substr(0, line.find(separator)));
        std::string RateStr = trim(line.substr(line.find(separator) + 1));

        // check if the first line is the header
        if(!checkHeader(firstLine, DateStr, RateStr))
        {
            std::cerr << "Error: bad header in database file." << std::endl;
            return false;
        }

        double rate;
        if (!isValideDate(DateStr))
        {
            std::cerr << "Error: invalid date in database." << std::endl;
            return false;
        }
        if (!parseToDouble(RateStr, rate) || rate < 0)
        {
            std::cerr << "Error: invalid rate in database." << std::endl;
            return false;
        }
        if (_data.find(DateStr) != _data.end())
        {
            std::cerr << "Error: duplicate date in database." << std::endl;
            return false;
        }

        _data[DateStr] = rate;
    }

    if (_data.empty())
    {
        std::cerr << "Error: database is empty." << std::endl;
        return false;
    }

    return true;
}


bool BitcoinExchange::parseInputLine(const std::string &inputfilename)
{
    // check if the file is open
    std::ifstream file(inputfilename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return false;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (!line.empty() && line[line.length() - 1] == '\r')
            line.erase(line.length() - 1);

        if (trim(line).empty())
        {
            std::cerr << "Error: empty line in input file." << std::endl;
            return false;
        }

        char separator ;
        if (!detectSeparator(line, separator))
        {
            std::cerr << "Error: bad input ! check the format." << std::endl;
            return false;
        }

        // extract the date and value
        std::string DateStr = trim(line.substr(0, line.find(separator)));
        std::string ValueStr = trim(line.substr(line.find(separator) + 1));

        // check if the first line is the header
        if(!checkHeader(firstLine, DateStr, ValueStr))
        {
            std::cerr << "Error: bad header in input file." << std::endl;
            return false;
        }

        if (!isValideDate(DateStr))
        {
            std::cerr << "Error: bad input ! check the format." << std::endl;
            return false;
        }

        double value;
        if (!parseToDouble(ValueStr, value))
        {
            std::cerr << "Error: bad input ! check the format." << std::endl;
            return false;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl; 
            return false;
        }

        double rate = getBitcoinValue(DateStr);
        if (rate < 0)
        {
            std::cerr << "Error: no earlier date in database => " << DateStr << std::endl;
            return false;
        }

        std::cout << DateStr << " => " << ValueStr << " = " << (value * rate) << std::endl;
    }
    return true;
}

double BitcoinExchange::getBitcoinValue(const std::string &date) const
{

    if (_data.empty())
        return -1.0;

    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
    if (it != _data.end() && it->first == date)
        return it->second;
    if (it == _data.begin())
        return -1.0;
    --it;
    return it->second;
}
