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
  
    std::vector<int> sortWinners( std::vector<int>  &data, std::vector<Pairs> &pairs);
    bool parseArguments(int argc, char **argv);
    bool startSorting();
    bool isOperand(char token) const;
    bool buildPairs(std::vector<Pairs> &pairs, std::vector<int> const &data, bool &hasStraggler, int &straggler) const;
    std::vector<size_t> Jacobsthal(size_t loserSize);
    void insertLosers(std::vector<int> &mainChain, std::vector<int> const &losers, bool hasStraggler, int straggler);
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



#endif
