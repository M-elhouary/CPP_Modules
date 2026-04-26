 
#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

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
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		void executeForm(AForm const & form) const;

};
std::ostream& operator<<(std::ostream& o, const Bureaucrat& i);

#endif
