#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

// check if the operation is valid and apply it to the top two elements of the stack
bool RPN::isOperator(char token) const
{
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

// check if the token is a valid operand (digit)
bool RPN::isOperand(char token) const
{
    return std::isdigit(static_cast<unsigned char>(token));
}

// apply the operation to the two operands and return the result
int RPN::apply(int left, int right, char operation) const
{
    switch (operation)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right == 0)
        {
            std::cerr << "Error: division by zero." << std::endl;
            return 0;
        }
        return left / right;
    default:
        std::cerr << "Error: unknown operation '" << operation << "'." << std::endl;
        return 0;
    }
}

// apply the operation to the two operands and return the result
void RPN::performOperation(char operation)
{

    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();

    int result = apply(left, right, operation);
    stack.push(result);
}

void RPN::clearStack()
{
    while (!stack.empty())
        stack.pop();
}

// parse the input string and push operands onto the stack, perform operations when operators are encountered
bool RPN::parseInput(const std::string &input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::isspace(input[i]))
            continue;
        if (!isOperator(input[i]) && !isOperand(input[i]))
        {
            std::cerr << "Error: failed to parse input." << std::endl;
            clearStack();
            return false;
        }

        if (i > 2 && isOperand(input[i]) && i + 1 < input.length() && isOperand(input[i + 1]))
        {
            std::cerr << "Error: operand must be less than 10." << std::endl;
            clearStack();
            return false;
        }

        if (isOperator(input[i]))
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: not enough operands for operation '" << input[i] << "'." << std::endl;
                clearStack();
                return false;
            }
            performOperation(input[i]);
        }
        else
            stack.push(input[i] - '0');
    }
    return true;
}

void RPN::caculateRPN(const std::string &input)
{
    // Parse the input and build the stack
    if (!parseInput(input))
    {
        clearStack();
        return;
    }
    // Check if the stack has exactly one element after processing the input
    if (stack.size() != 1)
    {
        std::cerr << "Error: invalid RPN expression." << std::endl;
        clearStack();
        return;
    }
    int result = stack.top();
    stack.pop();
    std::cout << result << std::endl;
}
