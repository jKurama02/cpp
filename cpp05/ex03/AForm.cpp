#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("def_name"), _signed(false), _gradeToSign(75), _gradeToExecute(75){};

AForm::AForm(std::string const name, bool _signed, int const _gradeToSign, int const _gradeToExecute)
	: _name(name), _signed(_signed), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if(_gradeToSign < 1)
		throw GradeTooHighException();
	else if(_gradeToSign > 150)
		throw GradeTooLowException();
	if(_gradeToExecute < 1)
		throw GradeTooHighException();
	else if(_gradeToExecute > 150)
		throw GradeTooLowException();
	else
		std::cout << "Form " << getName() << " created \n";
};

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){};

AForm::~AForm(){};

std::string AForm::getName() const
{
	return(this->_name);
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeToSign() const
{
	return(this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName()<< " GradeToSign " << form.getGradeToSign()
		<< ", GradeToExecute " << form.getGradeToExecute()
		<< ", Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
	return out;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}
