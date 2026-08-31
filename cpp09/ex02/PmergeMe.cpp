#include "PmergeMe.hpp"

#include <algorithm>
#include <sstream>
#include <cctype>
#include <climits>

// ================================== canonical form of the class ==================================
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// =================================== parsing part ===================================


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
    }

    if (value == 0)
    {
        std::cerr << "Error: zero is not a positive integer for token '" << token << "'." << std::endl;
        return false;
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

bool PmergeMe::buildPairs(std::vector<Pairs> &pairs, std::vector<int> const &data, bool &hasStraggler, int &straggler) const
{
    if (data.size() < 2)
        return true;

    hasStraggler = (data.size() % 2 == 1);
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        int a = data[i];
        int b = data[i + 1];
        if (a < b)
            std::swap(a, b);
        Pairs pair;
        pair.winner = a;
        pair.loser = b;
        pairs.push_back(pair);
    }
    if (hasStraggler)
        straggler = data.back();
    return true;
}
// ================================== sorting part ==================================

std::vector<int> PmergeMe::sortWinners(std::vector<int> &winners, std::vector<Pairs> &pairs)
{
    (void)pairs;
    std::vector<int> data = winners;



    if (data.size() <= 1)
        return data;



    std::vector<Pairs> localPairs;

    bool hasStraggler = false;
    int straggler = 0;

    buildPairs(localPairs, data, hasStraggler, straggler);

    std::vector<int> mainChain;
    std::vector<int> pend;
    
    for (size_t i = 0; i < localPairs.size(); ++i)
    {
        mainChain.push_back(localPairs[i].winner);
        pend.push_back(localPairs[i].loser);
    }

    std::vector<int> result = sortWinners(mainChain, pairs);

    insertLosers(result, pend, hasStraggler, straggler);

    return result;
}

std::vector<size_t> PmergeMe::Jacobsthal(size_t n)
{
    std::vector<size_t> sequence;

    if (n <= 1)
        return sequence;

    size_t previousJacob = 1;
    size_t currentJacob = 3;
    size_t previousBoundary = 1;

    while (currentJacob <= n)
    {
        sequence.push_back(currentJacob);

        for (size_t i = currentJacob - 1; i > previousBoundary; --i)
            sequence.push_back(i);

        previousBoundary = currentJacob;

        size_t nextJacob = currentJacob + (2 * previousJacob);

        previousJacob = currentJacob;
        currentJacob = nextJacob;
    }

    for (size_t i = n; i > previousBoundary; --i)
        sequence.push_back(i);

    return sequence;
}

void PmergeMe::insertLosers(std::vector<int> &mainChain, std::vector<int> const &losers, bool hasStraggler, int straggler)
{
    if (!losers.empty())
    {
        int first = losers[0];
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), first), first);
    }

    std::vector<size_t> jacobsthalSequence = Jacobsthal(losers.size());
    for (size_t k = 0; k < jacobsthalSequence.size(); ++k)
    {
        size_t j = jacobsthalSequence[k];
        if (j < 2 || j > losers.size())
            continue;
        int value = losers[j - 1];
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), value), value);
    }

    if (hasStraggler)
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);
}

bool PmergeMe::startSorting()
{
    if (_vectorData.size() <= 1)
        return true;

    bool hasStraggler = false;
    int straggler = 0;

    std::vector<Pairs> pairs;

    std::vector<Pairs> PairsForWinners;

    if (!buildPairs(pairs, _vectorData, hasStraggler, straggler))
        return false;

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].winner);

    PairsForWinners = pairs;

    std::vector<int> mainChain = sortWinners(winners, PairsForWinners);

    std::vector<int> sortedLosers;
    for (size_t i = 0; i < pairs.size(); ++i)
        sortedLosers.push_back(pairs[i].loser);

    _vectorData = mainChain;

    insertLosers(_vectorData, sortedLosers, hasStraggler, straggler);

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
