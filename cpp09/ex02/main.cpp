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
    pmergeMe.execute();

    return 0;
}
