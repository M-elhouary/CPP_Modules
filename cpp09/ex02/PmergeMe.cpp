#include "PmergeMe.hpp"

#include <algorithm>
#include <sstream>
#include <cctype>
#include <climits>




// ================================== canonical form of the class ==================================
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) : _vectorData(other._vectorData), _dequeData(other._dequeData){}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}


// =================================== parsing part ===================================

/// chekc if the token is a digit
bool PmergeMe::isOperand(char token) const
{
    return std::isdigit(static_cast<unsigned char>(token));
}

// Parse a string token into a positive integer,
// returning true if successful, false otherwise

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

// Parse command line arguments into _vectorData and _dequeData,
// returning true if successful, false otherwise
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

// Build pairs from the data,
//  returning true if successful, false otherwise










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
        if (a < b)
            std::swap(a, b);
        pairs.push_back({a, b});
    }
    if (hasStraggler)
        straggler = data.back();
    return true;
}

// ================================== sorting part ==================================

std::vector<int> PmergeMe::sortWinners( std::vector<int> &winners, std::vector<Pairs> &pairs)
{
    bool hasStraggler = true;
    int straggler = 0;

    std::vector<int> newWinners(winners.size());

    if (newWinners.size() <= 1)
        return newWinners;
        
    for (size_t i = 0; i < newWinners.size(); ++i)
         newWinners.push_back(winners[i]);
    PmergeMe::buildPairs(pairs, newWinners, hasStraggler, straggler);
    return sortWinners(newWinners, pairs);
}


size_t Jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    size_t j0 = 0;
    size_t j1 = 1;
    size_t j2 = 0;
    for (size_t i = 2; i <= n; ++i)
    {
        j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    return j2;
}


bool PmergeMe::startSorting()
{
    bool hasStraggler = false;
    int straggler = 0;
    std::vector<Pairs> pairs;
    std::vector<Pairs> PairsForWinners;

    if(!buildPairs(pairs, _vectorData, hasStraggler, straggler))
        return false;

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
         winners.push_back(pairs[i].winner);
    PairsForWinners = pairs;
    winners = sortWinners( winners, PairsForWinners);
    // sort the losers based on the sorted winners
    std::vector<int> sortedLosers;
    for (size_t i = 0; i < PairsForWinners.size(); ++i)
    {
        std::vector<int>::iterator it = std::find(winners.begin(), winners.end(), PairsForWinners[i].winner);
        if (it == winners.end())
        return false;
        size_t index = it - winners.begin();
        sortedLosers.push_back(PairsForWinners[index].loser);
    }
    _vectorData.clear();
    _vectorData.insert(_vectorData.end(), winners.begin(), winners.begin()+ 1);
    _vectorData.insert(_vectorData.end(), winners.begin(), winners.end());



    // Jacobsthal sequence insertion for the losers
    Jacobsthal(sortedLosers.size()-1);


    return true;
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
