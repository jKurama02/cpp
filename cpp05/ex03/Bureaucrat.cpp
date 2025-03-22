#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

Bureaucrat::Bureaucrat(){};

Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if(grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else
	{
	this->_name = name;
	this->_grade = grade;

	std::cout << "Bureaucrat " << Bureaucrat::getName() << ", grade: " << Bureaucrat::getGrade() << " created\n";
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	this->_name = other._name;
	this->_grade = other._grade;

	std::cout << "[copy_constructor]\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "[assignment opearator]\n";
	if(this == &other)
	{
		return(*this);
	}
	this->_name = other._name;
	this->_grade = other._grade;
	return(*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

void Bureaucrat::increment()
{
	if(this->_grade == 1)
		std::cout << "Grade too high \n";
	else
	{
		std::cout << this->getName() << " was incremented from: " << this->getGrade();
		this->_grade--;
		std::cout << " to " << this->getGrade() << std::endl;
	}
}

void Bureaucrat::decrement()
{
	if(this->_grade == 150)
		std::cout << "Grade too low \n";
	else
	{
		std::cout << this->getName() << " was decremented from: " << this->getGrade();
		this->_grade++;
		std::cout << " to " << this->getGrade() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << this->getName() << " couldn't execute " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}
