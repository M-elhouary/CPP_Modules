 
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45, "default target") {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {};

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45, target) {};

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	AForm::operator=(other);
	return *this;
};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	std::cout << "Bzzzzzz... drilling noises...\n";
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->getTarget() << "!" << std::endl;
}
