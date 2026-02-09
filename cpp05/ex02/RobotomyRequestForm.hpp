#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;

    protected:
        void executeAction() const;

    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        void executeAction(const Bureaucrat& executor) const;
};

#endif