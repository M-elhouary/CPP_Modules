#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{

    // std::cout << argv[1][0] << std::endl;
    // std::cout << argv[1] << std::endl;
    if(argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    std::string literal = argv[1]; 
    ScalarConverter::convert(literal);
    
    return 0;
}