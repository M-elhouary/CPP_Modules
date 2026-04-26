#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Form
{

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExec;

public:
    Form(Form const &other);
    Form(const std::string &name, const int gs, const int ge);
    Form();
    Form &operator=(Form const &other);
    ~Form();


    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    void beSigned(const class Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &o, const Form &i);

#endif