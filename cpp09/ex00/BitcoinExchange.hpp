#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, double> _data;
    std::string trim(const std::string &text) const;
    int parseToInt(const std::string &text) const;
    bool parseToDouble(const std::string &text, double &result) const;
    bool isLeapYear(int year) const;
    int daysInMonth(int year, int month) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool LoadData(const std::string &dbfilename);
    bool parseInputLine(const std::string &inputfilename);
    bool isValideDate(const std::string &date) const;
    double getBitcoinValue(const std::string &date) const;
};

#endif // BITCOINEXCHANGE_HPP
