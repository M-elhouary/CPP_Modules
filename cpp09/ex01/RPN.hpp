#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <list>
#include <cctype>
#include <cstdlib>
#include <string>


class RPN
{
    private:
        std::stack<int, std::list<int> > stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        void parseInput(const std::string &input);
        void performOperation(char operation);
        int apply(int left, int right, char operation) const;
        void clearStack();
        bool isOperator(char token) const;
        bool isOperand(char token) const;
};


#endif // RPN_HPP
