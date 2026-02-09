#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        // target is const, so we don't assign it here
    }
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile)
    {
        std::cerr << "Error: Could not create file " << target + "_shrubbery" << std::endl;
        return;
    }

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

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const
{
    AForm::execute(executor); // This will check if the form is signed and if the executor has the right grade
    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile)
    {
        std::cerr << "Error: Could not create file " << target + "_shrubbery" << std::endl;
        return;
    }

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
