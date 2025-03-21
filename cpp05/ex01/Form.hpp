#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		Form();
		Form(std::string const name, bool _signed, int const _gradeToSign, int const _gradeToExecute);
		Form(const Form& other);
		// Form& operator=(const Form& other);
		~Form();
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return(" the grade is too high\n");
				}
		};
		class GradeTooLowerException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return(" the grade is too lower\n");
				}
		};

		std::string getName();
		bool getSigned();
		int getGradeToSign();
		int getGradeToExecute();

		void beSigned(Bureaucrat &bureaucrat);

};
std::ostream& operator<<(std::ostream& out, Form& form);


#endif
