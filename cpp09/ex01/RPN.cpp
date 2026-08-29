#include "RPN.hpp"


RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->stack = other.stack;
    }
    return *this;
}



bool RPN::isOperator(char token) const {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

bool RPN::isOperand(char token) const {
    return std::isdigit(static_cast<unsigned char>(token));
}

void RPN::parseInput(const std::string &input)
{
    int nb;
    for(size_t i = 0 ; i < input.length(); i++ )
    {
        if(std::isspace(input[i]))
            continue;
        if( !isOperator(input[i]) && !isOperand(input[i]) )
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
        
        if(!std::isdigit(static_cast<unsigned char>(input[0])) &&
                !std::isdigit(static_cast<unsigned char>(input[1])))
        {
            std::cerr << "Error:the tow first char not a numbers " << std::endl;
        }
    }
    


}