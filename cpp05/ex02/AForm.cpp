#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeTosign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeTosign), gradeToExecute(gradeToExecute)
{
    if (gradeTosign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeTosign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned; // name, gradeToSign, and gradeToExecute are const
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
    os << "Form Name: " << aform.getName() << ", Signed: " << (aform.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << aform.getGradeToSign() << ", Grade to Execute: " << aform.getGradeToExecute();
    return os;
}
