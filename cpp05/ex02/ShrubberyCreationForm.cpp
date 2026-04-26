
#include "ShrubberyCreationForm.hpp"
#include <fstream>



ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "default target") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other) {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::ofstream outFile((this->getTarget() + "_shrubbery").c_str());
    if (outFile.is_open())
    {
        outFile << "       _-_" << std::endl;
        outFile << "    /~~   ~~\\" << std::endl;
        outFile << " /~~         ~~\\" << std::endl;
        outFile << "{               }" << std::endl;
        outFile << " \\  _-     -_  /" << std::endl;
        outFile << "   ~  \\\\ //  ~" << std::endl;
        outFile << "_- -   | | _- _" << std::endl;
        outFile << "  _ -  | |   -_" << std::endl;
        outFile << "      // \\\\" << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Error: Could not create file." << std::endl;
    }
}

