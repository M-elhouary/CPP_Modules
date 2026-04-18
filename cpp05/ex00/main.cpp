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
        // b2.incrementGrade(); // This should throw an exception.
        std::cout << b2 << std::endl;
        Bureaucrat b3("Charlie", 151); // This should throw an exception.
        b2.decrementGrade();
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
};
