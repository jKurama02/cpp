#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("def_name"), _signed(false), _gradeToSign(75), _gradeToExecute(75){};

Form::Form(std::string const name, bool _signed, int const _gradeToSign, int const _gradeToExecute) : _name(name), _signed(_signed), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if(_gradeToSign < 1)
		throw GradeTooHighException();
	else if(_gradeToSign > 150)
		throw GradeTooLowerException();
	if(_gradeToExecute < 1)
		throw GradeTooHighException();
	else if(_gradeToExecute > 150)
		throw GradeTooLowerException();
	else
		std::cout << "Form " << getName() << " created \n";
};

Form::Form(const Form& other)  : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){};

Form::~Form(){};

std::string Form::getName()
{
	return(this->_name);
}

bool Form::getSigned()
{
	return((int)this->_signed);
}
int Form::getGradeToSign()
{
	return(this->_gradeToSign);
}
int Form::getGradeToExecute()
{
	return(this->_gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
	out << form.getName()<< " GradeToSign " << form.getGradeToSign() << ", GradeToExecute " << form.getGradeToExecute()<<std::endl;
	return out;
}

// Implementazione dei metodi di Form
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw std::runtime_error("Grade too low to sign the form.");
	}
	this->_signed = true;
}

