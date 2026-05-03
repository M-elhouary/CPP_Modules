#ifndef AFORM_HPP

#define AFORM_HPP

#include <iostream>
#include <string>


// forward declaration to avoid circular dependency between AForm and Bureaucrat
class Bureaucrat;


class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
        const std::string target; // why not put target in the derived classes? because we want to have a common interface for all forms, and target is a common attribute that all forms will use. By having it in the base class, we can ensure that all forms have a target and can access it through the same interface. This also allows us to implement common functionality related to the target in the base class, reducing code duplication in the derived classes.
            
    protected:
        void checkExecution(Bureaucrat const & executor) const;

    public:
        AForm(const std::string& name, int signGrade, int execGrade, const std::string& target);
        AForm();
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm();

        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        std::string const &getTarget() const;

        void beSigned(Bureaucrat const &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif