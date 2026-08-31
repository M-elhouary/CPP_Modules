#include "PmergeMe.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: no arguments provided." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;
    if (!pmergeMe.parseArguments(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    // std::vector<int> sortedVec = pmergeMe.sortingVector(pmergeMe.getVecData());
    // std::deque<int> sortedDeq = pmergeMe.sortingDeque(pmergeMe.getDequeData());

    pmergeMe.printBefore();
    
    pmergeMe.startSort();
    pmergeMe.printAfter();

    
    // std::cout << "Vector: ";
    // for (size_t i = 0; i < sortedVec.size(); ++i)
    //     std::cout << sortedVec[i] << " ";
    // std::cout << std::endl;
    
    // std::cout << "Deque:  ";
    // for (size_t i = 0; i < sortedDeq.size(); ++i)
    //     std::cout << sortedDeq[i] << " ";
    // std::cout << std::endl;

    return 0;
}
