 
#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "too high";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "too low";
};

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g)
{
	if(g < 1)
		throw GradeTooHighException();
	else if (g > 150)
		throw GradeTooLowException();
};

Bureaucrat::Bureaucrat() : name("default"), grade(150) {};

Bureaucrat::~Bureaucrat()
{};

int Bureaucrat::getGrade() const 
{
	return this->grade;
};

const std::string& Bureaucrat::getName() const 
{
	return this->name;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureacrat  copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Bureacrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
};

void Bureaucrat::incrementGrade()
{
	if (this->grade < 1)
	throw GradeTooHighException();
	else
		this->grade--;
};

void Bureaucrat::decrementGrade()
{
	if(this->grade > 150)
		throw GradeTooLowException();
	else
		this->grade++;
};

void Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn’t execute " << form.getName() << ": " << e.what() << std::endl;
	}
}
