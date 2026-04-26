 
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
		const std::string target;

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
