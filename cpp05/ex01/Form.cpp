#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &n, int s, int e)
    : name(n), isSigned(false), gradeToSign(s), gradeToExecute(e)
{
    if (s < 1 || e < 1)
        throw GradeTooHighException();
    if (s > 150 || e > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned; // only non-const member can change
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int  Form::getGradeToSign() const { return gradeToSign; }
int  Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    // Remember: higher rank = smaller number
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName()
       << " | signed: " << (form.getIsSigned() ? "yes" : "no")
       << " | gradeToSign: " << form.getGradeToSign()
       << " | gradeToExecute: " << form.getGradeToExecute();
    return os;
}
