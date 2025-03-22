#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", false, 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (outfile.is_open())
	{
		outfile << "      /\\\n";
		outfile << "     /\\*\\\n";
		outfile << "    /\\O\\*\\\n";
		outfile << "   /*/\\/\\/\\\n";
		outfile << "  /\\O\\/\\*\\/\\\n";
		outfile << " /\\*\\/\\*\\/\\/\\\n";
		outfile << "/\\O\\/\\/*/\\/O/\\\n";
		outfile << "      ||\n";
		outfile << "      ||\n";
		outfile << "      ||\n";
		outfile.close();
		std::cout << "ASCII tree created in " << filename << std::endl;
	}
	else
	{
		std::cout << "Could not create file " << filename << std::endl;
	}
}
