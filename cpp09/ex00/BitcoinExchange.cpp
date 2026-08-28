#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{

    if (this != &other)
    {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::LoadData(std::string dbfilename)
{
    std::string path = "/home/mel-houa/cpp09/ex00/data.csv";
    std::ifstream file(path.c_str());
    
    std::string DateStr;
    std::string RateStr;
    std::string line;

    /// Check if the file is open
    if (!file.is_open())
    {
        std::cerr << "Error: opening input file." << std::endl;
    }

    // Skip the first line (header)
    if (!std::getline(file, line))
    {
        std::cerr << "Error: reading input file." << std::endl;
    }


    while (std::getline(file, line))
    {
        // Check if the line contains a comma
        if (line.find(",") == std::string::npos)
        {
            std::cerr << "Error: parsing data file." << std::endl;
        }
        // Split the line into date and rate
        size_t comaPos;
        DateStr = line.substr(0, line.find(","));
        RateStr = line.substr(line.find(",") + 1, line.length());

        // Convert the rate string to a double and store it in the map
        double rate = std::stod(RateStr);
        _data[DateStr] = rate;

    }
    // Close the file
    file.close();
}
