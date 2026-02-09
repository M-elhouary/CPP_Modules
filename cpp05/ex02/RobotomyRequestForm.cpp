#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
 : AForm("Robotomy Request Form", 72, 45), target(target)
{
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
 : AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        // target is const, so we don't assign it here
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Drilling noises... " << target << " has been robotomized successfully 50% of the time." << std::endl;
}

void RobotomyRequestForm::executeAction(const Bureaucrat& executor) const
{
    AForm::execute(executor); // This will check if the form is signed and if the executor has the right grade
    std::cout << "Drilling noises... " << target << " has been robotomized successfully 50% of the time." << std::endl;
}

