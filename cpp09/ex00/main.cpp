#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: usage: ./btc <input file>" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;

    // Load the database
    if (!bitcoinExchange.LoadData("data.csv"))
        return 1;
    if (!bitcoinExchange.parseInputLine(av[1]))
        return 1;

    return 0;
}
