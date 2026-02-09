#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
 : AForm("Presidential Pardon Form", 25, 5), target(target)
{
} 

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
 : AForm(other), target(other.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        // target is const, so we don't assign it here
    }
    return *this;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}



void PresidentialPardonForm::executeAction(const Bureaucrat& executor) const
{
    AForm::execute(executor); // This will check if the form is signed and if the executor has the right grade
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

