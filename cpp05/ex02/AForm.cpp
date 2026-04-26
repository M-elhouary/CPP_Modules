#include "AForm.hpp"
#include "Bureaucrat.hpp"


// Error text used when grade goes above the highest allowed rank (1).

const char* AForm::GradeTooHighException::what() const throw() {
    return "too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "form not signed";
}

AForm::AForm(const std::string& n, const int gs, const int ge, const std::string& t) : name(n), gradeToSign(gs), gradeToExec(ge), target(t)
{
    if(gs < 1)
        throw GradeTooHighException();
    else if(gs > 150)
        throw GradeTooLowException();

    if(ge < 1)
        throw GradeTooHighException();
    else if(ge > 150)
        throw GradeTooLowException();
    isSigned = false;
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExec(150), target("default target") {}
AForm::~AForm(){};

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec), target(other.target)
{
    std::cout << "AForm copy constructor called" << std::endl;
}


AForm &AForm::operator=(AForm const &other)
{
    std::cout << " AForm copy assignment called " << std::endl;
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string const &AForm::getTarget() const
{
    return target;
}

void AForm::checkExecution(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExec)
        throw GradeTooLowException();
}

std::string const &AForm::getName() const
{
    return this->name;
};

int AForm::getGradeToExec() const
 {
    return this->gradeToExec;

};

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
};


bool AForm::getIsSigned() const
{
    return this->isSigned;
};

void AForm::beSigned(const class Bureaucrat &b)
{
    if(b.getGrade() > gradeToSign)
        throw GradeTooLowException();   
    else
        this->isSigned = true;
};

std::ostream& operator<<(std::ostream& o, const AForm& i)
{
    if(i.getIsSigned())
        o << i.getName() << ", form is signed, grade to sign " << i.getGradeToSign() << ", grade to execute " << i.getGradeToExec() << ".";
    else
        o << i.getName() << ", form is not signed, grade to sign " << i.getGradeToSign() << ", grade to execute " << i.getGradeToExec() << ".";
    return o;
}