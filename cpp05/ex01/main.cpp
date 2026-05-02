#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        // Test signForm()
        Bureaucrat b1("Alice", 40);
        Form f1("Form1", 50, 30);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << "After signing:" << std::endl;
        std::cout << f1 << std::endl;

        // Uncomment to test exceptions and other cases
        // Form f2("Form2", 0, 30); // This should throw an exception.
        // Form f3("Form3", 50, 151); // This should throw an exception.
        // Bureaucrat b2("Bob", 1);
        // b2.incrementGrade(); // This should throw an exception.
        // Bureaucrat b3("Charlie", 151); // This should throw an exception.
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
