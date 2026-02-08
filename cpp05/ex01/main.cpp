#include  "Bureaucrat.hpp"
#include  "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 50);
        Form f1("FormA", 30, 20);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;   
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl; 

    }
    return 0;
}
