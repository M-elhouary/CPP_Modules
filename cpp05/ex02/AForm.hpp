#ifndef AFORM_HPP

#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"



class AForm {

    private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExec;

    public: 
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm();

        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(Bureaucrat const &b);
    virtual int execute(Bureaucrat const & executor) const = 0 ;
    

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};


#endif