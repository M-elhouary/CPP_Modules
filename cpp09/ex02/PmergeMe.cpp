#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTimeUs(0.0), _dequeTimeUs(0.0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vectorData(other._vectorData),
      _dequeData(other._dequeData),
      _vectorTimeUs(other._vectorTimeUs),
      _dequeTimeUs(other._dequeTimeUs)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
        _vectorTimeUs = other._vectorTimeUs;
        _dequeTimeUs = other._dequeTimeUs;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

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

std::vector<int> PmergeMe::getVecData()
{
    return _vectorData;
}

std::deque<int> PmergeMe::getDequeData()
{
    return _dequeData;
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size(); i++)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vectorData.size(); i++)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;
}

double PmergeMe::nowMicroseconds() const
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
}

void PmergeMe::printTimings(unsigned long count) const
{
    std::cout << "Time to process a range of " << count << " elements with std::vector : "
              << _vectorTimeUs << " us" << std::endl;
    std::cout << "Time to process a range of " << count << " elements with std::deque : "
              << _dequeTimeUs << " us" << std::endl;
}

void PmergeMe::startSort()
{
    double start = nowMicroseconds();
    _vectorData = sortingVector(_vectorData);
    _vectorTimeUs = nowMicroseconds() - start;

    start = nowMicroseconds();
    _dequeData = sortingDeque(_dequeData);
    _dequeTimeUs = nowMicroseconds() - start;
}