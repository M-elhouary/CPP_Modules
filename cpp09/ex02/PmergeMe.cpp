#include "PmergeMe.hpp"

#include <algorithm>
#include <sstream>
#include <cctype>
#include <climits>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vectorData(other._vectorData), _dequeData(other._dequeData)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::isOperand(char token) const
{
    return std::isdigit(static_cast<unsigned char>(token));
}
bool PmergeMe::parsePositiveInt(const std::string &token, int &value) const
{
    if (token.empty())
    {
        std::cerr << "Error: empty token." << std::endl;
        return false;
    }
    // initialize value to 0 before parsing for each token to prevent accumulation from previous tokens
    value = 0;
    for (size_t i = 0; i < token.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
        {
            std::cerr << "Error: invalid token '" << token << "'." << std::endl;
            return false;
        }

        int digit = token[i] - '0';
        if ((value == INT_MAX / 10 && digit > 7) || value > INT_MAX / 10)
        {
            std::cerr << "Error: integer overflow for token '" << token << "'." << std::endl;
            return false;
        }
        value = value * 10 + digit;

        if (value == 0)
        {
            std::cerr << "Error: zero is not a positive integer for token '" << token << "'." << std::endl;
            return false;
        }
    }
    return true;
}

bool PmergeMe::parseArguments(int argc, char **argv)
{
    int num;
    for (int i = 1; i < argc; i++)
    {
        if (!parsePositiveInt(argv[i], num))
            return false;
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    return true;
}

bool PmergeMe::buildPairs(std::vector<Pairs> &pairs, std::vector<int> const &data, bool &hasStraggler, int &straggler) const
{
    if (data.size() < 2)
        return true;

    hasStraggler = (data.size() % 2 == 1);
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        Pairs pair;
        int a = data[i];
        int b = data[i + 1];
        if(a < b)
         std::swap(a, b);
        pairs.push_back({a,b});
    }
    if (hasStraggler)
        straggler = data.back();
    return true;
}

void PmergeMe::execute()
{
}

void PmergeMe::printBefore() const
{
}

void PmergeMe::printAfter() const
{
}

void PmergeMe::printTimings(unsigned long count) const
{
    (void)count;
}

bool PmergeMe::verifyResults() const
{
    return false;
}

double PmergeMe::nowMicroseconds() const
{
    return 0.0;
}
