
#include "Intern.hpp"
#include "../ex02/ShrubberyCreationForm.hpp"
#include "../ex02/RobotomyRequestForm.hpp"
#include "../ex02/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    struct FormPair {
        const char* name;
        AForm* (*creator)(const std::string&);
    };
    static const FormPair forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
    };
    for (size_t i = 0; i < sizeof(forms)/sizeof(forms[0]); ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }
    std::cout << "Intern cannot create form: " << formName << std::endl;
    return 0;
}
