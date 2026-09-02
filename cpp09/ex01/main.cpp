#include "RPN.hpp"




int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    RPN rpn;
    if (!rpn.caculateRPN(av[1]))
        return 1;
    return 0;
}