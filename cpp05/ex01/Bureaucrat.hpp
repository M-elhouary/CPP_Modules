#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat(const std::string &name, int grade); // Constructor with name and grade
    Bureaucrat(const Bureaucrat &other);            // Copy constructor
    Bureaucrat &operator=(const Bureaucrat &other); // Assignment operator
    ~Bureaucrat();                                  // Destructor

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);

    // Exception classes for grade violations
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // Exception class for grade too low
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP