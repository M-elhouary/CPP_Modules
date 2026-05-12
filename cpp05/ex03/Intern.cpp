#include "Intern.hpp"

#include <iostream>


Intern::Intern() {} // Default constructor
Intern::Intern(const Intern&) {} // Copy constructor
Intern& Intern::operator=(const Intern&) { return *this; } // Assignment operator
Intern::~Intern() {} // Destructor

AForm* Intern::createShrubbery(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    
    typedef AForm* (Intern::*FormCreator)(const std::string&) const;

    struct FormPair {
        const char* name;
        FormCreator creator;
    };

    static const FormPair forms[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPardon}
    };

    for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(forms[i].creator))(target);
        }
    }
    std::cout << "Intern cannot create form: " << formName << std::endl;
    return 0;
}
