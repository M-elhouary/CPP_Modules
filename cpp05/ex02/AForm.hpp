#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>


class Bureaucrat;

class AForm {

    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:

    // canonical form
         AForm(const std::string name, const int gradeTosign, const int gradeToExecute);
         AForm(const AForm &other);
         AForm &operator=(const AForm &other);
        ~AForm();
        
    // getter func
        std::string  getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

    // member func
        void        beSigned(const Bureaucrat &bureaucrat);
        void        execute(const Bureaucrat &Executor) const;


    // exception classes
        class GradeTooHighException  : public std::exception
        {
                public:
                    virtual const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                    virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        protected:
            virtual void executeAction() const = 0; // pure virtual function to be implemented by derived classes
    
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);

#endif 