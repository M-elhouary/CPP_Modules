#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#include <ctime>
#include <cstdlib>

int main() {
    ::srand(std::time(0));
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);
        Bureaucrat charlie("Charlie", 50);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        // Try to execute unsigned forms
        std::cout << "\n--- Attempt to execute unsigned forms ---" << std::endl;
        alice.executeForm(shrub);
        alice.executeForm(robot);
        alice.executeForm(pardon);

        // Sign forms with various bureaucrats
        std::cout << "\n--- Signing forms ---" << std::endl;
        try { shrub.beSigned(bob); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { robot.beSigned(charlie); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { pardon.beSigned(alice); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

        // Try to execute with insufficient grade
        std::cout << "\n--- Execution with insufficient grade ---" << std::endl;
        bob.executeForm(shrub); // should succeed
        charlie.executeForm(robot); // should succeed
        bob.executeForm(pardon); // should fail

        // Try to execute with high grade
        std::cout << "\n--- Execution with high grade ---" << std::endl;
        alice.executeForm(shrub);
        alice.executeForm(robot);
        alice.executeForm(pardon);

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}