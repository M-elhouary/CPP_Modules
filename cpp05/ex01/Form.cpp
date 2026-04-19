#include "Form.hpp"


// Error text used when grade goes above the highest allowed rank (1).
const char* Form::GradeTooHighException::what() const throw()
{
    return "too high";
};

// Error text used when grade goes below the lowest allowed rank (150).
const char* Form::GradeTooLowException::what() const throw()
{
    return "too low";
};


Form::Form(const std::string& n, const int gs, const int ge) : name(n), gradeToSign(gs), gradeToExec(ge)
{
    if(gs < 1)
        throw GradeTooHighException();
    else if(gs > 150)
        throw GradeTooLowException();

    if(ge < 1)
        throw GradeTooHighException();
    else if(ge > 150)
        throw GradeTooLowException();
};
Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExec(150) {};
Form::~Form(){};

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "Form copy constructor called" << std::endl;
}


Form &Form::operator=(Form const &other)
{
    std::cout << " Form copy assignment called " << std::endl;
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}


std::string const &Form::getName() const
{
    return this->name;
};

int Form::getGradeToExec() const
 {
    return this->gradeToExec;

};

int Form::getGradeToSign() const
{
    return this->gradeToSign;
};


bool Form::getIsSigned() const
{
    return this->isSigned;
};

void Form::beSigned(const class Bureaucrat &b)
{
    if(b.getGrade() > gradeToSign)
        throw GradeTooLowException();   
    else
        this->isSigned = true;
};

std::ostream& operator<<(std::ostream& o, const Form& i)
{
    if(i.getIsSigned())
        o << i.getName() << ", form is signed, grade to sign " << i.getGradeToSign() << ", grade to execute " << i.getGradeToExec() << ".";
    else
        o << i.getName() << ", form is not signed, grade to sign " << i.getGradeToSign() << ", grade to execute " << i.getGradeToExec() << ".";
    return o;
}