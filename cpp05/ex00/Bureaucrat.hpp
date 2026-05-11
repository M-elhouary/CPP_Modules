#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {

    private:
        std::string  const name;
        int grade;
    public:
        Bureaucrat();
        std::string const &getName() const;
        int getGrade() const;
        Bureaucrat(const std::string& n, int g);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        void incrementGrade();
        void decrementGrade();
        ~Bureaucrat();

        class GradeTooHighException  : public std::exception {
            public :
                virtual const char* what() const throw();
        };

        // what is this
        // how it works ?
        // why we need it ?
        // why not implement it in the same class ?
        // this is a nested class that inherits from std::exception. It is used to define a custom exception that can be thrown when the grade of a bureaucrat is too low.
        // why decalre virtual const char* what() const throw() ?
        class GradeTooLowException : public std::exception {
            public :
                virtual const char* what() const throw();
        };

};
// what is this 
// how it works ?
// why we need it ?
// why declare it outside the class ?
std::ostream& operator<<(std::ostream& o, const Bureaucrat& i); 


#endif
