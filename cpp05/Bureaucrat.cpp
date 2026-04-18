#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n)
{
}

Bureaucrat::~Bureaucrat(){

};

int Bureaucrat::getGrade() const 
{
    return this->grade;
};


const std::string& Bureaucrat::getName() const 
{
    return this->name;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) name()
{
     this->name = other.name;
    std::cout << "Bureacrat  copy constructor called" << std::endl;
}
