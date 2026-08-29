#include "PmergeMe.hpp"

#include <algorithm>
#include <sstream>

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

bool PmergeMe::parsePositiveInt(const std::string &token, int &value) const
{
    (void)token;
    (void)value;

    

    return false;
}

bool PmergeMe::parseArguments(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return false;
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
