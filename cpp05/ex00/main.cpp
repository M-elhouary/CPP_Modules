#include "Bureaucrat.hpp"


int main()  
{
    try
    {
        Bureaucrat b1("Alice", 150);
        std::cout << b1 << std::endl; 
        b1.incrementGrade(); 
        std::cout << b1 << std::endl; 
        b1.decrementGrade();
        std::cout << b1 << std::endl; 

        Bureaucrat b2("Bob", 1);
        std::cout << b2 << std::endl;
        std::cout << b2 << std::endl;
        Bureaucrat b3("Charlie", 151); 
        b2.decrementGrade();
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& s)
    {
        std::cerr << "Exception caught: " << s.what() << std::endl;
    }
    return 0;

};
    