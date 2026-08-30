#include "PmergeMe.hpp"

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
    if (!pmergeMe.startSorting())
    {
        std::cerr << "Error: failed to start sorting." << std::endl;
        return 1;
    }

    return 0;
}
