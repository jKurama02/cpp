#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		std::string _name;
		int         _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void increment();
		void decrement();

		std::string getName() const;
		int getGrade() const;

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

		void signForm(AForm &form);
		void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
