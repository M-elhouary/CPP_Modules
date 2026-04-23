#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

    public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    void execute(Bureaucrat const & executor) const;

};

#endif