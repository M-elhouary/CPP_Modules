#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

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


bool BitcoinExchange::parseDataline(std::string DateStr, std::string RateStr)
{
    // Convert the rate string to a double and store it in the map
    double rate;
    rate = std::stod(RateStr);
    _data[DateStr] = rate;
    return true;
};

void BitcoinExchange::LoadData(std::string dbfilename)
{
    std::ifstream file(dbfilename.c_str());
    std::string line;
    std::string DateStr;
    std::string RateStr;
    size_t comaPos;
    double rate;


    /// Check if the file is open
    if (!file.is_open())
        std::cerr << "Error: opening input file." << std::endl;

    while (std::getline(file, line))
    {
        if(line.empty())
        {
            std::cerr << "Error: empty line in data file." << std::endl;
            return;
        }
        // Check if the line contains a comma
        if ((comaPos = line.find(",")) == std::string::npos)
        {
            std::cerr << "Error: parsing data file." << std::endl;
            line.clear();
            return;
        }
        DateStr = line.substr(0, comaPos);
        RateStr = line.substr(comaPos + 1, line.length());
        
        // header check
        if (DateStr != "date" && RateStr != "exchange_rate")
        {
            std::cerr << "Error: invalid header." << std::endl;
            line.clear();
            return;
        }
        else if (DateStr == "date" && RateStr == "exchange_rate")
            continue;

        if(!parseDataline(DateStr, RateStr))
            return;
        // Clear the line string for the next iteration
        line.clear();
    }
    // Close the file
    file.close();
}
