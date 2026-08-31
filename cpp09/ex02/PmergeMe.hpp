#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <climits>

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
  std::vector<int> getVecData();
  std::deque<int> getDequeData();

  bool parseArguments(int argc, char **argv);
  std::vector<int> sortingVector(std::vector<int> data);
  std::deque<int> sortingDeque(std::deque<int> data);
  bool buildPairsVec(std::vector<Pairs> &pairs, std::vector<int> const &data, bool &hasStraggler, int &straggler) const;
  bool buildPairsDeq(std::vector<Pairs> &pairs, std::deque<int> const &data, bool &hasStraggler, int &straggler) const;
  std::vector<size_t> Jacobsthal(size_t loserSize);
  void insertLosersVec(std::vector<int> &mainChain, std::vector<int> const &losers, bool hasStraggler, int straggler);
  void insertLosersDeq(std::deque<int> &mainChain, std::deque<int> const &losers, bool hasStraggler, int straggler);
  void startSort();
  bool parsePositiveInt(const std::string &token, int &value) const;

  void printBefore() const;
  void printAfter() const;
  void printTimings(unsigned long count) const;
  double nowMicroseconds() const;

private:
  std::vector<int> _vectorData;
  std::deque<int> _dequeData;
};

#endif
