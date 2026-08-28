#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void printData() const;
    void LoadData(std::string dbfilename);
    void parseData(const std::string& filename);
    double getBitcoinValue(const std::string& date) const;
};

#endif // BITCOINEXCHANGE_HPP   