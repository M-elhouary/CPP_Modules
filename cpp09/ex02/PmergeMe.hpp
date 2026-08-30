#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <string>
#include <vector>

struct Pairs
{
    int winner;
    int loser;
};


class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseArguments(int argc, char **argv);
    void execute();
    bool isOperand(char token) const;
    bool buildPairs(std::vector<Pairs> &pairs, std::vector<int> const &data, bool &hasStraggler, int &straggler) const;
  private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;

    bool parsePositiveInt(const std::string &token, int &value) const;

    void printBefore() const;
    void printAfter() const;
    void printTimings(unsigned long count) const;
    bool verifyResults() const;

    double nowMicroseconds() const;
};

#endif // PMERGEME_HPP
