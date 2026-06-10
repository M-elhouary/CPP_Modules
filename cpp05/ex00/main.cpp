#include "Bureaucrat.hpp"

int main()  
{
    try
    {
        Bureaucrat b("ahmed", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;


    }
    catch (const std::exception& s)
    {
        std::cerr << "Exception caught: " << s.what() << std::endl;
    }
    return 0;

};
    