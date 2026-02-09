#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "======= TEST 1: Bureaucrat with high enough grade signs form =======" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 25);
        Form f1("FormA", 30, 20);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << "\nAttempting to sign..." << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}
