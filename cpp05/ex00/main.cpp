#include "Bureaucrat.hpp"



int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << std::endl;
        bob.incrementGrade();
        std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << std::endl;
        bob.incrementGrade(); // This should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 149);
        std::cout << alice.getName() << ", bureaucrat grade " << alice.getGrade() << std::endl;
        alice.decrementGrade();
        std::cout << alice.getName() << ", bureaucrat grade " << alice.getGrade() << std::endl;
        alice.decrementGrade(); // This should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}