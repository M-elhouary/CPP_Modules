#include "Bureaucrat.hpp"



// Error text used when grade goes above the highest allowed rank (1).
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "too high";
};

// Error text used when grade goes below the lowest allowed rank (150).
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "too low";
};

// Build a Bureaucrat and enforce the valid grade range [1, 150].
Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g)
{
    if(g < 1)
        throw GradeTooHighException();
    else if (g > 150)
        throw GradeTooLowException();
};

// Default Bureaucrat starts at the lowest valid rank.
Bureaucrat::Bureaucrat() : name("default"), grade(150) {};

Bureaucrat::~Bureaucrat()
{};

// Read-only accessor for the current grade.
int Bureaucrat::getGrade() const 
{
    return this->grade;
};


// Read-only accessor for the immutable name.
const std::string& Bureaucrat::getName() const 
{
    return this->name;
};

// Copy constructor duplicates name and grade.
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureacrat  copy constructor called" << std::endl;
}

// Assignment updates only grade because name is const.
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureacrat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
};

// Promote: better rank means a smaller numeric grade.
void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
    throw GradeTooHighException();
    else
        this->grade--;
};

// Demote: worse rank means a larger numeric grade.
void Bureaucrat::decrementGrade()
{
    if(this->grade >= 150)
        throw GradeTooLowException();
    else
        this->grade++;
};


// Print Bureaucrat in the required subject format.
std::ostream& operator<<(std::ostream& o, const Bureaucrat& i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return o;

}