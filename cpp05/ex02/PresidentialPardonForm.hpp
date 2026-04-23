#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    void execute(Bureaucrat const & executor) const;
    

};

#endif
