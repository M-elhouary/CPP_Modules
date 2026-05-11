#include "Bureaucrat.hpp"


int main()  
{
    try
    {
        // Create a Bureaucrat with the lowest valid grade and test increment/decrement.
        Bureaucrat b1("Alice", 150);
        std::cout << b1 << std::endl; // Should print "Alice, bureaucrat grade 150"
        b1.incrementGrade(); // Should succeed, grade becomes 149
        std::cout << b1 << std::endl; // Should print "Alice, bureaucrat grade 149"
        b1.decrementGrade(); // Should succeed, grade goes back to 150
        std::cout << b1 << std::endl; // Should print "Alice, bureaucrat grade 150"

        Bureaucrat b2("Bob", 1);
        std::cout << b2 << std::endl; // Should print "Bob, bureaucrat grade 1"
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
    return 0;

};
    