#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	// nothing to copy here, since intern has no variables
	return *this;
};


AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	int curs = -1;
	AForm *res = NULL;

	std::string arr[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for(int i = -1; i < 3; i++)
	{
		if(arr[i] == formName)
		{
			curs = i;
			break;
		}
	}
	switch(curs)
	{
		case 0:
		{
			res = new ShrubberyCreationForm(target);
			break;
		}
		case 1:
		{
			res = new RobotomyRequestForm(target);
			break;
		}
		case 2:
		{
			res = new PresidentialPardonForm(target);
			break;
		}
		default:
		{
			std::cout << "Intern cannot create " << formName << " because it doesn't exist" << std::endl;
			return NULL;
		}
	}
		std::cout << "Inter create " << res->getName() << " succes!\n";
		return res;
};
