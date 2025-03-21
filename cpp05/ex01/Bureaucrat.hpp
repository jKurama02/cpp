#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"
class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void increment();
		void decrement();

		std::string getName();
		int getGrade();

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

		void signForm(Form &form);
};
std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif
