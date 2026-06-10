#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    std::srand(std::time(0));
    try {

        Bureaucrat alice("Alice", 1); 
        ShrubberyCreationForm shrub("garden");
        // alice.executeForm(shrub);

        // Bureaucrat bob("Bob", 140);
        // Bureaucrat charlie("Charlie", 50);

        // ShrubberyCreationForm shrub("garden");
        // RobotomyRequestForm robot("Bender");
        // PresidentialPardonForm pardon("Ford Prefect");

        // std::cout << "\n--- Attempt to execute unsigned forms ---" << std::endl;
        // alice.executeForm(shrub);
        // alice.executeForm(robot);
        // alice.executeForm(pardon);

        // std::cout << "\n--- Signing forms ---" << std::endl;
        
        try {
             shrub.beSigned(alice);
         } 
         catch (std::exception &e)
         {
             std::cout << e.what() << std::endl;
            }


    //     try { 
    //         robot.beSigned(charlie); 
    //     }
    //      catch (std::exception &e) 
    //      { 
    //         std::cout << e.what() << std::endl; 
    //     }


    //     try 
    //     { 
    //         pardon.beSigned(alice); 
    //     }
    //      catch (std::exception &e) 
    //      {
    //          std::cout << e.what() << std::endl;
    //          }

        // std::cout << "\n--- Execution with insufficient grade ---" << std::endl;
        // bob.executeForm(shrub); 
    //     charlie.executeForm(robot); 
    //     bob.executeForm(pardon); 

    //     alice.executeForm(robot);
    //     alice.executeForm(pardon);
        alice.executeForm(shrub);


    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
        return 0;
}