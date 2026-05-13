#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 40);
        Form f1("Form1", 50, 30);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << "After signing:" << std::endl;
        std::cout << f1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
