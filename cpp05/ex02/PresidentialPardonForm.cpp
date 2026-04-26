#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5, "default target") {};

PresidentialPardonForm::~PresidentialPardonForm() {};


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {};


PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5, target) {};


PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    AForm::operator=(other);
    return *this;
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << this->getName() << ": " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};

