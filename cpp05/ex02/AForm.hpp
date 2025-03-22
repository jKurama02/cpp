#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:
		AForm();
		AForm(std::string const name, bool _signed, int const _gradeToSign, int const _gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return(" the grade is too high\n");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return(" the grade is too low\n");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return("Form is not signed\n");
				}
		};

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
