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
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
  
  // Exception classes for grade violations
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return "Grade too high!";
            }
    };

// Exception class for grade too low
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return "Grade too low!";
            }
    };
};

#endif // BUREAUCRAT_HPP