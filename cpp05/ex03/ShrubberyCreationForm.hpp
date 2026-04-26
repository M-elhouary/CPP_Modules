 
#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	void execute(Bureaucrat const & executor) const;

};

#endif
